//
// Created by lemito on 1/26/25.
//

#include "FactoryMethod.h"

int test(const double_t a, const int32_t b) {
  const Calculator* first = new Calculator1;
  auto res1 = first->MagicPow(a, b);
  std::println("Result = {}", res1);
  delete first;
  const Calculator* second = new Calculator2;
  auto res2 = second->MagicPow(a, b);
  std::println("Result = {}", res2);
  delete second;
  return 0;
}

int main() {
  test(5, 2);
  return 0;
}
