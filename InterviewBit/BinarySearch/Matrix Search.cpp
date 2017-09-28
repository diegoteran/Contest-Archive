int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int N = A.size();
    int M = A[0].size();
    int low = 0, high = N;
    while (low != high) {
        int mid = (low+high)/2;
        if (A[mid][M-1] >= B)
            high = mid;
        else
            low = mid + 1;
    }
    if (low == N)
        return 0;
    
    int row = low;
    low = 0; high = M;
    while (low != high) {
        int mid = (low+high)/2;
        if (A[row][mid] >= B)
            high = mid;
        else
            low = mid + 1;
    }
    if (low == M)
        return 0;
    return (A[row][low] == B);
}