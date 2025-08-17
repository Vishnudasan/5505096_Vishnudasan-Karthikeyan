int superDigit(char* n, int k) {
    long long sum = 0;
    for (int i = 0; n[i] != '\0'; i++){
        sum += n[i] - '0';
    }
    sum *= k;
    
    while (sum >= 10){
        long long temp = 0;
        while(sum > 0){
            temp += sum%10;
            sum /= 10;
        }
        sum = temp;
    }
    return (int)sum;

}