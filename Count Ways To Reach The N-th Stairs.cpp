/*

https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

*/

//fisrt approch
/*
    Time Complexity: O( 2 ^ N )
    Space complexity: O( N )

    Where ‘N’ is the stair to reach, given in the input.
*/

int getCount(int currStep, int nStairs, const int& mod) {

    // Base case.
    if(currStep >= nStairs) {

        return (currStep == nStairs);
    }

    //  Climb one stair.
    int oneStepcount = getCount(currStep + 1, nStairs, mod);

    //  Climb two stairs
    int twoStepCount = getCount(currStep + 2, nStairs, mod);

    return (oneStepcount + twoStepCount) % mod; 

}

int countDistinctWays(int nStairs) {
    
    // Initialize the variable 'mod'.
    const int mod = 1000000007;

    // Initialize the variable 'ways'.
    int ways = getCount(0, nStairs, mod);

    return ways;
}


//second approch/*
    Time Complexity: O( N )
    Space complexity: O( N )

    Where ‘N’ is the stair to reach, given in the input.
*/

int getCount(int currStep, int nStairs, vector<int> &dp, const int &mod) {

    // Base case.
    if (currStep >= nStairs) {

        return (currStep == nStairs);
    }

    // Check we have already solution or not?.
    if (dp[currStep] != -1) {

        return dp[currStep];
    }

    // Climb one stair.
    int oneStepcount = getCount(currStep + 1, nStairs, dp, mod);

    // Climb two stairs.
    int twoStepCount = getCount(currStep + 2, nStairs, dp, mod);

    // Store for later use.
    dp[currStep] = (oneStepcount + twoStepCount) % mod;

    return dp[currStep];
}

int countDistinctWays(int nStairs) {
    
    // Initialize the variable 'mod'.
    const int mod = 1000000007;

    // Create an array 'dp' of length 'nStairs + 1' with initial value '-1'.
    vector<int> dp(nStairs + 1, -1);

    // Initialize the variable 'ways'.
    int ways = getCount(0, nStairs, dp, mod);

    return ways;
}

//third approch
/*
    Time Complexity: O( N )
    Space complexity: O( 1 )

    Where ‘N’ is the point to reach given in the input.
*/

int countDistinctWays(int nStairs) {
    
    // Initialize the variable 'mod'.
    const int mod = 1000000007;

    // Create an array 'dp' of length '2' with intial value '1'.
    vector<int> dp(2, 1);

    // Checking if 'nStairs' is less than or equal to '1', 
    // Because in that case there is no need for further calculation.
    if(nStairs <= 1) {

        return dp[nStairs];
    }

    // Iterate on the range '[2, nStairs]'.
    for (int currStep = 2; currStep <= nStairs; currStep++) {

        // Calculate ways to reach 'currStep'th stair.
        int currStepWays = (dp[0] + dp[1]) % mod;

        // Update 'dp' array.
        dp[0] = dp[1];

        dp[1] = currStepWays;
    }

    return dp[1];
}
