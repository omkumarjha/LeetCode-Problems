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
    // Yeh one of the approach hai jisme hum LL ki length calculate karke middle node pata kar rahe hai 
    /*
    ListNode* middleNode(ListNode* head) {
        // Edge case
        if(head->next == NULL){
            return head;
        }

        ListNode * temp = head;
        int length = 0;

        while(temp != NULL){
            length++;
            temp = temp -> next;
        }

        temp = head;

        int countToReach = (length/2) + 1;

        for(int i=1; i < countToReach; i++){
            temp = temp -> next;
        }

        return temp;

    }
    */

    // 2nd approach ex agar koi admi 2m se chal raha hai and 2nd person 1m se chal raha hai to after 10 min pehla wala banda 20m cover kar lega and doosra banda 10m cover karlega aur bilkul middle pe hogga . same goes with nodes traversal

    ListNode* middleNode(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode * slow = head;
        ListNode * fast = head->next;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next; 
            }

            slow = slow -> next;
        }
        return slow;
    }

};