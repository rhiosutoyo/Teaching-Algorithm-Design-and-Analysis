//	Source: https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

/*
	----------------------------
	0-1 Knapsack Problem | DP-10
	----------------------------
	Given weights and values of n items, put these items in a knapsack of capacity W to get the 
	maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] 
	which represent values and weights associated with n items respectively. Also given an integer W which 
	represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights 
	of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or 
	don’t pick it (0-1 property).
*/


/* 
	-----------------
	PROBLEM DEFINTION
	-----------------
	value[] = {60, 100, 120}
	weight[] = {10, 20, 30}
	W = 50
	
	Solution: 220
*/

// A Dynamic Programming based
// solution for 0-1 Knapsack problem
#include <stdio.h>

// A utility function that returns
// maximum of two integers
int max(int a, int b){
	return (a > b) ? a : b;
}

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n){
	int i, w;
	int K[n + 1][W + 1];

	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++){
		for (w = 0; w <= W; w++){
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1]
						+ K[i - 1][w - wt[i - 1]],
						K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}

int main(){
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;

	int n = sizeof(val) / sizeof(val[0]);
	printf("%d", knapSack(W, wt, val, n));

	return 0;
}


