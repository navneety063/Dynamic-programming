#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long dp[n][n*n];
    dp[0][0] = 1;
    for(int i = 1; i < (n*n)/2; i++) dp[0][i] = 0;
    for(int i = 1; i <= n; i++){
        for(int x = 0; i <= (n*(n+1))/4; i++){
            dp[i][x] = (((x < i) ? 0 : dp[i-1][x-i]) + dp[i-1][x]) % 1000000007;
        }
    }
    if((n*(n+1)) % 4 != 0) cout<<0;
    cout<< dp[n][(n*(n+1))/4]/2;
}