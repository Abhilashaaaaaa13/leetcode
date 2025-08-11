class Solution {
public:
vector<int>getvecount(int n){
    vector<int>vec(10,0);
    while(n){
        vec[n%10]++;
        n/=10;
    }
    return vec;
}
    bool reorderedPowerOf2(int n) {
        vector<int>input = getvecount(n);
        for(int p =0 ; p<=29; p++){
        if(input == getvecount(1<<p)){
            return true;
        }
        }
        return false;
    }
};