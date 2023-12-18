char* removeDuplicateLetters(char* s) {

    int count[26] = {0};
    bool isTaken[26] = {false};
    char stack[26]; //this is just for storing characters once
    int top = -1;
    
    for(int i=0 ; s[i]!='\0'; i++){
        count[s[i]-'a']++;
    }

    for(int i=0; s[i]!='\0'; i++){

        count[s[i] - 'a']--;

        if(isTaken[s[i]-'a'])continue;

        while(top>=0 && s[i]<stack[top]  && 
              count[stack[top] - 'a'] > 0){

            isTaken[stack[top] - 'a'] = false;
            top -- ;
        }

        stack[++top] = s[i];
        isTaken[s[i]-'a'] = true;
    }

    char *result = (char*)malloc((top+2)*sizeof(char));
    for(int i=0; i<=top; i++){
        result[i] = stack[i];
    }

    result[top+1] = '\0';
    return result;
};