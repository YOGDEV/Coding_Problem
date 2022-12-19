//https://practice.geeksforgeeks.org/problems/alex-travelling/1

//code

//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

// Position this line where user code will be pasted.

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();

            int tmp = sc.nextInt();
            int[][] flights = new int[tmp][3];
            for (int i = 0; i < tmp; i++) {

                int u1 = sc.nextInt();
                int v1 = sc.nextInt();
                int w1 = sc.nextInt();
                flights[i][0] = u1;
                flights[i][1] = v1;
                flights[i][2] = w1;
            }

            Solution ob = new Solution();
            int ans = ob.minimumCost(flights, n, k);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Node
{
    int v,w;
    Node(int V,int W)
    {
        this.v=V;
        this.w=W;
    }
}
class Solution {
    int dis[];//global array
    int minimumCost(int[][] flights, int n, int k) {
        
       
        List<List<Node>> adj=new ArrayList<>();
        
        for(int i=0;i<=n;i++)
        {
            adj.add(new ArrayList<>());
        }
        
        for(int arr[] : flights)
        {
            adj.get(arr[0]).add(new Node(arr[1],arr[2]));
        }
        
        dis=new int[n+1];
        
        for(int i=0;i<=n;i++)
        {
            Arrays.fill(dis,Integer.MAX_VALUE);
        }  
        
        dijkistra(adj,k);
        
        //last portion
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=Math.max(ans,dis[i]);
        }
        return ans==Integer.MAX_VALUE?-1 : ans;
    }
    void dijkistra(List<List<Node>> adj,int start)
    {
        PriorityQueue<Node> pq=new PriorityQueue<>((x,y) ->{return x.w - y.w;});
        
        dis[start]=0;
        pq.add(new Node(start,0));
        
        while(!pq.isEmpty())
        {
            Node curr=pq.poll();
            for(Node nei : adj.get(curr.v))
            {
                if(dis[nei.v] > dis[curr.v] + nei.w)
                {
                    dis[nei.v]=dis[curr.v] + nei.w;
                    pq.add(new Node(nei.v,dis[nei.v]));
                }
                
            }
        }
    }
}
