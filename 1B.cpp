#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  size_t n_elements;
  const int kNumberOfDigits = 10;
  std::cin >> n_elements;
  std::vector<double> plants(n_elements);
  std::vector<double> logs(n_elements);
  for (size_t i = 0; i != n_elements; ++i) {
    std::cin >> plants[i];
    logs[i] = log(plants[i]);
  }
  std::vector<double> pref_sum(n_elements + 1);
  pref_sum[0] = 0;
  for (size_t i = 1; i != n_elements + 1; ++i) {
    pref_sum[i] = pref_sum[i - 1] + logs[i - 1];
  }
  size_t q_queries;
  std::cin >> q_queries;
  for (size_t i = 0; i != q_queries; ++i) {
    double left_edge;
    double right_edge;
    std::cin >> left_edge >> right_edge;
    std::cout << std::fixed << std::setprecision(kNumberOfDigits)
              << exp(1 / (right_edge - left_edge + 1) *
                     (pref_sum[right_edge + 1] - pref_sum[left_edge]))
              << std::endl;
  }
  return 0;
}
