class Solution {
public:
bool isnotzero(int x){
    while(x>0){
    int lastdigit = x%10;
    if(lastdigit==0){
        return false;
    }
    x= x/10;}
    return true;
}
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        for(int i = 1; i< n ;i++){
          int a = i;
          int b = n-i;
          if(isnotzero(a) && isnotzero(b)){
            ans.push_back(a);
            ans.push_back(b);
            return ans;
          }
        }
        return ans;
    }
};