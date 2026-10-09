#include <iostream>
#include <string>
#include <vector>

bool CanKeep(const std::string& s, const std::string& t,
             const std::vector<int>& remove_time, int count) {
  int n = static_cast<int>(s.size());
  int m = static_cast<int>(t.size());
  int j = 0;
  for (int i = 0; i < n && j < m; i++) {
    if (remove_time[i] > count && s[i] == t[j]) {
      j++;
    }
  }
  return j == m;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s;
  std::string t;
  std::cin >> s >> t;

  int n = static_cast<int>(s.size());
  std::vector<int> remove_time(n);
  for (int i = 1; i <= n; i++) {
    int p;
    std::cin >> p;
    remove_time[p - 1] = i;
  }

  int l = 0;
  int r = n;
  while (l < r) {
    int mid = l + (r - l + 1) / 2;
    if (CanKeep(s, t, remove_time, mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }

  std::cout << l << "\n";
}
