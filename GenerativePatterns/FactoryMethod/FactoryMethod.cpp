//
// Created by lemito on 1/26/25.
//

#include "FactoryMethod.h"

int test(double_t a, int32_t b) {
  Calculator* first = new Calculator1;
  auto res1 = first->MagicPow(a, b);
  std::println("Result = {}", res1);
  delete first;
  Calculator* second = new Calculator2;
  auto res2 = second->MagicPow(a, b);
  std::println("Result = {}", res2);
  delete second;
  return 0;
}

int main(int argc, char const* argv[]) {
  test(5, 2);
  return 0;
}
