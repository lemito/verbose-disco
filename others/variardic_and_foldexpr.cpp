#include <concepts>
#include <iostream>
#include <type_traits>
/*
fold expr (свертка) - прикол С++20, который позволяет сокращать запись для множественных действий с бинарой операцией
https://en.cppreference.com/w/cpp/language/fold
*/

template <typename... Args>
void hello(Args&&... args) {
  (std::cout << ... << args);
}

template <typename T>
concept CanBeSummed = requires(T a, T b) {
  { a + b } -> std::convertible_to<T>;
} && std::is_arithmetic_v<T>;

template <CanBeSummed T, CanBeSummed... Args>
constexpr T sum(Args&&... args) {
  return (... + args);
}

auto main() -> int {
  hello(1, 3.14, "meow");
  hello("1", "3.14", "meow");
  const int t = sum<int>(1, 2, 3, 4, 5, 6);
  return 0;
}