//
// Created by lemito on 1/25/25.
//

#include "Singleton.h"

#include <iostream>

using s_int = Singleton<int>;
using ptr_s_int = Singleton<int> *;

template <typename T>
Singleton<T> *Singleton<T>::instance = nullptr;

int test() {
  /**/
  auto meow = s_int::getPtr(27022005);
  std::cout << "data=" << meow->getData() << std::endl;
  /**/
  s_int::open().setData(52);
  std::cout << "data=" << s_int::open().getData() << std::endl;
  /**/
  auto obj = s_int::getPtr();
  obj->setData(51);
  std::cout << "data=" << obj->getData() << std::endl;
  /**/
  return 0;
}

int main() {
  test();
  return 0;
}
