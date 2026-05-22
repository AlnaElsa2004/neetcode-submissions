class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> right(n);
        vector<int> left(n);
        stack<int> st;
        stack<int> st2;
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            right[i]=st.empty()?n:st.top();
             st.push(i);
        }
       for(int i=0;i<n;i++){
        while(!st2.empty() && heights[st2.top()]>=heights[i]){
            st2.pop();
        }
        left[i]=st2.empty()?-1:st2.top();
        st2.push(i);
       }
       for(int i=0;i<n;i++){
        int area=heights[i]*(right[i]-left[i]-1);
        maxi=max(maxi,area);
       }
       return maxi;
    }
};
