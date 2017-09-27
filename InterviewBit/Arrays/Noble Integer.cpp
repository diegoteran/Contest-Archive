int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    int res = -1;
    for (int i = 0; i < A.size(); i++) {
        int j = 0;
        for (int k = i+1; k < A.size() && A[k]==A[i]; k++, j++);
        if (A[i] == A.size()-i-1-j)
            res = 1;
    }
    return res;
}