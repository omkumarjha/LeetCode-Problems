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
    ListNode * reverseLinkedList(ListNode * head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode * temp = NULL;
        ListNode * prev = head;
        ListNode * curr = head;

        while(curr != NULL){
            curr = curr -> next;
            prev -> next = temp;
            temp = prev;
            prev = curr;
        }
        return temp;
    }

    int lengthLinkedList(ListNode * head){
        ListNode * temp = head;
        int length = 0;

        while(temp != NULL){
            temp = temp ->  next;
            length++;
        }
        return length; 
    }

    // Below approach mai bas hum 1st poore list ko reverse kar rahe hai then first k ko reverse kar rahe hai then last elements ko reverse kar rahe hai 
    /*
    ListNode* rotateRight(ListNode* head, int k) {

        int length = lengthLinkedList(head);

        // Edge case
        if(head == NULL || head -> next == NULL || k % length == 0){
            return head;
        }

        ListNode * dummy = new ListNode(-1);
        dummy -> next = head;

        k = k % length;

        // reversing complete linked list
        ListNode * first = reverseLinkedList(head);
        dummy -> next = first;
        ListNode * temp = first;

        for(int i = 1; i < k && temp -> next != NULL; i++){
            temp = temp -> next;
        }

        ListNode * second = temp -> next;
        temp -> next = NULL;

        dummy ->next = reverseLinkedList(first);
        first -> next = reverseLinkedList(second);

        return dummy -> next;
    }
    */

    // yeh approach from Hello World YT isme jaise k ki value 2 hai then last k nodes ko hume starting se connect karna padega same yahi logic ko hum implement kar rahe hai .
    ListNode* rotateRight(ListNode* head, int k){

        int length = lengthLinkedList(head);

        // Edge case
        if(head == NULL || head -> next == NULL || k % length == 0){
            return head;
        }

        k = k % length;
        int loop = length - k;
        int j = 0;
        ListNode * temp = head;
        ListNode * firstNode = head;

        while(temp != NULL){
            j++;
            if(j == loop){
                firstNode = temp -> next;
                temp -> next = NULL;
                break;
            }
            temp = temp -> next;
        }
        
        temp = firstNode;

        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = head;

        return firstNode;

    }

};