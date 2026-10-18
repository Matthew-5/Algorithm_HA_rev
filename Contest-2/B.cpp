#include <iostream>
#include <vector>

int main() {
  const int cMod = 10004321;
  const int cMulPrev = 123;
  const int cMulBefore = 45;
  const int cByteBits = 8;
  const int cByteValues = 256;

  int n;
  int k;
  int a0;
  int a1;
  std::cin >> n >> k >> a0 >> a1;

  std::vector<int> a(n);
  a[0] = a0;
  if (n > 1) {
    a[1] = a1;
  }
  for (int i = 2; i < n; i++) {
    long long value = static_cast<long long>(a[i - 1]) * cMulPrev +
                      static_cast<long long>(a[i - 2]) * cMulBefore;
    a[i] = value % cMod;
  }

  int prefix = 0;
  for (int shift = 2 * cByteBits; shift >= 0; shift -= cByteBits) {
    std::vector<int> count(cByteValues);
    for (int i = 0; i < n; i++) {
      if ((a[i] >> (shift + cByteBits)) == prefix) {
        int digit = (a[i] >> shift) & (cByteValues - 1);
        count[digit]++;
      }
    }

    for (int digit = 0; digit < cByteValues; digit++) {
      if (k > count[digit]) {
        k -= count[digit];
      } else {
        prefix = prefix * cByteValues + digit;
        break;
      }
    }
  }

  std::cout << prefix << "\n";
}
