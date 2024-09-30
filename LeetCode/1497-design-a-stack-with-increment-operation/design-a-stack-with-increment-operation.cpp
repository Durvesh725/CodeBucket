class CustomStack {
public:
    int size,top;
    int *arr;
    CustomStack(int maxSize) : size(maxSize), top(-1) {
        arr = new int[size];
    }
    
    void push(int x) {
        if(top + 1 < size){
            top++;
            arr[top] = x;
        }
    }
    
    int pop() {
        if(top != -1){
            int val = arr[top];
            top--;
            return val;
        }
        return -1;
    }
    
    void shiftElements(stack<int> &helper, int &val){
        while(top != -1){
            int x = pop();
            x += val;
            helper.push(x);
        }

        while(!helper.empty()){
            push(helper.top());
            helper.pop();
        } 
    }

    void increment(int k, int val) {
        stack<int> helper;
        if(top + 1 < k){
            shiftElements(helper, val);
        }
        else{
            stack<int> buffer;
            int r = (top + 1) - k;

            while(r){
                buffer.push(arr[top]);
                top--;
                r--;
            }

            shiftElements(helper, val);

            while(!buffer.empty()){
                push(buffer.top());
                buffer.pop();
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */