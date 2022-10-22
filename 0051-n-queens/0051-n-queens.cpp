class Solution {
    void make_grid(vector<vector<int>>&g, int r, int c, int v){
        int n = g.size();
        for(int i=r+1; i<n; ++i)
            g[i][c] += v;
        for(int i=1; r+i<n and c+i<n; ++i)
            g[r+i][c+i] += v;
        for(int i=1; r+i<n and c-i>=0; ++i)
            g[r+i][c-i] += v;
    }
    
    void solve(vector<vector<int>>&g, int r, vector<vector<string>>&f){
        if(r==g.size()){
            vector<string> c;
            for(int i=0; i<g.size(); ++i){
                string s;
                for(int j=0; j<g.size(); ++j){
                    if(g[i][j]==1) s+="Q";
                    else s+=".";
                }
                c.push_back(s);
            }
            f.push_back(c);
            return ;
        }
        
        for(int i=0; i<g.size(); ++i){
            if(g[r][i]<0) continue;
        
            g[r][i] = 1;
            make_grid(g,r,i,-1);
            
            solve(g,r+1,f);
            
            make_grid(g,r,i,1);
            g[r][i] = 0;   
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> g(n, vector<int>(n,0));
        vector<vector<string>> ans;
        solve(g,0,ans);
        return ans;
    }
};