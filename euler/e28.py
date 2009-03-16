import math

def solve():
    num = 1
    counter = 0
    sum = 0
    diff = 2

    while num <= 1002001:
        sum += num
        num += diff
        counter += 1
        if counter >= 4:
            diff += 2
            counter = 0
    
    return sum

if __name__ == '__main__':
    print solve()
