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

    ListNode * middleNode(ListNode * head){
        ListNode * slow = head;
        ListNode * fast = head -> next;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }


    // We can solve it using 2 ways 
    /*
        1.ki LL ke elements ko array mai store kardo uske baad 2 pointer concept laga ke check karlo 
        2.Ki LL ka half part reverse karlo and yeh half kuch koi saa bhi ho sakta hai and then first half ko second se compare kara lo .
    */
    bool isPalindrome(ListNode* head) {
        ListNode * middle = middleNode(head);

        middle->next = reverseLinkedList(middle->next);

        ListNode * head1 = head;
        ListNode * head2 = middle->next;

        while(head2 != NULL){
            if(head1->val != head2->val){
                return false;
            }
            head1 = head1 -> next;
            head2 = head2->next;
        }

        return true;
    }
};