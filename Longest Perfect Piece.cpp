//https://practice.geeksforgeeks.org/problems/close-to-perfection1525/1

 PriorityQueue<Integer> min_H = new PriorityQueue<>(); // min heap
         PriorityQueue<Integer> max_H = new PriorityQueue<>(Collections.reverseOrder());
         
         int ans=0;
         for(int i =0,j=0; i<N;i++)
         {
             min_H.add(arr[i]);
             max_H.add(arr[i]);
             
             while(j<N && max_H.peek() - min_H.peek() >1) // pt of violation of cond
             {
                  min_H.remove(arr[j]);
                max_H.remove(arr[j]);
                j++;
             }
             ans= Math.max(ans, max_H.size());
         }
         return ans;
