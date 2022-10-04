/*

https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1?page=1&curated[]=7&sortBy=submissions

Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.

 

Example:
Input:
2
5
111 222 333 444 555
3
121 131 20

Output:
1
0

Explanation:
For First test case.
n=5;
A[0] = 111    //which is a palindrome number.
A[1] = 222   //which is a palindrome number.
A[2] = 333   //which is a palindrome number.
A[3] = 444  //which is a palindrome number.
A[4] = 555  //which is a palindrome number.
As all numbers are palindrome so This will return 1.

*/

//codeclass Solution {
public:
    int ispal(int num)
    {
        string str=to_string(num);
        int s=0,e=str.length()-1;
        
        while(s<e)
        {
            if(str[s++]!=str[e--])
            return 0;
        }
        return 1;
    }
    int PalinArray(int a[], int n)
    {
    	for(int i=0;i<n;i++)
    	{
    	    if (!ispal(a[i]))
    	      return 0;
    	}
    	return 1;
    }
};
