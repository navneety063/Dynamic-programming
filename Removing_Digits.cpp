#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,INT_MAX);
    for(int i = 1 ; i <= 9 ; i++){
        dp[i] = 1;
    }
    for(int i = 10; i <= n; i++){
        int t = i;
        while(t != 0){
            int x = t % 10;
            t = t / 10;
            if(x == 0) continue;
            dp[i] = min(dp[i],1+dp[i-x]);
        }
    }
    cout<<dp[n];
}