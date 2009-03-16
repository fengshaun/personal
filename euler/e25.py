def xfib():
    a = 1
    b = 1
    yield a
    yield b
    while 1:
        c = a + b
        a = b
        b = c
        yield c

def solve():
    count = 1
    for i in xfib():
        if len(str(i)) >= 1000:
            return count
        count += 1

if __name__ == '__main__':
    print solve()
