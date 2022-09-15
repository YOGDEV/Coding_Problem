/*

Sample Input 2:
1
4 7
2 2 3 3 4 4 1 
Sample Output 2:
6
Explanation Of Sample Input 2:
The ayush will read the chapter as follows,
Day 1 : 1 , 2          Time required : 4
Day 2 : 3 , 4          Time required : 6
Day 3 : 5              Time required : 4
Day 4 : 6 , 7          Time required : 5
So the maximum time in a day is 6.


Sample Input 1:
1
3 5
1 2 2 3 1
Sample Output 1:
4
Explanation Of Sample Input 1:
The ayush will read the chapter as follows,
Day 1 : 1 , 2         Time required : 3
Day 2 : 3             Time required : 2
Day 3 : 4 , 5         Time required : 4
So the maximum time in a day is 4.


link : Book Allocation Problem: https://bit.ly/3GiCqY0

*/
#include <bits/stdc++.h>
bool isPossible(int n,int m,vector<int> time,int mid)
{
    long long time_required=0;//n denotes days in which all the chapters are supposed to be completed...
    long long day=1;
    
    for(int i=0;i<m;i++)//m denotes number of chapters to be studied 
    {
        if(time_required+ time[i]<=mid)
        {
            time_required+=time[i];
        }
        else
        {
            day++;
            if(day>n || time[i]>mid)return false;
            time_required=time[i];
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long s=0;
    long long  sum=accumulate(time.begin(),time.end(),0);
    long long e=sum;
    long long ans=-1;
    long long mid=s+(e-s)/2;
    while(s<=e)
    {
        if(isPossible(n,m,time,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
            s=mid+1;
        mid=s+(e-s)/2;
    }
    return ans;
}
