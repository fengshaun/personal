from pylib import mathfn

def solve():
    sum = 0
    for i in str(mathfn.fac(100)):
        sum += int(i)

    return sum

if __name__ == '__main__':
    print solve()
