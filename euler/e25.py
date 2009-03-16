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

if __name__ == '__main__':
    count = 1
    for i in xfib():
        if len(str(i)) >= 1000:
            print '%s\n%s' % (i, count)
            break
        count += 1
