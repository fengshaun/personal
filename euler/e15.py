# use combinatorics:
# permutation with repetition

from pylib import mathfn

def solve():
    return mathfn.fac(40) / (mathfn.fac(20) * mathfn.fac(20))

if __name__ == '__main__':
    print solve()
 
