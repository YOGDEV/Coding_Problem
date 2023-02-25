//https://practice.geeksforgeeks.org/problems/e7d81a082cda6bd1e959d943197aa3bc21b88bdb/1

//code

//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S[] = read.readLine().split(" ");
            int n = Integer.parseInt(S[0]);
            int m = Integer.parseInt(S[1]);
            
            String S1[] = read.readLine().split(" ");
            int a = Integer.parseInt(S1[0]);
            int b = Integer.parseInt(S1[1]);
            
            ArrayList<ArrayList<Integer>> edges = new ArrayList<ArrayList<Integer>>();
            
            for(int i=0; i<m; i++)
            {
                String S2[] = read.readLine().split(" ");
                int u = Integer.parseInt(S2[0]);
                int v = Integer.parseInt(S2[1]);
                int x = Integer.parseInt(S2[2]);
                int y = Integer.parseInt(S2[3]);
                
                ArrayList<Integer> edge = new ArrayList<>();
                edge.add(u);
                edge.add(v);
                edge.add(x);
                edge.add(y);
                
                edges.add(edge);
            }

            Solution ob = new Solution();
            System.out.println(ob.shortestPath(n,m,a,b,edges));
        }
    }
}
// } Driver Code Ends


//User function Template for Java
class Node
{
    int v,w;
    Node(int v,int w)
    {
        this.v=v;
        this.w=w;
    }
}
class Solution {
    static int shortestPath(int n, int m, int a, int b, ArrayList<ArrayList<Integer>> edges) {
        List<List<Node>> adj=new ArrayList<>();
        ArrayList<ArrayList<Integer>> curve=new ArrayList<>();
        
        for(int i=0;i<=n;i++)
        adj.add(new ArrayList<>());
        
        for(ArrayList<Integer> arr : edges)
        {
            adj.get(arr.get(0)).add(new Node(arr.get(1),arr.get(2)));
            adj.get(arr.get(1)).add(new Node(arr.get(0),arr.get(2)));
            
        ArrayList<Integer> temp=new ArrayList<>();
        temp.add(arr.get(0));
        temp.add(arr.get(1));
        temp.add(arr.get(3));
        
        curve.add(temp);
        
        }
        
        int disa[]=dijkistra(adj,a,n);
        int disb[]=dijkistra(adj,b,n);
        
        int ans=disa[b];
        
        for(int i=0;i<m;i++)
        {
            int u=curve.get(i).get(0);
            int v=curve.get(i).get(1);
            int cw=curve.get(i).get(2);
            
            ans=Math.min(ans,cw+disa[u]+disb[v]);
            ans=Math.min(ans,cw+disb[u]+disa[v]);
        }
        if(ans>=100000001)return -1;
        return ans;
    }
    static int[] dijkistra(List<List<Node>> adj,int start,int n)
    {
        int dis[]=new int[n+1];
        Arrays.fill(dis,100000001);
        
        PriorityQueue<Node> pq=new PriorityQueue<>((x,y)->{return x.w-y.w;});
        
        dis[start]=0;
        
        pq.add(new Node(start,0));
        
        while(!pq.isEmpty())
        {
            Node curr=pq.poll();
            
            for(Node nei : adj.get(curr.v))
            {
                if(dis[nei.v]>dis[curr.v]+nei.w)
                {
                    dis[nei.v]=dis[curr.v]+nei.w;
                    pq.add(new Node(nei.v,dis[nei.v]));
                }
            }
        }
        return dis;
    }
};
