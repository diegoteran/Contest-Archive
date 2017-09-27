int arr[10000][10000];
int Solution::uniquePaths(int A, int B) {
    arr[0][1] = 1;
    for(int r = 1; r <= A; r++)
        for (int c = 1; c <= B; c++)
            arr[r][c] = arr[r-1][c] + arr[r][c-1];
            
    return arr[A][B];
}