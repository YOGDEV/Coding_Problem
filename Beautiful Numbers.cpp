//https://www.codechef.com/problems/ITGUY10

//code

#include <iostream>
using namespace std;

bool helper(int num)
{
    if((num&(num>>1))>0)return false;
    return true;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int num;
	    cin>>num;
	    
	    while(!helper(num))
	    {
	        --num;
	    }
	    cout<<num<<endl;
	}
	return 0;
}
