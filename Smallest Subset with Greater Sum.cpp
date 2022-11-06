//https://practice.geeksforgeeks.org/problems/smallest-subset-with-greater-sum/1

//code

class Solution{
    public:
    static bool cmp(int& a, int& b){

        return a > b;

    }

int minSubset(vector<int> &Arr,int N){

        long long sum = 0;

        

        sort(Arr.begin(), Arr.end(), cmp);

        

        for(int i = 0; i < N; i++){

            sum += Arr[i];

        }

        long long Temp = 0;

        int ans = 0;

        for(int i = 0; i < N; i++){

            Temp += Arr[i];

            sum -= Arr[i];

            ans++;

            if(Temp > sum){

                return ans;

            }

        }

    }
};
