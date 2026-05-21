class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
       stack<int> st;
       st.push(0);
       for(int i=1;i<n;i++){
        if(temperatures[i]<=temperatures[i-1]){
            st.push(i);
        }else{
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                int idx=st.top();
                st.pop();
                ans[idx]=i-idx;

            }
           st.push(i);
        }

       }
       return ans;
       
    }
};
