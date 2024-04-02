#include <iostream >
#include <vector >
#include <queue >
#include <algorithm >
using namespace std;
const int INF = 1e9;

struct Edge
{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;
int N; // Number of nodes
int K; // Desired flow
int source, sink;
void add_edge(int from, int to, int cap, int cst)
{
    adj[from].push_back(to);
    adj[to].push_back(from);
    capacity[from][to] = cap;
    capacity[to][from] = 0;
    cost[from][to] = cst;
    cost[to][from] = -cst;
}
void init_code()
{
    N = 15;
    K = 10;
    source = 1;
    sink = 15;
    adj.assign(N + 1, vector<int>());
    cost.assign(N + 1, vector<int>(N + 1));
    capacity.assign(N + 1, vector<int>(N + 1));
    vector<Edge> edges = {
        {1, 2, 10, 2},
        {1, 3, 10, 4},
        {2, 3, 10, 1},
        {2, 4, 10, 3},
        {3, 5, 10, 2},
        {4, 6, 10, 5},
        {5, 7, 10, 2},
        {6, 8, 10, 1},
        {7, 8, 10, 1},
        {8, 9, 10, 3},
        {9, 10, 10, 4},
        {10, 11, 10, 2},
        {11, 12, 10, 1},
        {12, 13, 10, 2},
        {13, 14, 10, 3},
        {14, 15, 10, 4},
        {2, 6, 10, 2},
        {6, 10, 10, 2},
        {10, 14, 10, 2},
        {1, 5, 10, 1},
        {5, 9, 10, 1},
        {9, 13, 10, 1},
        {1, 4, 10, 3},
        {4, 7, 10, 3},
        {7, 11, 10, 3},
        {11, 15, 10, 3}};
    for (const Edge &e : edges)
        add_edge(e.from, e.to, e.capacity, e.cost);
}

void shortest_paths(int n, int v0, vector<int> &d, vector<int> &p)
{
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u])
        {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v])
            {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v])
                {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
int min_cost_flow(int N, int K, int s, int t)
{
    int flow = 0;
    int flow_cost = 0;
    vector<int> d, p;
    while (flow < K)
    {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;
        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s)
        {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        flow_cost += f * d[t];
        cur = t;
        while (cur != s)
        {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }
    if (flow < K)
        return -1;
    else
        return flow_cost;
}
int main()
{
    init_code();
    int min_cost = min_cost_flow(N + 1, K, source, sink);
    if (min_cost == -1)
        cout << "It was not possible to find the desired flow." << endl;
    else
        cout << "The minimum cost to achieve the flow " << K << " is " << min_cost << "." << endl;
    return 0;
}
