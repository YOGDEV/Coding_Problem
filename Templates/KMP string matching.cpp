//KMP string matching

//this will return the vector of length string1 + string2 + 1( for '#') and if the length is equal to the size of the substring pattern the it implies that there exists the substring match.

//code->

vector<int> kmp(string& s)
    {
        int n=s.size();
        vector<int> lps(n,0);

        for(int i=1;i<n;i++)
        {
            int pre_index = lps[i-1];

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
        for(int i=0;i<m;i++)
        {
            if(pattern[i]==1)ps.push_back('a');
            if(pattern[i]==0)ps.push_back('s');
            if(pattern[i]==-1)ps.push_back('d');
        }

        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]-nums[i] > 0)ns.push_back('a');
            if(nums[i+1]-nums[i] == 0)ns.push_back('s');
            if(nums[i+1]-nums[i] < 0)ns.push_back('d');
        }

        string hash_string = ps + "#" + ns;
        vector<int> lps=kmp(hash_string);

        for(int i=m;i<lps.size();i++)
            if(lps[i] == m){

              ---------------------
              --------------------Your logic now to implement
            }
    }
