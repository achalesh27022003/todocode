
  
  
  
  class Solution {
public:
    int dfs(vector<int>&informtime,vector<int>adj[],int i){
        int time=0;
        for(int it:adj[i]){
            time=max(time,dfs(informtime,adj,it));
        }
        return informtime[i]+time;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        return dfs(informTime,adj,headID);
    }
};
