class Solution {
public:
vector<int> nextelement(vector<int>& heights, int n){
    // iska logic next smaller element ke tarah hi hoga
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);

    for(int i = n-1; i >= 0; i--){
        int curr= heights[i];

        while(st.top()!=-1 && heights[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i); // yaha pe stack ke andar hum element nhi indexes ko store kar rahe hai 
    }
    return ans;
}

vector<int> prevelement(vector<int>& heights, int n ){
// iska logic previous smaller element ke tarah hi hoga
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);

    for(int i = 0; i < n; i++){
        int curr= heights[i];

        while(st.top()!=-1 && heights[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i); // yaha pe stack ke andar hum element nhi indexes ko store kar rahe hai 
    }
    return ans;
}

public:
    int largestRectangleArea(vector<int>& heights){
        // iska logic iss tarah se hai ki hum har eak baar ko tab tak extend kar sakte hai jab tab aage wale baar ki height uske barabar ho ya fir usse greater, every baar ko prev mai and next mai extend karte hue yahi logic lagega. 
        // iss question mai baar ki height to constant hai to apne ko poora focus width nikalne pe hi karna hai tabhi to apne ko maximum area mil payega sare rectanges mai se

       int n =heights.size();
       int area= INT_MIN;

       vector<int>next(n);
       vector<int>prev(n);

       next=nextelement(heights,n); 
       prev=prevelement(heights,n); 

       for(int i = 0; i < n; i++){

           int l = heights[i];
           if(next[i] == -1){ // ex jab sare baar ki heights 2 ho tab to area ke liye next[i] ya fir prev[i] ko n rakhlo and maximum area aa jayega usss situation mai
               next[i]=n;
           }

           int b = next[i]-prev[i]-1;
           int newarea= l*b;
           area=max(area,newarea);
       }
       return area;
    }
};