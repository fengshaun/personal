import math

def divisors(n):
    div = [0]
    for i in range(1, n / 2 + 1):
        if not n % i:
            div.append(i)
    return div

def is_amicable(n):
    n2 = reduce((lambda x, y: x + y), divisors(n))
    if reduce((lambda x, y: x + y), divisors(n2)) == n:
        if n != n2:
            return True
        else:
            return False
    else:
        return False

def solve():
    sum = 0
    for i in range(10000):
        if is_amicable(i):
            sum += i

    return sum

if __name__ == '__main__':
    print solve()
