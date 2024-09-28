class MyCircularQueue {
public:
    int *arr;
    int k, front, rear, len;
    MyCircularQueue(int k) : k(k), front(0), rear(k-1), len(0) {
        arr = new int[k];
    }
    
    bool enQueue(int value) {
        if(len == k)
            return 0;
        
        rear = (rear == k-1) ? 0 : rear + 1;
        // rear = (rear + 1) % k
        arr[rear] = value;
        len++;
        return 1;
    }
    
    bool deQueue() {
        if(len == 0)
            return 0;

        front = (front == k-1) ? 0 : front + 1;
        len--;
        return 1;   
    }
    
    int Front() {
        return (len == 0) ? -1 : arr[front]; 
    }
    
    int Rear() {
        return (len == 0) ? -1 : arr[rear];
    }
    
    bool isEmpty() {
        return (len == 0);
    }
    
    bool isFull() {
        return (len == k);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */