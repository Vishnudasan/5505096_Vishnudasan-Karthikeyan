int findPrimeDates(int d1, int m1, int y1, int d2, int m2, int y2) {
    int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int count = 0;
    while (1) {
        int x = d1;
        x = x * 100 + m1;
        x = x * 10000 + y1;
        if (x % 4 == 0 || x % 7 == 0) 
            count++;
        if (d1 == d2 && m1 == m2 && y1 == y2)
            break;
        if ((y1 % 400 == 0) || (y1 % 4 == 0 && y1 % 100 != 0))
            month[1] = 29;
        else
            month[1] = 28;
        d1++;
        if (d1 > month[m1 - 1]) {
            d1 = 1;
            m1++;
            if (m1 > 12) {
                m1 = 1;
                y1++;
            }
        }
    }
    return count;
}