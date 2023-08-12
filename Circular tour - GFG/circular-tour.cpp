//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

class Solution{
  public:

    int tour(petrolPump p[],int n){
        // Below approach brute force se better hai kyuki yaha pe hum front++ na karke front = rear + 1 kar rahe hai but still worst case mai iski TC 0(N2) ho jayegi to improve it , we use below approach jo one pass mai question solve kar deti hai 
        /*
        // yeh approacch  waise TLE mar jayegi but brute force se bhadiya hai yeh 
        int balance = 0;
        int front = 0 , rear = 0;
        
        while(front < n){
            balance = (balance + p[rear].petrol) - p[rear].distance;
            
            if(balance >= 0){
                rear++;
                rear = rear % n;
                    
                if(rear == front){
                    return front;
                }
            }
            else{
                balance = 0;
                front = rear + 1; // kyuki humne front = rear + 1 kara hai front++ kyu nhi to iske liye refer my copy
                rear = front;
            }
        }
        
        return -1;
        
        */
        
        // Below approach 0(n) ka hai by love babbr
        
        int kami = 0 , start = 0 , balance = 0;
        
        for(int i = 0; i < n; i++){
            balance = balance + p[i].petrol - p[i].distance;
            
            if(balance < 0){
                start = i + 1;
                kami = kami + balance; // kami ko add isliye karr rahe hai ex we have petrol pump from a to z to agar hum a se d nhi jaa paye to uska kami nikal liya then agar hum e se j nhi jaa paye to uska balance ko pichle kami se add kar denge takki abb combinely pata chal jaye ki a se j tak nhi pahuch paye kitne petrol ki kami ke wajah se 
                balance = 0;
            }
        }
        
        if(kami + balance >= 0){
            return start;
        }
        return -1;
  
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends