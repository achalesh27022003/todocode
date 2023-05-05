class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(n);
        for(auto it:dislikes){
            graph[it[0]-1].push_back(it[1]-1);
            graph[it[1]-1].push_back(it[0]-1);
        }
        vector<int>color(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                q.push(i);
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(auto it:graph[x]){
                        if(color[it]==-1){
                            color[it]=1-color[x];
                            q.push(it);
                        }
                        else if(color[it]==color[x]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
