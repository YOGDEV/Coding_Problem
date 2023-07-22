688. Knight Probability in Chessboard

//https://leetcode.com/problems/knight-probability-in-chessboard/

//code

unordered_map<string,double> mp;
    int dir[8][8]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    
    double helper(int n, int moves,int row ,int column)
    {
        if(row<0 or row>=n or column<0 or column>=n)
            return 0;
        
        if(moves==0)return 1;
        
        string key=to_string(row)+"yog"+to_string(column)+"yog"+to_string(moves);
        
        if(mp.find(key)!=mp.end())
            return mp[key];
        
        double probability=0;
        for(int i=0;i<8;i++)
        {
            probability+=helper(n,moves-1,row+dir[i][0],column+dir[i][1])/8.0;
        }
        
        mp[key]=probability;
        return mp[key];
    }
    double knightProbability(int n, int k, int row, int column) {
        return helper(n,k,row,column);
    }

//always return 1 in the base case of probabitity questions ,,, rember always
... Good Luck Yogi bhaii
