//
// Created by lemito on 1/25/25.
//

#include "Builder.h"

#include <iostream>

int main(int argc, const char** argv) {
  // создаем билдера
  auto* mb = new MeowBuilder();
  // создаем прораба
  auto* dir = new Director();
  // назначаем подчиненного
  dir->setBuilder(mb);
  std::cout << "Examples" << std::endl;
  // люто работаем
  dir->buildM();
  const auto tmp1 = mb->flush();
  std::cout << *tmp1 << std::endl;
  dir->buildAll();
  const auto tmp2 = mb->flush();
  std::cout << *tmp2 << std::endl;
  return 0;
}