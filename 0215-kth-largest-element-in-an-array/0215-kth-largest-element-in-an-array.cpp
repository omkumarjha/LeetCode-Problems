class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int element ;

        priority_queue <int> pq; // Max Heap 

        // Stored values of array into Max heap 
        for(auto num : nums){
            pq.push(num);
        }

        // Then jaise hi k == 0 ho jaata hai to element return kardenge 
        while(k){
            element = pq.top();
            pq.pop();
            k--;
        }

        return element;
    }
};