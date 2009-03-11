import time

def score(name):
    sum = 0
    for i in name:
        sum += ord(i) - 64
    return sum

if __name__ == '__main__':
    start_time = time.time()
    f = open('names.txt', 'r')
    data = f.readlines()[0]
    data = data.replace('"', '').split(',')

    sum = 0
    for i in enumerate(sorted(data)):
        s = score(i[1]) * (i[0] + 1)
        print i, s,
        sum += s

    elapsed = time.time() - start_time
    print sum, '\ntook:', elapsed
