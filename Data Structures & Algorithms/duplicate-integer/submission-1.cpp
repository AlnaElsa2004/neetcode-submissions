// class Solution {
// public:
//     bool hasDuplicate(vector<int>& nums) {
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]==nums[j]){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> seen(n);
        for(int i=0;i<n;i++){
           if(seen.find(nums[i])!=seen.end()){
            return true;
           }
           seen.insert(nums[i]);
        }
        return false;
    }
};