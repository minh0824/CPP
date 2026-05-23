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

const long long MOD = 1e6 + 7;
using Mat = vector<vector<long long>>;

Mat matMul(const Mat& A, const Mat& B) {
  int sz = A.size();
  Mat C(sz, vector<long long>(sz, 0));
  for (int i = 0; i < sz; i++)
    for (int k = 0; k < sz; k++) {
      if (!A[i][k]) continue;
      for (int j = 0; j < sz; j++)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    }
  return C;
}

vector<int> decToBinary(string s) {
  vector<int> bits;
  while (s != "0") {
    int rem = 0; string next;
    for (char c : s) {
      rem = rem * 10 + (c - '0');
      if (!next.empty() || rem / 2) next += (char)('0' + rem / 2);
      rem %= 2;
    }
    bits.push_back(rem);
    s = next.empty() ? "0" : next;
  }
  return bits;
}

string subOne(string s) {
  int i = s.size() - 1;
  while (s[i] == '0') { s[i--] = '9'; }
  s[i]--;
  size_t st = s.find_first_not_of('0');
  return st == string::npos ? "0" : s.substr(st);
}

Mat matPow(Mat A, const string& p) {
  int sz = A.size();
  Mat R(sz, vector<long long>(sz, 0));
  for (int i = 0; i < sz; i++) R[i][i] = 1;
  if (p == "0") return R;
  for (int bit : decToBinary(p)) {
    if (bit) R = matMul(R, A);
    A = matMul(A, A);
  }
  return R;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string n; cin >> n;
  size_t st = n.find_first_not_of('0');
  n = st == string::npos ? "0" : n.substr(st);

  if (n == "0") return 0;
  if (n == "1") { cout << 1; return 0; }

  vector<long long> v = {1, 2, 1};
  Mat T = {{2,1,2},{2,2,1},{1,2,2}};
  Mat Tn = matPow(T, subOne(n));

  long long ans = 0;
  for (int i = 0; i < 3; i++)
    ans = (ans + Tn[0][i] * v[i]) % MOD;

  cout << ans;
}
