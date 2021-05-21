# Write a function that takes in targetSum and an array of numbers.

# Return a boolean indicating whether or not it is possible to generate the 
# targetsum using numbers from the array

# numbers can be used in infinitely

def canSum(targetsum, numbers, memo={}):
	# if targetsum in memo:
	# 	return memo[targetsum];
	if (targetsum==0):
		return True;
	if (targetsum<0):
		return False
	for num in numbers:
		rem=targetsum-num;
		if canSum(rem,numbers,memo)==True:
			# memo[targetsum]=True
			return True;
	# memo[targetsum]=False
	return False

print(canSum(7,[2,3])) # true 
print(canSum(7,[5,3,4,7])) # true
print(canSum(7,[2,4])) # false
print(canSum(8,[2,3,5])) # true
print(canSum(300,[7,14])) # false







