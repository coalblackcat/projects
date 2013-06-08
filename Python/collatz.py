import sys

def collatz(start):
	if start == 1:
		return 0
	elif (start % 2 == 0):
		collatz(start / 2)
	elif (start % 2 != 0):
		collatz((start * 3) + 1)

for i in range(1,1000000):
	collatz(i)
	print "Proven for " + str(i) + "\n"
