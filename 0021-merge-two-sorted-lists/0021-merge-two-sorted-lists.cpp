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
    // Below approach mai maine bilkul waise hi kiya hai jaise hum merge two sorted array ko karte hai 
    /*
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
    */

    ListNode * mergeList(ListNode * first,ListNode * second){
        ListNode * curr1 = first;
        ListNode * next1 = curr1->next;

        ListNode * curr2 = second;
        ListNode * next2 = curr2->next;

        while(next1 != NULL && curr2 != NULL){
            if(curr2 -> val >= curr1->val && curr2->val <= next1->val){
                // Add node in between the node of first list
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;

                // Updating pointers
                curr1 = curr2;
                curr2 = next2;
            }
            else{
                // Go ahead one step in first list

                curr1 = next1;
                next1 = next1 -> next;

                if(next1 == NULL){
                    curr1 -> next = curr2;
                    return first;
                }
            }
        }
        if(next1 == NULL){
            curr1 -> next = curr2;
        }
        return first;
    }

    // Hum iss below love babbar approach mai sirf eak element ko pakad rahe hai aur check kar rhae hai ki woh kya first ke 2 nodes ke beech aa sakta hai agar ha to usko unke beech add kardenge agar nhi to uss element ko aage ke 2 nodes ke sath check karnge.
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        if(list1 -> val <= list2->val){
            return mergeList(list1,list2); // hum baad mai wahi list rakh rahe hai jiski value ko hume between compare karna hai
        }

        return mergeList(list2,list1);
    }

};