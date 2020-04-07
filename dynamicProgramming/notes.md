## Dynamic Programming Notes  <br/>

### KnapSack Problem
Given weights and values of n items, put these items in a knapsack of
capacity W to get the maximum total value in the knapsack. 
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] 
which represent values and weights associated with n items respectively. 
Also given an integer W which represents knapsack capacity, find out the
maximum value subset of val[] such that sum of the weights of this 
subset is smaller than or equal to W. You cannot break an item,
either pick the complete item, or don’t pick it (0-1 property)

In this problem we define dp[i][j] as i value and for j knapsack capacity. That is for j capacity how much maximum value it can store. 

```
if( j < wt[i]) 
		dp[i][j] = dp[i-1][j];
	else 
		dp[i][j] = max(dp[i-1][j - wt[i]] + val[i] , dp[i-1][j]);

```
### Longest Common Subsequnce 
Given two sequences, find the length of longest subsequence present in both of them. In the code given below we assume X,Y to be strings. 
 ``` 
        if (i == 0 || j == 0)  
            dp[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            dp[i][j] = dp[i - 1][j - 1] + 1;  
      
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
         
 ```
 
### Maximum Sum Subarray 
The maximum subarray problem is the task of finding the largest possible sum of a contiguous subarray, within a given one-dimensional array A[1…n] of numbers.


```
	dp[i] = dp[i-1] + a[i] - a[i-k-1]
```
### Longest Increasing Subsequence 
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.

