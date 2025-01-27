//
// Created by lemito on 1/25/25.
//

#include "Builder.h"

#include <iostream>

int main() {
  // создаем билдера
  auto* mb = new MeowBuilder();
  // создаем прораба
  auto* dir = new Director<char>();
  // назначаем подчиненного
  dir->setBuilder(mb->setName("some name as parameter"));
  std::cout << "Examples" << std::endl;
  // люто работаем
  const auto tmp1 = dir->buildM();
  std::cout << *tmp1 << std::endl;
  delete tmp1;
  const auto tmp2 = dir->buildAll();
  std::cout << *tmp2 << std::endl;
  delete tmp2;
  delete dir;
  delete mb;
  return 0;
}