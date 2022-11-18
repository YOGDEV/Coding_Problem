//https://leetcode.com/problems/zigzag-conversion/

//code

 string convert(string s, int numRows) {
        vector<string> str(numRows,"");
        int n=s.length();
        int i=0;
        
        while(i<n)
        {
            for(int ind=0;ind<numRows && i<n;ind++)
                str[ind].push_back(s[i++]);
            for(int ind=numRows-2;ind>=1&& i<n;ind--)
                str[ind].push_back(s[i++]);
        }
        
        string zigzag;
        for(string v:str)zigzag+=v;
        return zigzag;
    }

//java solution

String convert(String s, int numRows) {
        char[] c=s.toCharArray();
        int n=c.length;
        StringBuffer[] sb=new StringBuffer[numRows];
        for(int i=0;i<numRows;i++)sb[i]=new StringBuffer();
        
        int i=0;
        while(i<n)
        {
            for(int ind=0;ind<numRows && i<n;ind++)
                sb[ind].append(c[i++]);
            for(int ind=numRows-2;ind>=1 && i<n;ind--)
                sb[ind].append(c[i++]);
        }
        
        for(int idx=1;idx<sb.length;idx++)
        {
            sb[0].append(sb[idx]);
        }
        return sb[0].toString();
    }
