vector<vector<int> > Solution::generate(int A) {
    vector<vector<int> > res;
    if (A) {
        vector<int> v;
        v.push_back(1);
        res.push_back(v);
    }
    for (int i = 2; i <= A; i++) {
        vector<int> v;
        res.push_back(v);
        res[i-1].push_back(1);
        for (int j = 2; j < i; j++)
            res[i-1].push_back(res[i-2][j-2] + res[i-2][j-1]);
        res[i-1].push_back(1);
    }
    return res;
}