class MyCircularDeque {
public:
    int *arr;
    int size;
    int front;
    int rear;

    MyCircularDeque(int k) {
        size = k;
        arr = new int[k];
        front = rear = -1;
    }
    
    bool insertFront(int value) {
        if((front == 0 && rear == size-1) || (rear == front-1)){ // when queue is full
            return false;
        }
        
        if(front == -1){ // iska matlab first time insertion ho raha hai 
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1){ // cyclic nature ko implement karne ke liye
            front = size-1;
        }
        else{
            front--;  // for remaining cases
        }
        arr[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if((front == 0 && rear == size-1) || (rear == front-1)){ // when queue is full
            return false;
        }
        
        if(front == -1){ // iska matlab first time insertion ho raha hai 
            front = rear = 0;
        }
        else if(rear == size-1  && front != 0){ // cyclic nature ko implement karne ke liye
            rear = 0;
        }
        else{
            rear++; // for remaining cases
        }
        arr[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if(front == -1){ // when queue is empty
            return false;
        }
        arr[front] = -1;

        if(front == rear){ // jab queue mai sirf eak hi element ho front = rear = 0
            front = rear = -1;
        }
        else if(front == size-1){ // To maintain cyclic order
            front = 0;
        }
        else{
            front++; // bakki saare cases ke liye
        }
        return true;
    }
    
    bool deleteLast() {
        if(front == -1){ // when queue is empty
            return false;
        }
        arr[rear] = -1;

        if(front == rear){ // jab queue mai sirf eak hi element ho front = rear = 0
            front = rear = -1;
        }
        else if(rear == 0){ // To maintain cyclic order
            rear = size -1;
        }
        else{
            rear--; // bakki saare cases ke liye
        }
        return true;
    }
    
    int getFront() {
        if(front == -1){ // when queue is empty
            return -1;
        }
        return arr[front];
    }
    
    int getRear() {
        if(front == -1){ // when queue is empty
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front == -1){ // when queue is empty
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if((front == 0 && rear == size-1) || (rear == front-1)){ // when queue is full
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */