int Solution::titleToNumber(string A) {
    int j;
    int res = 0;
    for (int i = A.size(), j = 0; i; i--, j++) {
        res += (A[i-1] - 'A' + 1)*(pow(26, j)); 
    }
    return res;
}