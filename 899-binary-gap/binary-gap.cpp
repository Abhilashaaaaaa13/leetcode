class Solution {
public:
    int binaryGap(int n) {
        int currpos = 0;
        int prevpos = -1;
        int maxdist = 0;
        while(n>0){
            if((n&1)==1){
                if(prevpos!= -1){
                    maxdist = max(maxdist,currpos-prevpos);
                    
                }
                prevpos = currpos;
            }
            n=n>>1;
            currpos++;
        }
        return maxdist;
    }
};