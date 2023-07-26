/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Isme basically hume original list de rakhi hai aur hume usse as it is copy karni hai new list mai par condition yeh hai ki copied list ka koi bhi pointer original list ko point na kar raha ho means copied list bilkul hi alag honi chahiye 

    // below approach TC - 0(n) , SC - 0(n) -- isme basically hum next pointers ko use karke clone bana lenge then fir uss clone wale list ke random pointers ko set kardenge map ka use karke

    void insertAtTail(Node * &head,Node * &tail,int data){
        if(tail == NULL){
            tail = new Node(data);
            head = tail;
        }
        else{
            Node * temp = new Node(data);
            tail -> next = temp;
            tail = temp;
        }
    }

    Node* copyRandomList(Node* head) {
        // step 1 -- clone the original list with next pointers
        Node * cloneHead = NULL;
        Node * cloneTail = NULL;

        Node * temp = head;

        while(temp != NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp = temp -> next;
        }
        
        // Step 2 -- original list ke har eak node ki mapping store kardo copied or clone list ke andar

        map<Node* , Node*> mp;

        Node * originalListPointer = head;
        Node * clonePointer = cloneHead;

        while(originalListPointer != NULL){
            mp[originalListPointer] = clonePointer;
            originalListPointer = originalListPointer -> next;
            clonePointer = clonePointer -> next;
        }

        // step 3 -- mapping ka use karke copies list ke random pointers ko set karo 

        originalListPointer = head;
        clonePointer = cloneHead;

        while(originalListPointer != NULL){
            clonePointer->random = mp[originalListPointer->random];
            originalListPointer = originalListPointer -> next;
            clonePointer = clonePointer -> next;
        }

        return cloneHead;

    }
};