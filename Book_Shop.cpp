#include<bits/stdC++.h>
using namespace std;
#define ll long long 
#define fr(a,b) for(int i = a; i < b; i++)
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> price(n+1), pages(n+1);
        fr(1,n+1)
            cin >> price[i];
        fr(1,n+1)
            cin >> pages[i];
 
        int dp[n+1][x+1];
 
        for(int i = 0; i <= n; i++)
        {
            for(int money = 0; money <= x; money++)
            {
                if(money == 0 || i == 0)
                    dp[i][money] = 0;
                else
                {
                    int op1 = (i == 1) ? 0 : dp[i-1][money];
                    int op2 = (money < price[i]) ? 0 : pages[i] + dp[i-1][money - price[i]];
                    dp[i][money] = max(op1,op2);
                }
            }
        }
        cout << dp[n][x];
}