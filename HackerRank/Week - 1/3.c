char* timeConversion(char* s) {
    static char result[16];
    int hour;

    sscanf(s, "%2d", &hour);
    if (s[8] == 'A') {
        if (hour == 12) 
            hour = 0;
    } else { // PM
        if (hour != 12)
             hour += 12;
    }
    snprintf(result, sizeof(result), "%02d:%c%c:%c%c", hour,s[3],s[4],s[6],s[7]);
    return result;
}
