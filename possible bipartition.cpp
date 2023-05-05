// We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

// Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

// Example 1:

// Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: The first group has [1,4], and the second group has [2,3].
// Example 2:

// Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
// Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.


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
