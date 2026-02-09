class Solution {
public:
    int minimumDeletions(string s) {
    int bcount = 0;
    int deletion = 0;
    for(int i =0;i<s.length();i++){
        if(s[i]=='b'){
            bcount++;
        }
        else{
            deletion = min(deletion+1,bcount);
        }
    } 
    return deletion;
    }
};