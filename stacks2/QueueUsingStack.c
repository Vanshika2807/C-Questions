


typedef struct {
    int size;
    int top;
    int *arr;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
    q->size= 0;
    q->top = -1;
    q->arr = (int*)malloc(100*sizeof(int)); //taken size = 100 as atmost 100 calls made
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    // if(obj->top == obj->(size-1)){
    //     return;
    // }

    obj->arr[++obj->top] = x;
    obj->size++;

}

int myQueuePop(MyQueue* obj) {
    int front = obj->arr[0];
    for(int i=1; i<obj->size; i++){
        obj->arr[i-1] = obj->arr[i];
    }

    obj->size--;
    obj->top--;
    return front;
}

int myQueuePeek(MyQueue* obj) {
    return obj->arr[0];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->size == 0;
}

void myQueueFree(MyQueue* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/