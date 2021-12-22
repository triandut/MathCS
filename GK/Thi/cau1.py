# Tính các ước số của n
import math as mt
from math import *

# Function to print the divisors


def printDivisors(n):

    i = 1
    while (i * i < n):
        if (n % i == 0):
            print(i, end=" ")

        i += 1

    for i in range(int(sqrt(n)), 0, -1):
        if (n % i == 0):
            print(n // i, end=" ")


# Driver Code
print("Kết quả: ")

printDivisors(10000)


# Tính tổng các ước số


def sumDivisorsOfDivisors(n):
    sum = 0
    for i in range(1, n + 1):
        if(n % i == 0):
            sum += i
    return sum


# Driver Code
n = 10000
print("Sum = ", sumDivisorsOfDivisors(n))

# Tính tích các ước số


def multiDivisorsOfDivisors(n):
    sum = 1
    for i in range(1, n + 1):
        if(n % i == 0):
            sum *= i
    return sum


# Driver Code
n = 10000
print("Multi", multiDivisorsOfDivisors(n))
