//code  

#include<iostream>
using namespace std;
#include<vector>
void display(vector<int> v)
{   if(v.size()==0)
    cout<<"{}";
    for(auto i :v ){
        cout<<i<<"  ";
    }
    cout<<endl;
}
void print(int ind,vector<int> v,int n,int arr[])//recursion
{   
    if(ind>=n)
    {
        display(v);      
        return ;
    }
    
 
    //pick
    v.push_back(arr[ind]);
    print(ind+1,v,n,arr);
    v.pop_back();

    //not pick
    print(ind+1,v,n,arr);
    
}
int main()
{
    int arr[100];
    int n;
    
    cout<<"\nEnter number of elements : ";
    cin>>n;
    cout<<"\nEnter array element ::::::::\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    vector<int> v;//data structure of holding subsuquence
    
    cout<<"\nprinting subsequences :::::::::::\n";
    print(0,v,n,arr);
    return 0;
}
