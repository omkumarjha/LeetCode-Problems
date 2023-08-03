class Solution {
public:

// Bahut similar question hai "largest rectange in histogram" wale se to isko samajhne se pehle go for that question.

   vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }

    int largestRectangleArea(vector<int> heights, int n) {

        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        // iss wale quetion mai sab same hai histogram wale question ke tarah bas yaha pe hum har piche wale row ko add kar rahe hai curr wale se aur uss combined ko hum historagm wale function mai pass kar rahe hai  Love babbar.

        // for first row 

        vector<int> rowElements(m);

        for(int j = 0; j < m; j++){
            int a=int(matrix[0][j] - '0');
            rowElements[j] = a;
        }

        //compute area for first row
        int area = largestRectangleArea(rowElements, m);
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++) {
                
                //row update: by adding previous row's value
                if(matrix[i][j] != '0'){
                    int a=int(matrix[i][j] - '0');
                    rowElements[j] += a;
                }
                else{
                    rowElements[j] = 0;
                }    
            }
            
            //entire row is updated now
            area = max(area, largestRectangleArea(rowElements,m));
            
        }
        return area;
    }
};