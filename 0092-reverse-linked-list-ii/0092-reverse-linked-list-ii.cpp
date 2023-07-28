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
    // Code to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        // Edge cases 
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode * temp = NULL;
        ListNode * curr = head;
        ListNode * prev = head;

        while(curr != NULL){
            curr = curr -> next;
            prev->next = temp;
            temp = prev;
            prev = curr;
        }

        return temp;
    }

/*
    // To understand below approach refer 1st example isme hum eak pointer 1 pe and doosra pointer 5 pe rakh rahe hai aur 1 ke next ko reversed list ke barabar kar rahe hai .

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode* current = head, *prev = NULL;

        // Below while loop se hum left value wale node pe curr ko rakh rahe hai and pichle wale node pe prev ko rakh rahe hai .
        int count = 1;
        while(count != left){
            prev = current;
            current = current->next;
            count++;
        }
        
        // Below while loop mai hum curr pointer ko right value wale node pe rakh rahe hai .
        ListNode* start = current;
        while(count != right){
            current = current->next;
            count++;
        }
        
        ListNode* rest = current->next;
        current->next = NULL; // null isliye kara takki left se right node tak hum reverse kar paye LL ko 
        
        ListNode* newHead = reverseList(start);
        if (prev!=NULL){
            prev->next = newHead;
        }
        current = newHead;
        while(current->next!=NULL){
            current= current->next;
        }
        current->next = rest;

        if(left == 1){  // it means reversed list ka head return kardo 
            return newHead;
        }
        else{
            return head;   // otherwise normal head return kardo
        }
        
    }
    */

    // Below approach ki TC bhi above ke tarah hi hai but isme effort kam lagta hai by AYUSHI SHARMA YT
    
    ListNode* reverseBetween(ListNode* head, int left, int right){

        ListNode * dummy = new ListNode(-1);  // dummy node humne isliye create kara takki last mai hume above approach ki tarah yeh na dekhna pade ki left==1 hai ya nhi so hum directly dummy-> next return kar sakte hai kyuki usme hume kuch bhi condition lagane ki jaroorat nhi padegi 
        
        dummy -> next = head;
        ListNode * prev = dummy;
        
        for(int i = 1; i < left; i++){
            prev = prev -> next;
        }

        ListNode * tail = prev->next;

        for(int i = 1; i <= (right-left); i++){
            ListNode * temp = prev->next;
            prev->next = tail -> next;
            tail->next = tail->next->next;
            prev->next->next = temp; 
        }


        return dummy->next;

    }

};