int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3) {
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < h1_count; i++){
        sum1 += h1[i];
    }
    for (int i = 0; i < h2_count; i++){
        sum2 += h2[i];
    }
    for (int i = 0; i < h3_count; i++){
        sum3 += h3[i];
    }
    int i1 = 0, i2 = 0, i3 = 0;
    while (1) {
        if (i1 == h1_count || i2 == h2_count || i3 == h3_count) {
            return 0;
        }
        if (sum1 == sum2 && sum2 == sum3) {
            return sum1;
        }
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= h1[i1++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= h2[i2++];
        } else {
            sum3 -= h3[i3++];
        }
    }

}