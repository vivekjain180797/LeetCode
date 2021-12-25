class Solution {
    
private :
    
    vector<int> topKFrequentUsingHeap(vector<int>& nums, int &k){
        unordered_map<int,int> count;
        for(auto num : nums){
            count[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(auto it : count){
            q.push({it.second,it.first});
            if(q.size()>k) q.pop();
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top().second);
            q.pop();
            if(res.size()==k) return res;
        }
        return res;
    }

     vector<int> topKFrequentUsingBucketSort(vector<int>& nums, int &k){
        unordered_map<int,int> count;
        for(auto num : nums){
            count[num]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        for(auto it: count){
            bucket[it.second].push_back(it.first);
        }
        vector<int> res;
        for(int i = bucket.size()-1; i>=0; --i){
            for(int j =0 ; j<bucket[i].size();++j){
                res.push_back(bucket[i][j]);
                if(res.size()==k) return res;
            }
        }
         return res;
     }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      return 1 ? topKFrequentUsingHeap(nums,k) : topKFrequentUsingBucketSort(nums,k);
    }
};