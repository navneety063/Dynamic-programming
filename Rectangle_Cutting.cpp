#include<bits/stdc++.h>
using namespace std;
int solve(int a, int b)
{
    int dp[a+1][b+1];
 
    for(int height = 1; height <= a; height++)
    {
        for(int width = 1; width <= b; width++)
        {
            if(height == width)
                dp[height][width] = 0;
            else
            {
                int ans = 1e8;
                for(int i = 1; i < width; i++)
                    ans = min(ans, 1 + dp[height][width - i] + dp[height][i]);
                for(int i = 1; i < height; i++)
                    ans = min(ans, 1 + dp[height - i][width] + dp[i][width]);
                dp[height][width] = ans;
            }
        }
    }
 
    return dp[a][b];
}
 
int main() {
   long long t,n,m,x,i,j,k,q;
   t = 1;
   while(t--)
   {
        int a,b;
        cin >> a >> b;
        cout << solve (a,b);
   }
   return 0;
}