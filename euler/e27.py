from pylib import prime

def primes_produced(a, b):
    # in the form n^2 + an + b
    produced = 0
    n = 0

    while 1:
        
        if prime.is_prime(n ** 2 + a * n + b):
            produced += 1
        else:
            break
        n += 1

    return produced

def solve():
    a = 0
    b = 0
    n = 0

    for x in xrange(-1000, 1001):
        for i in prime.primes_max(1000):
            for y in [i, -i]:
                num = primes_produced(x, y)
                if num > n:
                    n = num
                    a = x
                    b = y

    return a * b

if __name__ == '__main__':
    print solve()
