//https://www.codechef.com/problems/BEAUTGAR?tab=statement

//code

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int cr=0;
	    int cg=0;
	    int cp=0;
	    int n=s.length();
	    bool flag=false;
	    if(n%2)flag=true;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='R')
	        cr++;
	        else 
	        cg++;
	        if(i>0)
	        {
	            if(s[i-1]==s[i])cp++;
	        }
	    }
	    if(n>2 and s[0]==s[n-1])cp++;
	    if(cr!=cg || cp>2)flag=true;
	    if(flag)cout<<"no\n";
	    else cout<<"yes"<<endl;
	}
	return 0;
}
