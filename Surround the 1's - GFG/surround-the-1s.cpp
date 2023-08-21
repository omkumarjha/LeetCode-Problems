//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    
    int count_zero(int i, int j, int n, int m,vector<vector<int> >& matrix){
        int c=0;
        if(i-1>=0 and matrix[i-1][j]==0) c++; // up
        if(i-1>=0 and j-1>=0 and matrix[i-1][j-1]==0) c++; // left up diognal
        if(i-1>=0 and j+1<m and matrix[i-1][j+1]==0) c++; // right up diognal
        if(j-1>=0 and matrix[i][j-1]==0) c++; // left
        if(j+1<m  and matrix[i][j+1]==0) c++; // right
        if(i+1<n  and matrix[i+1][j]==0) c++; // down
        if(i+1<n  and j-1>=0 and matrix[i+1][j-1]==0) c++;// down left 
        if(i+1<n  and j+1<m and matrix[i+1][j+1]==0) c++;// down right
        
        return c;
    }
    
    int Count(vector<vector<int> >& matrix) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    int cnt=count_zero(i,j,n,m,matrix);
                if(cnt!=0 and cnt%2==0)
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends