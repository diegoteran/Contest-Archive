int segregate (vector<int> &arr) {
    int j = 0, i;
    for(i = 0; i < arr.size(); i++)
    {
       if (arr[i] <= 0)  
       {
           swap(arr[i], arr[j]);
           j++;  // increment count of non-positive integers
       }
    }
 
    return j;
}


int Solution::firstMissingPositive(vector<int> &A) {
    int first = segregate(A);
    for (int i = first; i < A.size(); i++) {
        if (first + abs(A[i]) <= A.size() && A[first + abs(A[i]) - 1] > 0)
            A[first + abs(A[i]) - 1] *= -1;
    }
    
    int i;
    for (i = first; i < A.size() && A[i] < 0; i++);
    
    return i - first + 1;
}