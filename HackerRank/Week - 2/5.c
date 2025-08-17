char* caesarCipher(char* s, int k) {
    int len = strlen(s);
    char* result = malloc((len+1)* sizeof(char));
    if (!result){
        exit(EXIT_FAILURE);
    }
    k = k % 26;
    for(int i=0; i<len; i++){
        char ch = s[i];
        if (isalpha(ch)){
            if(isupper(ch)){
                result[i] = ((ch - 'A' + k)%26)+ 'A';
            }
        else{
            result[i] = ((ch - 'a' + k)%26)+ 'a';
        }
        }
        else{
            result[i] = ch;
        } 
    }
    result[len] = '\0';
    return result;
}