/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.*/


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
