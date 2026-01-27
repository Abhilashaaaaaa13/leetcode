class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int , int>>>adj(n);
        for(auto&e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        priority_queue<pair<int , int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int d = curr.first, node = curr.second;
            if(d>dist[node]) continue;
            for(auto& neigh:adj[node]){
                int nei = neigh.first, w = neigh.second;
                if(dist[nei]>d+w){
                    dist[nei] = d+w;
                    pq.push({dist[nei],nei});
                }
            }
        }
        return (dist[n-1]==INT_MAX ? -1 :dist[n-1]);
    }
};