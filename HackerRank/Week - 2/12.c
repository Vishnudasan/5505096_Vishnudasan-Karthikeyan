char* counterGame(long n) {
    static char louise[] = "Louise";
    static char richard[] = "Richard";
    
    int moves = 0;
    
    while(n>1){
        if((n & (n-1)) == 0){
            n >>=1;
        }
        else{
            long p = 1L << ((int)log2(n));
            n -= p;
        }
        moves ++;
    }
    return (moves % 2 == 1) ? louise:richard;

}