from pylib import prime

def solve():
    return list(prime.primes_count(10001))[-1]

if __name__ == '__main__':
    print solve()
