import time

def number_of_steps(num):
    counter = 0
    while num != 1:
        if num % 2 == 0:
            num /= 2
            counter += 1
        else:
            num = 3 * num + 1
            counter += 1

    return counter

if __name__ == '__main__':
    start_time = time.time()
    longest_chain = 0
    starting_number = 0
    chain = 0
    for i in range(999999, 1, -1):
        # with print, 75s.  Without print, 55s.
        #print 'inspecting', i
        chain = number_of_steps(i)
        if chain > longest_chain:
            longest_chain = chain
            starting_number = i

    elapsed = time.time() - start_time
    print starting_number, longest_chain
    print 'took', elapsed, 's'
