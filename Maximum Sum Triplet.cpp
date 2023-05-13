//https://www.interviewbit.com/problems/maximum-sum-triplet/

//code

int Solution::solve(vector<int> &A) {
    vector<int> suffix(A.size(),0);
    for(int i=A.size()-1;i>=0;i--)
    {
        if(i==A.size()-1)suffix[i]=A[i];
        else suffix[i]=max(A[i],suffix[i+1]);
    }
    int ans=-1;
    set<int> s;
    s.insert(A[0]);
    for(int i=1;i<A.size();i++)
    {
        s.insert(A[i]);
        auto itr=s.find(A[i]);
        if(itr!=s.begin() and suffix[i]!=A[i])
        ans=max(ans,*(--itr)+A[i]+suffix[i]);
    }
    return ans;
}

