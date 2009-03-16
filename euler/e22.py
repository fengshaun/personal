def score(name):
    sum = 0
    for i in name:
        sum += ord(i) - 64
    return sum

def solve():
    f = open('names.txt', 'r')
    data = f.readlines()[0]
    data = data.replace('"', '').split(',')

    sum = 0
    for i in enumerate(sorted(data)):
        s = score(i[1]) * (i[0] + 1)
        print i, s,
        sum += s

    return sum

if __name__ == '__main__':
    print solve()
