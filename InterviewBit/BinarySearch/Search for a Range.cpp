vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int low = lower_bound(A.begin(), A.end(), B) - A.begin();
    int eq = lower_bound(A.begin(), A.end(), B+1) - A.begin();
    if (low == eq) low = eq = -1;
    else eq--;
    return {low, eq};
}