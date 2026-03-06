class Solution {
public:
double dfs(string src, string dest , double product,unordered_set<string>&vis, unordered_map<string,vector<pair<string,double>>>&graph){
    if(src==dest)return product;
    vis.insert(src);
    for(auto&nbr:graph[src]){
        string next = nbr.first;
        double val = nbr.second;
        if(!vis.count(next)){
          double res = dfs(next,dest,product*val,vis,graph);
          if(res != -1){
            return res;
          }
        }
    }
    return -1;
}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>graph;
        for(int i=0;i<equations.size();i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b,val});
            graph[b].push_back({a,1/val});
        }
        vector<double>ans;
        for(auto& q:queries){
          string src = q[0];
          string dest = q[1];
          if(!graph.count(src) || !graph.count(dest)){
            ans.push_back(-1);
            continue;
          }
          unordered_set<string>vis;
         
            ans.push_back(dfs(src,dest,1,vis,graph));
          
        }
        return ans;
    }
};