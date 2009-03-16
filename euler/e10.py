from pylib.prime import primes_max 

def solve():
    sum = 0
    for i in primes_max(2000000):
        sum += i
    return sum

if __name__ = '__main__':
    print solve()
