# Python program to find the largest
# subset where each pair is divisible.

# function to find the longest Subsequence
def largestSubset(a, n):
	
	# dp[i] is going to store size
	# of largest divisible subset
	# beginning with a[i].
	dp = [0 for i in range(n)]
	
	# Since last element is largest,
	# d[n-1] is 1
	dp[n - 1] = 1;

	# Fill values for smaller elements
	for i in range(n - 2, -1, -1):
		
		# Find all multiples of a[i]
		# and consider the multiple
		# that has largest subset	
		# beginning with it.
		mxm = 0;
		for j in range(i + 1, n):
			if a[j] % a[i] == 0 or a[i] % a[j] == 0:
				mxm = max(mxm, dp[j])
		dp[i] = 1 + mxm
		
	# Return maximum value from dp[]
	return max(dp)

# Driver Code
a = [ 1, 3, 6, 13, 17, 18 ]
n = len(a)
print(largestSubset(a, n))


