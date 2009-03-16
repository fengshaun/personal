from pylib.prime import primes_max 
import time

start = time.time()
sum = 0
for i in primes_max(2000000):
    sum += i
elapsed = time.time() - start
print sum, '\ntook:', elapsed
