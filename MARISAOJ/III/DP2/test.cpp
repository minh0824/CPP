#include <iostream>
#include <math.h>
#include <cstring>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();

    if(n % 2 == 1){ cout << 0; return 0; }

    // dp[j] = so cach co balance j sau khi xu ly i ky tu
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        vector<long long> ndp(n + 1, 0);
        for(int j = 0; j <= n; j++){
            if(!dp[j]) continue;
            if(s[i] == '(' || s[i] == '?')
                if(j + 1 <= n)
                    ndp[j+1] = (ndp[j+1] + dp[j]) % MOD;
            if(s[i] == ')' || s[i] == '?')
                if(j - 1 >= 0)
                    ndp[j-1] = (ndp[j-1] + dp[j]) % MOD;
        }
        dp = ndp;
    }

    cout << dp[0] << '\n';
    return 0;
}
