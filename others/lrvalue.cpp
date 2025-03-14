#include <iostream>

void meow(int &a) { std::cout << "a - lvalue\n"; }

void meow(int &&a) { std::cout << "a - rvalue\n"; }

// получаем lvalue но передаем как rvalue
void meow2(int &a) {
  std::cout << "meow2&:\n";
  meow(a);
  meow(std::forward<int>(a));
}

// получаем rvalue, но оно преобразуется в lvlue, перебрасываем как rvalue
void meow2(int &&a) {
  std::cout << "meow2&&:\n";
  meow(a);
  meow(std::forward<int>(a));
}

auto main() -> int {
  int a = 52;  // lvalue
  meow(a);
  meow(52);  // 52 - rvalue
  meow2(a);
  meow2(52);
}