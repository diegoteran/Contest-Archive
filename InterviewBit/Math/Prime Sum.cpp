bool isPrime(int n) {
    if (n <= 1)
        return 0;
    int maxCheck = (int)sqrt(n);
    for (int i = 2; i <= maxCheck; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

vector<int> Solution::primesum(int A) {
    vector<int> res;
    for (int i = 2; i <= A/2; i++)
        if (isPrime(i) && isPrime(A-i)) {
            res.push_back(i);
            res.push_back(A-i);
            return res;
        }
}