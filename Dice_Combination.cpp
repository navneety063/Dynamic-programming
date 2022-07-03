#include<bits/stdC++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int x = 1; x <= 6; x++){
            if(x > i) break;
            dp[i] = (dp[i] + dp[i-x]) % 1000000007;
        }
    }
    cout<<dp[n];
}