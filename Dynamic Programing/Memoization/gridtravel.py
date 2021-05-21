import functools
# LRU Cache implementation
# @functools.lru_cache(maxsize=None) #128 by default
# def gt(m,n):
# 	if(m==1 or n==1):
# 		return 1;
# 	elif (m==0 or n==0):
# 		return 0;
# 	return gt(m-1,n) + gt(m,n-1);
def gt(m,n,memo={}):
	key=str(m)+','+str(n)
	if key in memo:
		return memo[key]
	if(m==1 and n==1):
		return 1;
	elif (m==0 or n==0):
		return 0;
	memo[key] = gt(m-1,n) + gt(m,n-1);
	return memo[key]


print(gt(1,1)) # 1
print(gt(2,3)) # 3
print(gt(3,2)) # 3
print(gt(3,3)) # 6
print(gt(18,18)) # 2333606220