class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string ,int> m;
        vector<vector<string>> ans;
        int idx = 0;
        for(auto st : strs){
            string s = st;
            sort(s.begin(),s.end());
            if(m.find(s)==m.end()){
                m[s] = idx++;
                ans.push_back({st});
            } else {
                ans[m[s]].push_back(st);
            }
        }
        
        return ans;
        
    }
};