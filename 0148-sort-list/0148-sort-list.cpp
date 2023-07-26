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
        ListNode * fast = head->next;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode * merge(ListNode * left , ListNode * right){
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        
        // yaha pe maine dummy node create kar diya jaha pe ans aur temp dono point kar rahe hai and finally mai temp ko move karte rahoonga aur jab node merge ho jayenge to ans -> next return kardoonga
        ListNode * ans = new ListNode(-1);
        ListNode * temp = ans;


        while(left != NULL && right != NULL){
            if(left->val < right->val){
                temp -> next = left;
                temp = left;
                left = left -> next;
            }
            else{
                temp -> next = right;
                temp = right;
                right = right -> next;
            }
        }

        while(left != NULL){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }

        while(right != NULL){
            temp -> next = right;
            temp = right;
            right = right -> next;
        }

        return ans->next;

    }

    ListNode* sortList(ListNode* head) {

        // Base case
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        ListNode * midNode = middle(head);

        ListNode * left = head;
        ListNode * right = midNode -> next;

        midNode -> next = NULL;

        // Recursively sort left and right part 
        left = sortList(left);
        right = sortList(right);

        // Now merge left and right sorted part 

        ListNode * result = merge(left,right);
        
        return result;
    }
};