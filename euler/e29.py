def solve():
    return len(dict([(x, '') for x in [a ** b for a in range(2, 101) for b in range(2, 101)]]).keys())

if __name__ == '__main__':
    print solve()
