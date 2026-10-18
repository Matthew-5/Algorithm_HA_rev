#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  const int cBits = 64;
  const int cByteBits = 8;
  const int cByteValues = 256;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  std::vector<std::uint64_t> a(n);
  std::vector<std::uint64_t> temp(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  // Сортируем по байтам от младшего к старшему.
  for (int shift = 0; shift < cBits; shift += cByteBits) {
    // Подсчитываем числа с каждым значением текущего байта.
    std::vector<int> count(cByteValues);
    for (int i = 0; i < n; i++) {
      int digit = static_cast<int>((a[i] >> shift) & (cByteValues - 1));
      count[digit]++;
    }

    // Находим начало группы для каждого значения байта.
    std::vector<int> position(cByteValues);
    int total = 0;
    for (int digit = 0; digit < cByteValues; digit++) {
      position[digit] = total;
      total += count[digit];
    }

    // Раскладываем числа, сохраняя порядок внутри каждой группы.
    for (int i = 0; i < n; i++) {
      int digit = static_cast<int>((a[i] >> shift) & (cByteValues - 1));
      temp[position[digit]] = a[i];
      position[digit]++;
    }
    // Следующий проход работает с уже упорядоченным массивом.
    a.swap(temp);
  }

  for (int i = 0; i < n; i++) {
    std::cout << a[i] << "\n";
  }
}
