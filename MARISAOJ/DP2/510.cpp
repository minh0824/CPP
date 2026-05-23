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

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n;
string s;
int a[nmax];
ll dp[nmax];

void preprocess() {
  cin >> s;
  n=sz(s);
  s=" "+s;
  for (int i = 1; i <= n; ++i) a[i]=s[i]-'0';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  preprocess();

  // goi dp[i] la so cach xu li tinh den ki tu thu i;
  // do ta xet 2 gia tri cong la x+y;
  // 0 <= x + y <= 18
  // do do ta can xet 2 th: neu s[i-1]=='1' && s[i-1]!='1';
  // voi sum <= 9 thi co sum+1 cach;
  // voi sum > 9 thi co 19-sum cach;
  dp[0]=1;
  for (int i = 1; i <= n; ++i) {
    int cur = a[i-1]*10+a[i];
    dp[i]+=dp[i-1]*(a[i]+1);
    if (cur>9&&cur<19) {
      dp[i]+=dp[i-2]*(19-(a[i-1]*10+a[i]));
    }
  }
  cout << dp[n];
  return 0;
}
