//https://leetcode.com/problems/snapshot-array/

//code

int id=0;
    map<int,map<int,int>> snaps;
    SnapshotArray(int length) {
        for(int i=0;i<length;i++)
        {
            map<int,int> mp;
            mp[0]=0;
            snaps[i]=mp;
        }
    }
    
    void set(int index, int val) {
        snaps[index][id]=val;
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        auto itr=snaps[index].upper_bound(snap_id);
        itr--;
        return itr->second;
    }
