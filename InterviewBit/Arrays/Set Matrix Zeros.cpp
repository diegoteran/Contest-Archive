void Solution::setZeroes(vector<vector<int> > &A) {
    set<int> r, c;
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A[i].size(); j++)
            if (!A[i][j]) {
               r.insert(i);
               c.insert(j);
            }
                
    for (int rows = 0; rows < A.size(); rows++)            
        if (r.find(rows) != r.end())
            for (int i = 0; A.size() && i < A[0].size(); i++)
                A[rows][i] = 0;
    
    for (int columns = 0; A.size() && columns < A[0].size(); columns++)            
        if (c.find(columns) != c.end())    
            for (int i = 0; i < A.size(); i++)
                A[i][columns] = 0;
}