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
    ListNode * middle(ListNode * head){
        ListNode * slow = head;
        ListNode * fast = head;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* deleteMiddle(ListNode* head){
        // Edge cases
        if(head == NULL){
            return head;
        }
        if(head -> next == NULL){
            ListNode * temp = head;
            delete temp;
            head = NULL;
            return head;
        }

        ListNode * middleNode = middle(head);

        ListNode * temp = head;
        while(temp -> next != middleNode){
            temp = temp -> next;
        }
        temp -> next = middleNode -> next;

        middleNode -> next = NULL;
        delete middleNode;

        return head;

    }

};