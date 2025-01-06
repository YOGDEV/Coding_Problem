//Here is the concept of adding a number to the range of a given array
//since we are adding the number to some range, we can do it in o(n^2) complexity by traversing in the range for the given query
//to avoid such condition we, try to find the effective change or diff in the array
//for that we initialize the n+1 length array to zero
//after that we add the number at its first occurance of the range 
//and subtract the number at end_of_range + 1 
//and finally to get the effective diff we calculate the prefix sum


2381. Shifting Letters II // try doing this question for proper undesrtanding, also try to implment the fenwick tree solution for this question
//Solution 1
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        //new infromation added, that is thr effective impact on the array to add some value in some range of the array in O(n) time

        int n = s.size();
        vector<int> diff(n+1,0);

        for(auto itr : shifts)
        {
            if(itr[2] == 0)
            {
                diff[itr[0]]--;
                diff[itr[1]+1]++;
            }
            else
            {
                diff[itr[0]]++;
                diff[itr[1]+1]--;
            }
        }

        //calculate the effective change in array by doing prefix sum
        for(int i = 1;i<=n;i++)
            diff[i] += diff[i-1];
        
        string ans;
        for(int i=0;i<n;i++)
        {
            int count = diff[i] % 26;
            if(count < 0)
            {
                count += 26;
            }
            char ch = char((s[i]-'a' + count)%26 + 97);
            ans.push_back(ch);
        }
        return ans;
    }
};

//Sloution 2
class Solution {
public:
    int n;
    vector<int> bit;

    void add(int val,int id)//id = index
    {
       
        while(id <= n)
        {
            bit[id] += val;
            id += (id & -id);
        }
    }

    int query(int id)
    {
        int sum=0;
        while(id > 0)
        {
            sum+= bit[id];
            id -= (id & -id);
        }
        return sum;
    }
    
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        //new infromation added, that is thr effective impact on the array to add some value in some range of the array in O(n) time

        n = s.size();
        bit.assign(n+2,0);

        for(auto itr : shifts)
        {
           itr[2] == 1 ? add(1,itr[0]+1) : add(-1,itr[0]+1);
           itr[2] == 1 ? add(-1,itr[1]+2) : add(1,itr[1]+2);
        }
        
        for(int i=0;i<n;i++)
            s[i] = 'a' + ((s[i] - 'a') + (query(i+1) % 26) + 26) % 26;
        
        return s;
    }
};
