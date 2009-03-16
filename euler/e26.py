from pylib import prime

'''
the period of a number n's reciprocal is the smallest k
such that n divides 10**k - 1 '(10**k - 1) % n'.

it should be prime too!
'''

if __name__ == '__main__':
    max_p = 0
    num = 0
    for n in prime.primes_max(1000):
        for p in range(1, n + 1):
            if (10 ** p - 1) % n == 0:
                if p > max_p:
                    max_p = p
                    num = n
                    print p
                break

    print num

