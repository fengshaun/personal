def solve():
    return reduce((lambda x, y: int(x) + int(y)), str(2 ** 1000))

if __name__ == '__main__':
    print solve()
