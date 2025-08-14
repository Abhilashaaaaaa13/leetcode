class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for(int i =1 ;i<num.length()-1;i++){
            if( num[i]==num[i-1] && num[i]==num[i+1]){
            string sub = num.substr(i-1,3);
             if(sub>ans){
                ans = sub;
             }
            }
           
        }
        return ans;
    }
};