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
    void insertAtTail(ListNode * &head,ListNode * &tail,int data){
        if(tail == NULL){
            tail = new ListNode(data);
            head = tail;
        }
        else{
            ListNode * temp = new ListNode(data);
            tail -> next = temp;
            tail = temp;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * sumListHead = NULL;
        ListNode * sumListTail = NULL;
        int carry = 0;

        ListNode * head1 = l1;
        ListNode * head2 = l2;

        while(head1 != NULL && head2 != NULL){
            int sum = (head1->val) + (head2->val) + carry;
            carry = sum / 10;
            sum = sum % 10;
            insertAtTail(sumListHead,sumListTail,sum);
            head1 = head1 -> next;
            head2 = head2 -> next;
        }

        // Traversing for first list remaining elements

          while(head1 != NULL){
            int sum = (head1->val) + carry;
            carry = sum / 10;
            sum = sum % 10;
            insertAtTail(sumListHead,sumListTail,sum);
            head1 = head1 -> next;
        }

         // Traversing for second list remaining elements

          while(head2 != NULL){
            int sum = (head2->val) + carry;
            carry = sum / 10;
            sum = sum % 10;
            insertAtTail(sumListHead,sumListTail,sum);
            head2 = head2 -> next;
        }

        // Agar koi carry ho to uske liye

        while(carry != 0){
            int sum = carry;
            carry = sum / 10;
            sum = sum % 10;
            insertAtTail(sumListHead,sumListTail,sum);
        }

        return sumListHead;
    }
};