//https://leetcode.com/problems/daily-temperatures/

//code

 vector<int> dailyTemperatures(vector<int>& arr) {
        stack<pair<int,int>> st;
        int n=arr.size();
        
        st.push({arr[0],0});
        
        vector<int> v(n,0);
        for(int i=1;i<n;i++)
        {
         while( !st.empty() and st.top().first < arr[i])
         {
          v[st.top().second]=i-st.top().second;
          st.pop();
         }
          st.push({arr[i],i});   
        }
        
        v[st.top().second]=0;
        return v;
    }   
