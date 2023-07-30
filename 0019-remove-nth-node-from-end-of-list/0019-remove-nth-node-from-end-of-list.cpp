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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Finding length of the linked list

        int length = 0;
        ListNode * temp = head;

        while(temp != NULL){
            temp = temp -> next;
            length++;
        }

        temp = head;
        ListNode * prev = NULL;
        for(int i = 1; i < (length-n+1); i++){
            prev = temp;
            temp = temp -> next;
        }

        // Now hum uss node pe hai jisko hume delete karna hai .

        // agar hume pehla hi node delte karna ho to 
        if(length == n){
            temp = head;
            head = head -> next;
            delete temp;
        }
        else{
            prev -> next = temp -> next;
            delete temp;
        }

        return head;

    }
};