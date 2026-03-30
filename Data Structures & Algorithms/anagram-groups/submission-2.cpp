class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         std::map<std::string,std::vector<std::string>> hash;
        for ( auto & s : strs) {
            std::vector<int> sign(26,0);
            for ( char c : s) {
                sign[c-'a']++;
            }
            string key = to_string(sign[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(sign[i]);
            }
            // std::string key = "";
            // for ( int i =0; i < 26; i++) {
            //     key += std::to_string(sign[i]);
            // }
            hash[key].emplace_back(s);
        }
        std::vector<std::vector<std::string>> ans;
        for ( auto & pair : hash)  {
            ans.emplace_back(pair.second);
        }
        return ans;
    }
};
