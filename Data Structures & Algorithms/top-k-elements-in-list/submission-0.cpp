class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        //vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            
           int cnt = count(nums.begin(), nums.end(), nums[i]);
            mp[nums[i]]=cnt;
            
        }
        vector<int> arr;
        while(k--){
            int maxi=0;
            int element;
            for(auto x:mp){
                if(x.second>maxi){
                    maxi=x.second;
                    element=x.first;
                }
                
            }
            arr.push_back(element);
            mp.erase(element);
        }
        return arr;
    }
};
