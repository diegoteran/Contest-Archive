void Solution::arrange(vector<int> &A) {
    for (int i = 0; i < A.size(); i++) {
        if (A[i] < 0 || A[i] == i) continue;
        
        int temp = A[i];
        int j = i;
        int temp2;
        while (A[A[j]] >= 0) {
            temp2 = A[j];
            A[j] = -A[A[j]] - 1;
            j = temp2;
        }
        A[j] = -temp-1;
    }
    
    for (int i = 0; i< A.size(); i++)
        if (A[i] < 0)
            A[i] = -A[i] -1;
}