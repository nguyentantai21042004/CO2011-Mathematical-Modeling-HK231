import numpy as np
from gamspy import Container
from gamspy import Equation
from gamspy import Model
from gamspy import Variable
from gamspy import Set
from gamspy import Parameter
from gamspy import Sum
from gamspy import Sense
from gamspy import Problem
from gamspy import *
# so luong san pham
n = 8
# so luowng nguyen lieu can dat truoc khi san xuat
m = 5
# so kich ban S = 2
# [ Rest of the code ...]
SLP . solve ()
print ("so␣ nguyen ␣ lieu ␣moi␣ loai ␣x:\n",x . records )
print ("\n")
print ("so␣ nguyen ␣ lieu ␣con␣lai ␣␣y1␣( kich ␣ban␣1) :\n", y1 . records
)
print ("\n")
print ("so␣ nguyen ␣ lieu ␣con␣lai ␣y2␣( kich ␣ban␣2) :\n", y2 . records )
print ("\n")
print ("so␣ luong ␣moi␣ loai ␣san ␣ pham ␣z1␣( kich ␣ban␣1) :\n", z1 .
records )
print ("\n")
print ("so␣ luong ␣moi␣ loai ␣san ␣ pham ␣z2␣( kich ␣ban␣2) :\n", z2 .
records )
print ("\n")
print ("Gia␣ tri␣ham␣muc␣ tieu :␣", SLP . objective_value )
