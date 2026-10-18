#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  const int cPrecision = 10;
  int n;
  std::cin >> n;

  std::vector<double> sum(n + 1);
  for (int i = 0; i < n; i++) {
    double x;
    std::cin >> x;
    sum[i + 1] = sum[i] + std::log(x);
  }

  int q;
  std::cin >> q;
  std::cout << std::fixed;
  std::cout.precision(cPrecision);

  for (int i = 0; i < q; i++) {
    int l;
    int r;
    std::cin >> l >> r;
    double ans = std::exp((sum[r + 1] - sum[l]) / (r - l + 1));
    std::cout << ans << "\n";
  }
}
