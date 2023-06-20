import time

def constructor(number):
	return number + sum([int(i) for i in str(number)])

def main():
	# time check start
	start = time.time()
	constructors = [constructor(i) for i in range(1, 10000)]
	numbers = [i for i in range(1, 10000)]
	numbers = [i for i in numbers if i not in constructors]
	for i in numbers:
		print(i)
	# time check end
	end = time.time()
	print("time : ", end - start)

def main2():
	# time check start
	start = time.time()
	constructors = [constructor(i) for i in range(1, 10000)]
	for i in range(1, 100):
		if i not in constructors:
			print(i)
	# time check end
	end = time.time()
	print("time : ", end - start)

main2()
