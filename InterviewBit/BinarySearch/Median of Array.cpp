double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int lenA = A.size(), lenB = B.size();
    bool odd = (lenA + lenB)%2;
    int lo, hi, median = (lenA + lenB)/2;
    double res;
    if (!lenA) {
        res = B[median];
        if (!odd)
            res = (double)(res + B[median-1])/2;
        return res;
    }
    if (!lenB) {
        res = A[median];
        if (!odd)
            res = (double)(res + A[median-1])/2;
        return res;
    }
        
    lo = 0; hi = lenA;
    while (lo != hi) {
        int mid = (lo + hi)/2;
        if (mid + (lower_bound(B.begin(), B.end(), A[mid]) - B.begin()) >= median)
            hi = mid;
        else
            lo = mid + 1;
    }
    vector<int> s, b;
    if (lo == lenA) {
        s.push_back(A[lo-1]);
        if (median - lo -1 >= 0)
            s.push_back(B[median-lo-1]);
        b.push_back(B[median-lo]);
    } else {
        b.push_back(A[lo]);
        if (lo)
            s.push_back(A[lo-1]);
        if (lenB > median - lo - 1 && median - lo - 1 >= 0)
            s.push_back(B[median - lo - 1]);
        if (lenB > median - lo && median - lo >= 0)
            b.push_back(B[median-lo]);
    }
    sort(b.begin(), b.end());
    sort(s.begin(), s.end());
    res = b[0];
    if (!odd)
        res = (res + s[s.size()-1])/2;
    return res;
}