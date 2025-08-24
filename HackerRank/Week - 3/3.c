char* isValid(char* s) {
      static char yes[] = "YES";
    static char no[] = "NO";
    int freq[26] = {0};
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    
    int freqCount[100001] = {0};
    int distinctFreqs = 0;
    int maxFreq = 0;
    
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            if (freqCount[freq[i]] == 0) {
                distinctFreqs++;
            }
            freqCount[freq[i]]++;
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
            }
        }
    }
    
    if (distinctFreqs == 1) {
        return yes;
    } else if (distinctFreqs == 2) {
        int firstFreq = -1, firstCount = 0;
        int secondFreq = -1, secondCount = 0;
        for (int i = 1; i <= maxFreq; i++) {
            if (freqCount[i] > 0) {
                if (firstFreq == -1) {
                    firstFreq = i;
                    firstCount = freqCount[i];
                } else {
                    secondFreq = i;
                    secondCount = freqCount[i];
                }
            }
        }
        
        if ((firstCount == 1 && (firstFreq == 1 || firstFreq == secondFreq + 1)) || 
            (secondCount == 1 && (secondFreq == 1 || secondFreq == firstFreq + 1))) {
            return yes;
        }
    }
    
    return no;
}