from pylib import mathfn

sum = 0
for i in str(mathfn.fac(100)):
    sum += int(i)

print sum
