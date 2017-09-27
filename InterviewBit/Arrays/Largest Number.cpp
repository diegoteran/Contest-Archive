  int myCompare(string X, string Y) {
        // first append Y at the end of X
        string XY = X.append(Y);
 
        // then append X at the end of Y
        string YX = Y.append(X);
 
        // Now see which of the two formed numbers is greater
        return XY.compare(YX) < 0 ? 1: 0;
    }

string Solution::largestNumber(const vector<int> &A) {
    vector<string> B;
    for (int i = 0; i < A.size(); i++)
        B.push_back(to_string(A[i]));
    sort(B.begin(), B.end(), myCompare);
    string res = "";
    for (int i = B.size(); i; i--)
        res += B[i-1];
        
    if (res.length() > 1 && res[0] == '0')
        res = "0";
        
    return res;
}