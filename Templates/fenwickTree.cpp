class fanwickTree{
public:
    vector<int> bit;
    int n;

    fanwickTree(int n)
    {
        this->n=n;
        bit = vector<int>(n+1,0);
    }

    void add(int id,int val)
    {
        while(id <= n)
        {
            bit[id]=max(bit[id],val);//bit[id]+=val; for summ problem , if new value has to be added then first delete the exixting value at all places in sum query,as add(id,-prev_val) then add(id,new_val)
            id += (id & -id);
        }
    }

    int query(int id)
    {
        int max_gap=0;
        while(id > 0)
        {
            max_gap=max(max_gap,bit[id]); // for sum query sum+=bit[id], return sum
            id -= (id & -id);
        }
        return max_gap;
    }
};


// give a try to question number 3161 at leetcode
