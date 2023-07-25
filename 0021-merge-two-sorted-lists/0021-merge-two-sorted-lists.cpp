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
    void insertAtTail(ListNode* &tail,ListNode * &head,int data){
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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * mergedListHead = NULL;
        ListNode * mergedListTail = mergedListHead;

        ListNode * list1Pointer = list1;
        ListNode * list2Pointer = list2;

        while(list1Pointer != NULL && list2Pointer != NULL){
            int value1 = list1Pointer->val;
            int value2 = list2Pointer -> val;

            if(value1 < value2){
                insertAtTail(mergedListTail,mergedListHead,value1);
                list1Pointer = list1Pointer-> next;
            }
            else{
                insertAtTail(mergedListTail,mergedListHead,value2);
                list2Pointer = list2Pointer-> next;
            }
        }

        while(list1Pointer != NULL){
            int value1 = list1Pointer -> val;
            insertAtTail(mergedListTail,mergedListHead,value1);
            list1Pointer = list1Pointer-> next;
        }

        while(list2Pointer != NULL){
            int value2 = list2Pointer -> val;
            insertAtTail(mergedListTail,mergedListHead,value2);
            list2Pointer = list2Pointer-> next;
        }

        return mergedListHead;
    }
};