//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k){
        vector<int> ans;
        
        int totalElements = n * m;
        int count = 0;

        int startingRow = 0;
        int endingRow = n - 1;
        int startingCol = 0;
        int endingCol = m - 1;

        while(count < totalElements){
            // Print starting row
            for(int i = startingCol; count < totalElements && i <= endingCol; i++){
                count++;
                if(count == k){
                    return a[startingRow][i];
                }
            }
            startingRow++;

            // Print ending col
            for(int i = startingRow; count < totalElements && i <= endingRow; i++){
                count++;
                if(count == k){
                    return a[i][endingCol];
                }
            }
            endingCol--;

            // Print ending row
            for(int i = endingCol; count < totalElements && i >= startingCol; i--){
                count++;
                if(count == k){
                    return a[endingRow][i];
                }
            }
            endingRow--;

            // Print starting col
            for(int i = endingRow; count < totalElements && i >= startingRow; i--){
               count++;
                if(count == k){
                    return a[i][startingCol];
                }
            }
            startingCol++;
        }
        
        return -1;
        
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends