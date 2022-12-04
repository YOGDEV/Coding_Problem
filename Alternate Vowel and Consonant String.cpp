//https://practice.geeksforgeeks.org/problems/alternate-vowel-and-consonant-string2939/1

//code

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string S, int N)
    {
        
        int v=0;
        int c=0;
        int freq_v[26]={0};
        int freq_c[26]={0};
        
        char small_vowel='u';
        char small_cons='z';
        
        for(int i=0;i<N;i++)
        {   
            
            if(S[i]=='a' || S[i]=='e' || S[i]=='i' || S[i]=='o'|| S[i]=='u'){ freq_v[S[i]-'a']++;v++; if(small_vowel>S[i])small_vowel=S[i];}
            else {freq_c[S[i]-'a']++;c++;if(small_cons>S[i])small_cons=S[i];}
        }
        
        if(abs(c-v)>1)return "-1";
        
        bool flag = true;//for start with vowel
        if(c==v)
        {
            if(small_vowel>small_cons)
            flag=false;
            else
            flag=true;
        }
        if(c>v)//consonents are more than vowel by '1'
        {
            flag=false;
        }
        else if(v>c)
        {
            flag=true;
        }
        string ans;
        int k=0;
        int i=0,j=0;
        while(i< 26 || j<26)
        {
            if(flag==true)
            { 
                while(i<26 && freq_v[i]==0)i++;
                if(i==26)break; 
                // ans+=(char)(i+'a');
                ans.push_back((char)(i+'a'));
                freq_v[i]--;
                flag=false;
                 
            }
            else
            {
                while(j<26 && freq_c[j]==0)j++;
                if(j==26)break;
                ans+=(char)('a'+j);
                freq_c[j]--;
                flag=true;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
