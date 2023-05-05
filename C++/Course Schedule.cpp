class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        vector<int>indegree(n,0);
        for(auto it:pre){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        vector<int>bfs;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)bfs.push_back(i);
        }
        for(int i=0;i<bfs.size();i++){
            for(int it:adj[bfs[i]]){
                if(--indegree[it]==0)bfs.push_back(it);
            }
        }
        if(bfs.size()==n)return true;
        return false;
    }
};
