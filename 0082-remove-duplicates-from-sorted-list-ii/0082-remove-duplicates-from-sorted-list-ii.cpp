/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Edge cases
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode * dummy = new ListNode(-1); // dummy node ki importance ko samajhne ke liye example 1 and 2 ko dry run karo. hum prev ko NULL rakhkar bhi kar sakte hai but usme hume bahut conditions lagani padegi so dummy node is a better alternative. ARUSHI SHARMA YT 
        dummy -> next = head;
        ListNode * prev = dummy;
        ListNode * curr = head;

        while(curr != NULL){
            if(curr -> next != NULL && curr->val == curr->next->val){
                while(curr -> next != NULL && curr->val == curr->next->val){
                    curr = curr -> next;
                }
                prev->next = curr->next;
            }
            else{
                prev = prev -> next;
            }
            curr = curr -> next;
        }

        return dummy -> next;
        
    }
};