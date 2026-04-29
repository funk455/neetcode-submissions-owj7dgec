class Solution {
public:
    // Map each course to its prerequisites
    unordered_map<int, vector<int>> preMap;
    // Store all courses along the current DFS path
    unordered_set<int> visiting;
    unordered_set<int> visited;
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }
        
        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) 
                return {};
        }
        if (res.size()!=numCourses){
            return {};
        }
        return res;
    }

    bool dfs(int crs) {
        if (visiting.count(crs)) {
            // Cycle detected
            return false;
        }
        if (visited.count(crs)) {
            return true;
        }
        visiting.insert(crs);
        for (int pre : preMap[crs]) {
            if (!dfs(pre)){
                return false;
            }
        }
        //成功处理节点
        visiting.erase(crs);
        visited.insert(crs);
        res.push_back(crs);
        return true;
    }
};
