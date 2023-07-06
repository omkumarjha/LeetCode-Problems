class Solution {
public:
    void merge(vector < int > & arr, int n,int start,int end){
        int mid = start + (end - start)/2;

        int len1 = mid - start + 1;
        int len2 = end - mid;

        int *first = new int[len1];
        int *second = new int[len2];

        // copy 
        int mergeIndex = start;
        for(int i = 0; i < len1; i++){
            first[i] = arr[mergeIndex++];
        }

        mergeIndex = mid + 1;
        for(int i = 0; i < len2; i++){
            second[i] = arr[mergeIndex++];
        }

        // Now merge those two sorted arrays

        int i = 0 , j = 0;
        mergeIndex = start;

        while(i < len1 && j < len2){
            if(first[i] < second[j]){
                arr[mergeIndex++] = first[i++];
            }
            else{
                arr[mergeIndex++] = second[j++];
            }
        }

        while(i < len1){
            arr[mergeIndex++] = first[i++];
        }
        while(j < len2){
            arr[mergeIndex++] = second[j++];
        }

        delete []first;
        delete []second;
}

void merging(vector < int > & arr, int n,int start,int end){
    // base case
    if(start >= end){
        return;
    }
    else{
        int mid = start + (end - start)/2;

        // left part ko sort karo
        merging(arr,n,start,mid);

        // right part ko sort karo
        merging(arr,n,mid+1,end);

        // ab woh dono sorted parts ko merge karke arr mai assign kardo
        merge(arr,n,start,end);
    }
    
}


    vector<int> sortArray(vector<int>& nums) {
        merging(nums,nums.size(),0,nums.size()-1);
        return nums;
    }
};