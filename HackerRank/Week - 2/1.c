int sockMerchant(int n, int ar_count, int* ar) {
    int freq[101] = {0};
    int pairs = 0;
    
    for(int i = 0; i<ar_count; i++){
        freq[ar[i]]++;
    }
    for(int i = 0; i<101; i++){
        pairs += freq[i]/2;
    }
    return pairs;

}
