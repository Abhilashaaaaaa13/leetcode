class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int i =0;
     vector<vector<pair<int,double>>>adj(n);
     for(auto&vec : edges){
        int u = vec[0];
        int v = vec[1];
        double p = succProb[i];
        i++;
        adj[u].push_back({v,p});
        adj[v].push_back({u,p});
     }
     priority_queue<pair<double,int>>pq;
     vector<double>result(n,0);
     pq.push({1.0,start_node});
     while(!pq.empty()){
        auto[currprob,currnode] = pq.top();
        pq.pop();
        for(auto&temp : adj[currnode]){
            double adjprob = temp.second;
            int adjnode = temp.first;
            if(result[adjnode]<currprob*adjprob){
                result[adjnode] = currprob*adjprob;

                pq.push({result[adjnode],adjnode});
            }
        }
     }
     return result[end_node];
    }
};