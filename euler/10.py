from pylib.prime import primes_max 

sum = 0
for i in primes_max(2000000):
    sum += i
print sum
