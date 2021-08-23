# Return from a function that takes a targetSum and array, an array containing the shortest
# combination of numbers that add up to exactly the targetSum

def bestSum(targetSum, numbers, memo={}):
	if targetSum in memo:
		memo[targetSum];
	if (targetSum==0):
		return [];
	if (targetSum<0):
		return None;
	shortest_best = None
	for num in numbers:
		rem=targetSum-num;
		remComb = bestSum(rem,numbers, memo)
		if (remComb!=None):
			combination=remComb+[num];
			if (shortest_best==None or len(combination) < len(shortest_best)):
				shortest_best=combination
	memo[targetSum]=shortest_best;
	return shortest_best;

print(bestSum(7,[5,3,4,7])) # [7]
print(bestSum(8,[2,3,5])) # [3, 5]
print(bestSum(8,[1,4,5])) # [4, 4]
print(bestSum(100,[1,2,5,25])) # [25, 25, 25, 25]
