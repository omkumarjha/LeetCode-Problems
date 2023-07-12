//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int x,int y,vector<vector<int>> m,vector<vector<int>> visited,int n){
        if(x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1){
            return true;
        }
        return false;
    }
    void sourceToDestination(vector<vector<int>> m,int n,vector<string>& ans,vector<vector<int>> visited,int x,int y,string path){
        // base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1; // initially x,y cell ko hum visited mark kar denge 
        
        // Down ke liye 
        
        int newX = x+1;
        int newY = y;
        
        if(isSafe(newX,newY,m,visited,n)){
            path.push_back('D');
            sourceToDestination(m,n,ans,visited,newX,newY,path);
            path.pop_back();
        }
        
        // Left ke liye 
        
        newX = x;
        newY = y-1;
        
        if(isSafe(newX,newY,m,visited,n)){
            path.push_back('L');
            sourceToDestination(m,n,ans,visited,newX,newY,path);
            path.pop_back();
        }
        
        // Right ke liye 
        
        newX = x;
        newY = y+1;
        
        if(isSafe(newX,newY,m,visited,n)){
            path.push_back('R');
            sourceToDestination(m,n,ans,visited,newX,newY,path);
            path.pop_back();
        }
        
        // Up ke liye 
        
        newX = x-1;
        newY = y;
        
        if(isSafe(newX,newY,m,visited,n)){
            path.push_back('U');
            sourceToDestination(m,n,ans,visited,newX,newY,path);
            path.pop_back();
        }
        
        visited[x][y] = 0; // jab humne eak given cell ke liye top , bottom , left , right sab check kr lye woh kahi bhi nhi jaaa sakta then usko visited se hata do .
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans; // jo ke sare paths ko store karega 
        
        // Edge case
        if(m[0][0] == 0 || m[n-1][n-1] == 0){
            return ans;
        }
        
        vector<vector<int>> visited = m;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                visited[i][j] = 0; // visited wale 2D mai sare elements ko zero se mark kardiya hai .
            }
        }
        
        int srcx = 0;
        int srcy = 0;
        
        string path = "";
        
        sourceToDestination(m,n,ans,visited,srcx,srcy,path);
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends