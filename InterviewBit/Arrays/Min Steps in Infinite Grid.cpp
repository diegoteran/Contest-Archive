// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int res = 0;
    for (int i = 0; i < X.size()-1; i++) {
        int lenX = X[i] - X[i+1];
        int lenY = Y[i] - Y[i+1];
        res += max(abs(lenX), abs(lenY));
    }
    return res;
}
