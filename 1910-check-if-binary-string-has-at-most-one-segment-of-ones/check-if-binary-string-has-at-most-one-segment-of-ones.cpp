class Solution {
public:
    bool checkOnesSegment(string s) {
        bool zerofound = false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                zerofound = true;
            }
            if(zerofound && s[i]=='1'){
                return false;
            }
        }
       return true;
    }
};