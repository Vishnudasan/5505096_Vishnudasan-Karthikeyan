char* highestValuePalindrome(char* s, int n, int k) {
    char* str = strdup(s);
    bool* changed = calloc(n, sizeof(bool));
    int left = 0, right = n - 1, used = 0;

    while (left < right) {
        if (str[left] != str[right]) {
            if (k == 0) {
                free(changed);
                free(str);
                return "-1";
            }
            if (str[left] > str[right]) str[right] = str[left];
            else str[left] = str[right];
            changed[left] = changed[right] = true;
            k--;
            used++;
        }
        left++;
        right--;
    }

    left = 0, right = n - 1;
    while (left <= right && k > 0) {
        if (left == right) {
            if (str[left] != '9' && k > 0) {
                str[left] = '9';
                k--;
            }
        } 
        else {
              if (str[left] != '9') {
                if (changed[left] || changed[right]) {
                    if (k >= 1) {
                        str[left] = str[right] = '9';
                        k--;
                    }
                } else if (k >= 2) {
                    str[left] = str[right] = '9';
                    k -= 2;
                }
            }
        }
        left++;
        right--;
    }

    free(changed);
    return str;
}
