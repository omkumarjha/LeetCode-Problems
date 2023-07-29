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
    ListNode* removeElements(ListNode* head, int val) {
        // Edge case
        if(head == NULL){
            return head;
        }

        ListNode * dummy = new ListNode(-1); // refer example 3 , isliye use kiya takki agar 1st hi ko delete karna hoto.
        ListNode * prev = dummy;
        ListNode * temp = head;
        dummy -> next = head;

        while(temp != NULL){
            if(temp -> val == val){
                prev -> next =  temp -> next;
                ListNode * deleteNode = temp;
                temp = prev -> next;
                deleteNode -> next = NULL;
                delete deleteNode;
            }
            else{
                prev = temp;
                temp = temp -> next;
            }
        }

        return dummy -> next;
    }
};