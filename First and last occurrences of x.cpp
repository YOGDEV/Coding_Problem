/*

https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1?page=1&curated[]=7&sortBy=submissions

Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Example 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  2 5
Explanation: First occurrence of 5 is at index 2 and last
             occurrence of 5 is at index 5. 
 

Example 2:

Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  6 6 

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function find() that takes array arr, integer n and integer x as parameters and returns the required answer.
Note: If the number x is not found in the array just return both index as -1.

 

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1).

 

Constraints:
1 ≤ N ≤ 107

*/

//code

int left(int arr[],int n,int x)
{
    int s=0;
    int e=n-1;
    int index=-1;
    int mid=s+(e-s)/2;
    
    while(s<=e)
    {
        if(arr[mid]==x){
        e=mid-1;
        index=mid;
        }        
         else if(arr[mid]>x)
        e=mid-1;
        else
        s=mid+1;
        mid=s+(e-s)/2;
    }
    return index;
}
int right(int arr[],int n,int x)
{
    int s=0;
    int e=n-1;
    int index=-1;
    int mid=s+(e-s)/2;
    
    while(s<=e)
    {
        if(arr[mid]==x){
        s=mid+1;
        index=mid;
        }        
        else if(arr[mid]>x)
        e=mid-1;
        else
        s=mid+1;
        mid=s+(e-s)/2;
    }
    return index;
}
vector<int> find(int arr[], int n , int x )
{
    vector<int> v;
    int first=left(arr,n,x);
    int second=right(arr,n,x);
    v.push_back(first);
    v.push_back(second);
    return v;
}
