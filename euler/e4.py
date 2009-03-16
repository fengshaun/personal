def solve():
    largest = 0
    for i in range(999, 700, -1):
        for j in range(i - 1, 700, -1):
            s = str(i * j)
            if s[0] == s[-1] and s[1] == s[-2] and s[2] == s[-3]:
                if int(s) > largest:
                    largest = int(s)
    return largest

if __name__ == '__main__':
    print solve()
