int Solution::pow(int x, int n, int d) {
    long long res = (x != 0);
    long long y = x;
    while (n) {
        if (n%2)
            res = (res*y)%d;
        y = (y*y)%d;
        n /= 2;
    }
    if (res < 0) res += d;
    return res;
}