l = [                                       [75],
                                          [95, 64],
                                        [17, 47, 82],
                                      [18, 35, 87, 10],
                                    [20,  4, 82, 47, 65],
                                  [19,  1, 23, 75,  3, 34],
                                [88,  2, 77, 73,  7, 63, 67],
                              [99, 65,  4, 28,  6, 16, 70, 92],
                            [41, 41, 26, 56, 83, 40, 80, 70, 33],
                          [41, 48, 72, 33, 47, 32, 37, 16, 94, 29],
                        [53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14],
                      [70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57],
                    [91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48],
                  [63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31],
                [ 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23]]

def update_element(row, col):
    elem1 = 0
    elem2 = 0

    try:
        elem1 = l[row - 1][col - 1]
    except IndexError:
        # it is the beginning element
        l[row][col] += l[row - 1][col]
        return

    try:
        elem2 = l[row - 1][col]
    except IndexError:
        # it is the last element
        l[row][col] += l[row - 1][col - 1]
        return

    if elem1 > elem2:
        l[row][col] += elem1
    else:
        l[row][col] += elem2

def update_row(row):
    for col in range(len(l[row])):
        update_element(row, col)

def solve():
    for i in range(1, len(l)):
        update_row(i)

    return max(l[-1])

if __name__ == '__main__':
    print solve()
