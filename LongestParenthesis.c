int longestValidParentheses(char* s) {
    
    int n = strlen(s);
    // printf("%d\n",n);
    int* arr  = (int*)malloc(n*sizeof(int));
    int top = -1;

    for(int i=0; s[i]!='\0'; i++){
        if(s[i] == '('){
            arr[++top] = i;
        }
        else{
            if(top == -1){ //means stack is empty
                arr[++top] = i;
            }
            else{
                if(s[arr[top]] == '('){
                    top -- ;
                }
                else{
                    arr[++top] = i;
                }
            }
        }
    }

    // for(int i= 0; i<=top; i++){
    //     printf("%d ",arr[i]);
    // }

    // printf("\n");

    int result[top+3];
    result[0] = -1;
    int j = 1;
    for(int i=0; i<=top; i++){
        result[j] = arr[i];
        j++;
    }

    result[top+2] = n;
    // for(int i=0; i<top+3; i++){
    //     printf("%d ",result[i]);
    // }

    int len = sizeof(result)/sizeof(int);
    // printf("\n");
    // printf("%d ",len);
    int max = 0;
    for(int i=0; i<len-1; i++){
        int diff = result[i+1]-result[i] -1;
        if(diff>max){
            max=diff;
        }
    }

    return max;
    


}