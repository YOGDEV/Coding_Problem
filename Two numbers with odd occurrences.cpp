//https://practice.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1

/*
Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences.

Example 1:

Input:
N = 8
Arr = {4, 2, 4, 5, 2, 3, 3, 1}
Output: {5, 1} 
Explaination: 5 and 1 have odd occurrences.

Example 2:

Input:
N = 8
Arr = {1 7 5 7 5 4 7 4}
Output: {7, 1}
Explaination: 7 and 1 have odd occurrences.

Your Task:
You don't need to read input or print anything. Your task is to complete the function twoOddNum() which takes the array Arr[] and its size N as input parameters and returns the two numbers in decreasing order which have odd occurrences.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/


//code

class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int x=0;
        for(int i=0;i<N;i++)
        {
            x=x^Arr[i];
        }
        
        long long int set=0;
        for(int i =0;i<N;i++)
        {
            long long int curr=1<<i;
            if((x&curr)!=0)
            {
                set=curr;
                break;
            }
        }
        
        long long int first=0;
        long long int second=0;
        
        for(int i=0;i<N;i++)
        {
            if((set&Arr[i])!=0)
            {
                first^=Arr[i];
            }
            else
            {
                second^=Arr[i];
            }
        }
        
        vector<long long int> v;
        v.push_back(max(first,second));
        v.push_back(min(first,second));
        
        return v;
    }
};
