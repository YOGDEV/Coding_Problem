//https://practice.geeksforgeeks.org/problems/least-prime-factor5216/1

//code

vector<int> leastPrimeFactor(int n) {
      vector<int> ans(n+1,-1);
      ans[0]=0;
      ans[1]=1;
      for(int i=2;i<n+1;i++)
      {
          if(ans[i]==-1)
          {
              for(int j=i;j<=n;j+=i)
              {
                  if(ans[j]==-1)ans[j]=i;
              }
          }
      }
      return ans;
    }
