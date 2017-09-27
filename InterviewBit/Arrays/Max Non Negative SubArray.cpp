vector<int> Solution::maxset(vector<int> &A) {
    A.push_back(-1);
    vector<int> res;
    long long max = -1;
    int maxLen = -1;
    vector<int> temp;
    long long sum = 0;
    int len = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] < 0) {
            if (sum >= max) {
                if (sum == max) {
                    if (len > maxLen) {
                        max = sum;
                        res = temp;
                        maxLen = len;
                    }
                } else {
                    max = sum;
                    res = temp;
                    maxLen = len;
                }
            }
            sum = 0;
            len = 0;
            temp.clear();
        } else {
            sum += A[i];
            temp.push_back(A[i]);
            len++;
        }
    }
    return res;
}