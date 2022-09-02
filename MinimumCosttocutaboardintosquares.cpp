/*
https://practice.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1
______________________________________________________________________________________
A board of length M and width N is given. The task is to break this board into M * N squares such that cost of breaking is minimum. 
The cutting cost for each edge will be given for the board in two arrays X[] and Y[]. 
In short, you need to choose such a sequence of cutting such that cost is minimized. Return the minimized cost.

Example 1:

Input:
M = 6. N = 4
X[] = {2, 1, 3, 1, 4}
Y[] = {4, 1, 2}
Output: 42
Explanation: 

For above board optimal way to cut into square is:
Total minimum cost in above case is 42. It is 
evaluated using following steps.
Initial Value : Total_cost = 0
Total_cost = Total_cost + edge_cost * total_pieces
Cost 4 Horizontal cut:      Cost = 0 + 4*1 = 4
Cost 4 Vertical cut:        Cost = 4 + 4*2 = 12
Cost 3 Vertical cut:        Cost = 12 + 3*2 = 18
Cost 2 Horizontal cut:      Cost = 18 + 2*3 = 24
Cost 2 Vertical cut:        Cost = 24 + 2*3 = 30
Cost 1 Horizontal cut:      Cost = 30 + 1*4 = 34
Cost 1 Vertical cut:        Cost = 34 + 1*4 = 38
Cost 1 Vertical cut:        Cost = 38 + 1*4 = 42
 

 

Example 2:

Input:
M = 4, N = 4
X[] = {1, 1, 1}
Y[] = {1, 1, 1}
Output: 15
Explanation: 

For above board optimal way to cut into square is:
Total minimum cost in above case is 15.
It is evaluated using following steps.
Initial Value : 
Total_cost = 0 Total_cost = Total_cost + edge_cost * total_pieces
Cost 1 Horizontal cut: Cost = 0 + 1*1 = 1
Cost 1 Horizontal cut: Cost = 1 + 1*1 = 2
Cost 1 Horizontal cut: Cost = 2 + 1*1 = 3
Cost 1 Vertical cut:   Cost = 3 + 1*3 = 6
Cost 1 Vertical cut:   Cost = 6 + 1*3 = 9
Cost 1 Vertical cut: Cost = 9 + 1*3 = 12
Cost 1 Vertical cut:   Cost = 12 + 1*3 = 15
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function minimumCostOfBreaking() which takes a string S and returns an integer as output.

Expected Time Complexity: O(NlogN + MlogM)
Expected Auxiliary Space: O(1)
*/
//------------------------------------------------------------


class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        M--;
        N--;
        sort(X.begin(),X.end(),greater<int>());
        sort(Y.begin(),Y.end(),greater<int>());
        
        int min_cost=0;
        int move_in_x=0,move_in_y=0;
        int ver_count=1,hor_count=1;
        
        while(move_in_x<M && move_in_y<N)
        {
            if(X[move_in_x]>Y[move_in_y])
            {
                min_cost +=(ver_count*X[move_in_x]);
                hor_count++;
                move_in_x++;
            }
            else
            {
                min_cost +=(hor_count*Y[move_in_y]);
                ver_count++;
                move_in_y++;
            }
        }
        while(move_in_x<M)
        {
           min_cost +=(ver_count*X[move_in_x]); 
           move_in_x++;
        }
        while(move_in_y<N)
        {
           min_cost +=(hor_count*Y[move_in_y]); 
           move_in_y++;
        }
        return min_cost;
    }
};
