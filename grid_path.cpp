#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

int main(){
    int n;
    cin >> n;
    vector<vector<char>> grid(n+1,vector<char>(n+1));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1 and j == 1) dp[i][j] = 1;
            else{
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod ;
                if(grid[i][j] == '*') dp[i][j] = 0;
            }
        }
    }
    if(grid[1][1] == '*') cout<< 0 <<endl;
    else cout<<dp[n][n]<<endl;
}