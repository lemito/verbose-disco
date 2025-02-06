#include <iostream>
#include <ranges>
#include <vector>

int main() {
  std::vector<int> meow = {27, 02, 2005, 52, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto lambda = [&meow](int n) {
    int cnt = 0;
    for (auto& elem : meow) {
      if (n == elem) cnt++;
    }
    return cnt;
  };
  int cnt_of_two = lambda(2);
  std::cout << cnt_of_two << std::endl;
  auto n = meow | std::views::filter([](int n) { return n % 2 == 0; });
  for (auto& elem : n) {
    std::cout << elem << " " << std::endl;
  }

  return 0;
}
