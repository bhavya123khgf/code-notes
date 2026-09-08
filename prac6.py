def greet(name):
    return print(f"hello {name}")
greet("bhavya")

import random
print(random.randint(1,10))

import datetime
print(datetime.datetime.now())

import math
print(math.sqrt(256))
print(math.factorial(5))
print(math.pi)

def power(base,exponent=2):
    return print(base ** exponent)
power(5)

def total(*numbers):
    return print(sum(numbers))
total(10,20,30)

gen = (x**2 for x in range(3))
for val in gen:
    print(val)

def factorial(n):
    if n == 1:
        return 1
    return n * factorial(n-1)

print(factorial(5))

x = 10
def change():
   x = 20
   print("Inside:", x)
change()
print("Outside:", x)

def modify(lst):
    lst.append(99)
nums=[1,2]
modify(nums)
print(nums)

square=lambda x:x**2
print(square(5))

nums=[1,2,3,4]
square=list(map(lambda x:x**2,nums))
print(square)

from functools import reduce
nums=[1,2,3,4]
product = reduce(lambda x,y: x*y,nums)
print(product)

nums=[1,2,3,4,5,6]
evens = list(filter(lambda x: x%2 == 0,nums))
print(evens)