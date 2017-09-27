vector<int> Solution::wave(vector<int> &A) {
    vector<int> res;
    sort(A.begin(), A.end());
    int len = A.size()/2;
    len *= 2;
    for (int i = 0; i < len; i+=2){
        res.push_back(A[i+1]);
        res.push_back(A[i]);
    }
    if (A.size()%2)
        res.push_back(A[A.size()-1]);
    return res;
}