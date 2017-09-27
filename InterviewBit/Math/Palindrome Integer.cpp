bool Solution::isPalindrome(int A) {
    if (A < 0)
        return false;
        
    int res = 0;
    for (int n = A; n; n/=10)
        res = res*10 + n%10;
        
    return A == res;
}