//https://leetcode.com/problems/ugly-number/

//code

 bool isUgly(int n) {
        if(n==1)return true;
        if(n==0)return false;
        while(n!=1){
        if(n%5!=0 && n% 3!=0 && n%2!=0)return false;
        if(n%5==0)
        {
          n=n/5;
        }
        else if(n%3==0)
        n/=3;
        else  if(n%2==0)
        {n/=2;cout<<n<<endl;}
        }
        if(n==1)return true;
        return false;
    }
