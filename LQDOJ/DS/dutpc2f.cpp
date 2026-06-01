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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<string, long long> mp;

  while (n--) {
    string a, b;
    long long c;
    cin >> a >> b >> c;

    mp[a] += c;
    mp[b] += c;
  }

  for (auto [name, total] : mp) {
    cout << name << ' ' << total << '\n';
  }

  return 0;
}
