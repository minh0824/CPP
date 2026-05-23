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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  double a, b, c; cin >> a >> b >> c;
  double p = (a+b+c)/2;
  double S = sqrt(p*(p-a)*(p-b)*(p-c));
  cout << "chu vi: " << 2*p << endl;
  cout << "dien tich: " << S << endl;
  cout << "sin goc A: " << 2*S/(b*c);
  return 0;
}
