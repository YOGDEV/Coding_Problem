//KMP string matching

//this will return the vector of length string1 + string2 + 1( for '#') and if the length is equal to the size of the substring pattern the it implies that there exists the substring match.

//code->

vector<int> kmp(string& s)
    {
        int n=s.size();
        vector<int> lps(n,0);

        for(int i=1;i<n;i++)
        {
            int pre_index = lps[i-1];//here lps vector gives the length of the matching string at the ith position or at till s[i] character included

            while(pre_index > 0 and (s[i] != s[pre_index]))
                pre_index = lps[pre_index-1];

            lps[i] = pre_index + (s[i] == s[pre_index]? 1 : 0);
        }
        return lps;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        //KMP
        int n=nums.size(),m=pattern.size(),ans=0;
        string ps="",ns="";//ps -> pattern string
        // for(int i=0;i<m;i++)                  Modify your strings if needed as per of the questions
        // {
        //     if(pattern[i]==1)ps.push_back('a');
        //     if(pattern[i]==0)ps.push_back('s');
        //     if(pattern[i]==-1)ps.push_back('d');
        // }

        // for(int i=0;i<n-1;i++)
        // {
        //     if(nums[i+1]-nums[i] > 0)ns.push_back('a');
        //     if(nums[i+1]-nums[i] == 0)ns.push_back('s');
        //     if(nums[i+1]-nums[i] < 0)ns.push_back('d');
        // }

        string hash_string = ps + "#" + ns;
        vector<int> lps=kmp(hash_string);

        for(int i=m;i<lps.size();i++)
            if(lps[i] == m){

              ---------------------
              --------------------Your logic now to implement
            }
        //for getting the index of starting index of matching string in the major string do this, ind = i - 2*( patter.size() ),where i starts from m, size of pattern
    }




//try doing 1408. String Matching in an Array , this is really a good question that involve the use of kmp,
// The inefficiency of the naive algorithm lies in how it handles mismatches.
//     When a mismatch occurs, the algorithm shifts the starting index in the main string by one position
// and restarts the comparison from the first character of sub, even though parts of sub may have already matched.
//     The algorithm redundantly rechecks the prefix "aaa" for different starting positions in main.
//     Instead of restarting the comparison every time, we can remember that the prefix "aaa" is already a match. 
//     For the next attempt, we shift sub and continue matching from where we left off.

To achieve this, we use the LPS (Longest Prefix Suffix) table.
The LPS table helps us skip unnecessary comparisons when a mismatch occurs. It stores, for each prefix of sub, the length of the longest proper prefix that is also a suffix.
class Solution {
public:
    vector<int> kmp(string& s)
    {
        int n=s.size();
        vector<int> lps(n,0);

        for(int i=1;i<n;i++)
        {
            int pre_index = lps[i-1];//here lps vector gives the length of the matching string at the ith position or at till s[i] character included

            while(pre_index > 0 and (s[i] != s[pre_index]))
                pre_index = lps[pre_index-1];

            lps[i] = pre_index + (s[i] == s[pre_index]? 1 : 0);
        }
        return lps;
    }
    bool isSubstring(string& sub,string& main,vector<int>& lps)
    {
        //Really Goof Implementation of KMP Algorithm really Good
        int main_index=0;
        int sub_index=0;

        while(main_index < main.size())
        {
            if(main[main_index] == sub[sub_index])
            {
                main_index++;
                sub_index++;
                if(sub_index == sub.size())
                    return true;
            }
            else if(sub_index > 0)
            {
                sub_index = lps[sub_index - 1];
            }
            else
            {
                main_index++;
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        //rabin karp algo   
        vector<string> ans;
        for(int i=0;i<words.size();i++)//sub string
        {
            vector<int> lps = kmp(words[i]);//sub string

            for(int j=0;j<words.size();j++)//main string
            {
                if(i==j)continue;

                if(isSubstring(words[i],words[j],lps))
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
