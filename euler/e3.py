import math

def solve():
    n = 600851475143
    last_factor = 1

    if not n % 2:
        last_factor = 2
        while not n % 2:
            n = n / 2
            
    factor = 3
    max_factor = math.sqrt(n)

    while n > 1 and factor <= max_factor:
        if not n % factor:
            last_factor = factor
            n = n / factor
            while not n % factor:
                n = n / factor
            max_factor = math.sqrt(n)
        factor += 2
		
    if n == 1:
        return last_factor
    else:
        return n

if __name__ == '__main__':
    print solve()
