class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<double> s;
        vector<pair<int, int>> pair;
        for ( int i = 0; i < position.size();i++) {
            pair.push_back({position[i],speed[i]});
        }
        sort(pair.rbegin(),pair.rend());
        for ( auto & p : pair) {
            s.push_back((double)(target-p.first)/p.second);
            if ( s.size()>=2 && s.back() <= s[s.size()-2]){
                s.pop_back();
            }
        }
        return s.size();
    }
};
