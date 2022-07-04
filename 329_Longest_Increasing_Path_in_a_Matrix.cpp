class Solution {
public:
    vector<int>a={-1,1,0,0};
    vector<int>b={0,0,-1,1};
    int dp[201][201];
    bool chck(vector<vector<int>>&m, int i, int j)
    {
        if(i<0 || j<0 || i==m.size() || j==m[0].size())
            return false;
        return true;
    }
    int dfs(vector<vector<int>>&m, int i, int j)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int x=i+a[k];
            int y=j+b[k];
            if(chck(m,x,y) && m[x][y]>m[i][j])
                dp[i][j]=max(dp[i][j],1+dfs(m,x,y));
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& m) 
    {
        int ans=1;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m.size();i++)
        {
            for(int j=0;j<m[0].size();j++)
            {
                ans=max(ans,dfs(m,i,j));
            }
        }
        return ans;
    }
};