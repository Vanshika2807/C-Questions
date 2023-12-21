#include "stdio.h"
#include "stdbool.h"

int postfixExpression(){
    
    int arr[50];
    char ch;
    int i=0;
    
    while(true){
        scanf("%c",&ch);
       if(ch == '?')break;
        if(ch == ' ' || ch == '\n'){
            continue;
        }
        if(ch == '+'){
            arr[i-2] = arr[i-1]+arr[i-2];
            i--;
            scanf("%c",&ch);
        }
        else if(ch == '-'){
            arr[i-2] = arr[i-2]-arr[i-1];
            i--;
            scanf("%c",&ch);
        }
        else if(ch == '*'){
            arr[i-2] = arr[i-1]*arr[i-2];
            i--;
            scanf("%c",&ch);
        }
        else if(ch == '/'){
            arr[i-2] = arr[i-2]/arr[i-1];
            i--;
            scanf("%c",&ch);
        }
        
        else if(ch >='0' && ch<='9' ){
            int no =0;
            while(ch != ' ' && ch!='?'){
                int a = ch - '0';
                no = no*10 + a;
                scanf("%c",&ch);
            }
            
            arr[i] = no;
            i++;
        }
        
    }
    
    return arr[0];
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        printf("%d\n",postfixExpression());
    }
    return 0;
}