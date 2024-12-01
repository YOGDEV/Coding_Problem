1408. String Matching in an Array

class Solution {
public:
    #define ll long long
    const ll radix_1=26;
    const ll radix_2=27;
    const ll mod_1 = 1000000007;
    const ll mod_2 = 1000000033;

    pair<ll,ll> function(string s, int m)
    {   
        ll hash_1=0,hash_2=0;
        ll factor_1=1,factor_2=1;

        for(int i=m-1;i>=0;i--)
        {
            hash_1 += ((s[i]-'a')* factor_1) % mod_1;
            factor_1 = (factor_1 * radix_1) % mod_1;

            hash_2 += ((s[i]-'a')* factor_2) % mod_2;
            factor_2 = (factor_2 * radix_2) % mod_2;
        }
        return {hash_1 % mod_1, hash_2 % mod_2};
    }
    int helper(string one,string two)
    {
        int m=one.size(),n=two.size();
        if(m>n) return -1;
        
        ll max_val_1=1,max_val_2=1;
        for(int i=0;i<m;i++)
        {
            max_val_1=(max_val_1*radix_1)%mod_1;
            // cout<<max_val_1<<" ";
            max_val_2=(max_val_2*radix_2)%mod_2;
            // cout<<max_val_2<<" ";
        }

        pair<ll,ll> minor=function(one,m);
        pair<ll,ll> major={0,0};

        for(int i=0;i<=n-m;i++)
        {
            if(i == 0)
            {
                major = function(two,m);
            }
            else
            {
                // cout<<major.first<<" ";
                major.first = ((major.first * radix_1 )% mod_1 
                - ((two[i-1]-'a') * max_val_1 ) % mod_1
                + (two[i+m-1]-'a') + mod_1) % mod_1; 
            
                major.second = ((major.second * radix_2)% mod_2 
                - ((two[i-1]-'a')*max_val_2)%mod_2 
                + (two[i+m-1]-'a') + mod_2)%mod_2;
            }

            if(major.first == minor.first && major.second == minor.second)
                return i;
        }
        return -1;
    }
    vector<string> stringMatching(vector<string>& words) {
        //rabin karp algo   // try KMP tomorrow
        vector<string> ans;
        map<string,int> count;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(i!=j and helper(words[i],words[j])!=-1)
                {
                    if(count.find(words[i])==count.end())
                    {
                        ans.push_back(words[i]);
                        count[words[i]]=1;
                    }
                }
            }
        }
        return ans;
    }
};
