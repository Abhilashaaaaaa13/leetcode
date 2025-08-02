class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
       unordered_map<int,int>mp;
       int minelement = INT_MAX;
       for(int &x : basket1){
        mp[x]++;
        minelement = min(minelement,x);
       } 
       for(int &x : basket2){
        mp[x]--;
        minelement = min(minelement,x);
       }
      vector<int>finalist;
      for(auto &it : mp){
        int cost = it.first;
        int freq = it.second;

      
      if(freq ==0){
        continue;
      }
       if(freq%2 != 0){
        return -1;
       }
      for(int c = 1 ;c<=abs(freq/2) ;c++){
           finalist.push_back(cost); 
      }}
      sort(finalist.begin(), finalist.end());
      long long ans =0;
      for(int i =0 ;i< finalist.size()/2 ; i++) {
        ans += min(finalist[i], minelement*2);
      }
      return ans;
    }
};