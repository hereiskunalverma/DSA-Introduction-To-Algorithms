# Write a function that takes in targetSum and an array of numbers.

# Return an array containing any combination of elements that add up to target sum

# numbers can be used in infinitely

def howSum(target, numbers, memo={}):
	if (target in memo):
		memo[target];
	if(target==0):
		return [];
	if(target<0):
		return None;
	for num in numbers:
		rem=target-num;
		remRes=howSum(rem,numbers, memo);
		if(remRes!=None):
			memo[target] = remRes+[target];
			return memo[target];
	memo[target]=None;
	return None


print(howSum(7,[2,3])) # [3 2 2]
print(howSum(7,[5,3,4,7])) # [4 3]
print(howSum(7,[2,4])) # null
print(howSum(8,[2,3,5])) # [2 2 2 2]
print(howSum(300,[7,14])) # null