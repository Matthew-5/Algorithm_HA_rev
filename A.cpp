#include <iostream>
#include <vector>

struct Segment {
  int l;
  int r;
};

void MergeSort(std::vector<Segment>& segments, std::vector<Segment>& temp,
               int left, int right) {
  if (right - left <= 1) {
    return;
  }

  int middle = left + (right - left) / 2;
  MergeSort(segments, temp, left, middle);
  MergeSort(segments, temp, middle, right);

  int i = left;
  int j = middle;
  for (int k = left; k < right; k++) {
    if (j == right || (i < middle && segments[i].l <= segments[j].l)) {
      temp[k] = segments[i];
      i++;
    } else {
      temp[k] = segments[j];
      j++;
    }
  }

  for (int k = left; k < right; k++) {
    segments[k] = temp[k];
  }
}

int main() {
  int n;
  std::cin >> n;

  std::vector<Segment> segments(n);
  for (int i = 0; i < n; i++) {
    std::cin >> segments[i].l >> segments[i].r;
  }

  std::vector<Segment> temp(n);
  MergeSort(segments, temp, 0, n);

  std::vector<Segment> ans;
  for (int i = 0; i < n; i++) {
    if (ans.empty() || segments[i].l > ans.back().r) {
      ans.push_back(segments[i]);
    } else if (segments[i].r > ans.back().r) {
      ans.back().r = segments[i].r;
    }
  }

  std::cout << ans.size() << "\n";
  for (int i = 0; i < static_cast<int>(ans.size()); i++) {
    std::cout << ans[i].l << " " << ans[i].r << "\n";
  }
}
