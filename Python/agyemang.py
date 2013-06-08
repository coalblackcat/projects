import math
import sys

# Find a number when added to its cube roots yields 6

a = float(sys.argv[1])

print(math.pow(a,1/3.0) + a)
