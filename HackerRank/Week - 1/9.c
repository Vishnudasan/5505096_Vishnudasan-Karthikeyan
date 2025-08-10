char* pangrams(char* s) {
    int alpha[26] = {0};
    int count = 0;
    for(int i = 0;s[i]!='\0';i++){
        if(isalpha(s[i])){
            char ch = tolower(s[i]);
            int idx = ch - 'a';
            if(alpha[idx]==0){
                alpha[idx] = 1;
                count++;
            }
        }
    }
    if (count==26) {
        return "pangram";
    }
    else {
        return "not pangram";
    }
}