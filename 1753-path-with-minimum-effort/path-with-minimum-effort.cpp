class Solution {
public:
vector<vector<int>>directions = {{-1,0},{0,-1},{1,0},{0,1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<tuple<int, int , int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto[effort,x,y] = pq.top();
            pq.pop();
            if(x==m-1 && y==n-1)
            return effort;
           for(auto dir:directions){
            int xnew = x+dir[0];
            int ynew = y+dir[1];
            if(xnew>=0 && ynew>= 0 && xnew<m && ynew<n){
              int maxdiff = abs(heights[xnew][ynew]-heights[x][y]);
              int maxeffort = max(maxdiff,effort);
              if(dist[xnew][ynew]>maxeffort){
                dist[xnew][ynew] = maxeffort;
                pq.push({maxeffort,xnew,ynew});
              }
            }
           }
        }
        return 0;
    }
};