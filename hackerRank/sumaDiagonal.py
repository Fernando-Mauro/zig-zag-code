#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'diagonalDifference' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def diagonalDifference(arr):
   suma = 0
   for i in range(0,len(arr)):
      # print(arr[i][i], end=' ')
      suma += arr[i][i]
   secondSuma = 0
   j = 0
   for i in range(len(arr) - 1, -1, -1):
      secondSuma += arr[i][j]
      j+=1
   return abs(suma - secondSuma)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w') 

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
