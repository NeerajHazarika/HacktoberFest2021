/*
The knapsack problem is a problem in combinatorial optimization: Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible. It derives its name from the problem faced by someone who is constrained by a fixed-size knapsack and must fill it with the most valuable items. The problem often arises in resource allocation where the decision makers have to choose from a set of non-divisible projects or tasks under a fixed budget or time constraint, respectively.
*/

// Here is the top-down approach of dynamic programming
#include <bits/stdc++.h>
using namespace std;

// Returns the value of maximum profit
int knapSackRec(int W, int wt[], int val[], int i, int** dp)
{
	// base condition
	if (i < 0)
		return 0;
	if (dp[i][W] != -1)
		return dp[i][W];

	if (wt[i] > W) {
		// Store the value of function call stack in table before return
		dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
		return dp[i][W];

	}
	else {
		// Store value in a table before return
		dp[i][W] = max(val[i] + knapSackRec(W - wt[i], wt, val, i - 1, dp),
		knapSackRec(W, wt, val, i - 1, dp));

		// Return value of table after storing
		return dp[i][W];

	}
}

int knapSack(int W, int wt[], int val[], int n)
{
	// double pointer to declare the table dynamically
	int** dp;
	dp = new int*[n];

	// loop to create the table dynamically
	for (int i = 0; i < n; i++)
		dp[i] = new int[W + 1];

	// loop to initially filled the table with -1
	for (int i = 0; i < n; i++)
		for (int j = 0; j < W + 1; j++)
			dp[i][j] = -1;

	return knapSackRec(W, wt, val, n - 1, dp);

}

// Driver Code
int main()
{
	//Inputs
	int W,n;
  cout<<"Enter the maximum weight the knapsack can hold : ";
  cin>>W;
  cout<<"\nEnter number of items to be choosen from : ";
  cin>>n;
  int val[n],wt[n];
    
  cout<<"\nEnter the weights to be choosen from : "; 
  for(int i=0;i<n;i++){
      cin>>wt[i];
  }
  cout<<"\nEnter the values corresponding to these weights : ";
  for(int i=0;i<n;i++){
      cin>>val[i];
  }

	cout <<"\nMax profit : "<<knapSack(W, wt, val, n);
	return 0;
}

/*
Sample Input : 
50
3
10 20 30
60 100 120

Sample Output :

*/

