


typedef struct {
    int front;
    int rear;
    int *data;
    int size;
    int totalLength;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    q->totalLength = k;
    q->data= (int*)malloc(k*sizeof(int));

    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

    if(obj->size == obj->totalLength){
        return false;
    }
    if(obj->front == -1){
        obj->front++;
    }
    int idx = ++obj->rear;
    obj->data[idx] = value;
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {

    if(obj->size == 0){
        return false;
    }

    for(int i=obj->front+1; i<=obj->rear; i++){
        obj->data[i-1] = obj->data[i];
    }

    obj->rear--;
    obj->size--;
    return true;

}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->size == 0){
        return -1;
    }
    int idx = obj->front;
    return obj->data[idx];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->size == 0){
        return -1;
    }
    int idx = obj->rear;
    return obj->data[idx];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(obj->size == obj->totalLength){
        return true;
    }

    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/