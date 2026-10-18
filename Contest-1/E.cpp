#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::vector<int> b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::vector<int> d(n - 1);
  for (int i = 0; i < n - 1; i++) {
    d[i] = b[i] - a[i + 1];
  }

  int q;
  std::cin >> q;
  for (int j = 0; j < q; j++) {
    int x;
    std::cin >> x;

    int l = 0;
    int r = n - 2;
    int ans = n;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (d[m] <= x) {
        ans = m + 1;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    std::cout << ans << "\n";
  }
}
