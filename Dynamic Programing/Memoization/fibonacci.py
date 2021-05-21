def fib(n, memo={}):
	if (n in memo):
		return memo[n];
	if n<=2:
		return 1;
	memo[n]=fib(n-1)+fib(n-2)
	return memo[n];

# By lru_cache : 
# import functools

# @functools.lru_cache(maxsize=None) #128 by default
# def fib(num):
# 	if num<2:
# 		return num;
# 	return fib(num-1)+fib(num-2)


print(fib(6))
print(fib(7))
print(fib(8))
print(fib(50))

