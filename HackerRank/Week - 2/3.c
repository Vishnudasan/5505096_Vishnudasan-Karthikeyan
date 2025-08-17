int pageCount(int n, int p) {
    int fromfront = p/2;
    int fromback = (n/2) - (p/2);
    return (fromfront < fromback) ? fromfront : fromback;

}