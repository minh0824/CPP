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

int freq[127];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  getline(cin, s);
  for (char i : s) {
    ++freq[i];
  }
  for (int i = 0; i < 256; ++i) {
    if (freq[i]>0) {
      cout << (char)i << ' ' << freq[i] << endl;
    }
  }
  return 0;
}
