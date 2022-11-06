//https://www.codechef.com/submit/RRSTONE?tab=statement
/*
Roman has no idea, why this problem is called Stone. He also has no idea on how to solve the followong problem: given array of N integers A and a number K. During a turn the maximal value over all Ai is chosen, let's call it MAX. Then Ai = MAX - Ai is done for every 1 <= i <= N. Help Roman to find out how will the array look like after K turns.

Input
The numbers N and K are given in the first line of an input. Then N integers are given in the second line which denote the array A.

Output
Output N numbers on a single line. It should be the array A after K turns.

Constraints
1 <= N <= 105
0 <= K <= 109
Ai does not exceed 2 * 109 by it's absolute value.
Sample 1:
Input
Output
4 1
5 -1 7 0
2 8 0 7

*/

//code

#include<bits/stdc++.h>
#include <iostream>
#include<climits>
using namespace std;

int main() {
	long long int n,k;
	cin>>n>>k;
	
	vector<long long int> arr;
	long long int maxi=INT_MIN;
	long long int mini=INT_MAX;
	long long int a;
	
    for(int i=0;i<n;i++){cin>>a;maxi=max(maxi,a);mini=min(mini,a);arr.push_back(a);}
    
	if(k==0)
	{
	for(int i=0;i<n;i++)cout<<arr[i]<<" ";    
	}
	else {
	    for(int i=0;i<n;i++)
	    arr[i]=maxi-arr[i];
	    if(k&1)
	    {
	        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
	    }
	    else
	    {
	        long long int d=maxi-mini;
	        for(int i=0;i<n;i++)cout<<d-arr[i]<<" ";
	    }
	}
	cout<<endl;
	return 0;
    
}

