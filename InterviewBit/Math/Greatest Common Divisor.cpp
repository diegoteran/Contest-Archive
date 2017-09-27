int Solution::gcd(int A, int B) {
    if (A <= B) swap(A, B);
    if (!B)
        return A;
    while (A > B) {
        A = A - B;
        if (A <= B) swap(A, B);
    }
    return A;
}