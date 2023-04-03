//https://leetcode.com/problems/boats-to-save-people/

//code

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        //first sort the people array
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        int ans=0;
        while(i<=j)
        {
            int sum=people[i]+people[j];
            if(sum<=limit)
            {
                ans++;
                i++;
                j--;
            }
            else
            {
                ans++;
                j--;
            }
        }
        return ans;
    }
};
