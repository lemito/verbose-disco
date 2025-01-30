//
// Created by lemito on 1/26/25.
//

#include "AbstractFactory.h"

int test(const AbstractFactory& fac) {
  const Dog* dog = fac.createDog();
  const Cat* cat = fac.createCat();
  dog->say_woof();
  std::print("\n");
  cat->say_meow();
  std::print("\n");
  delete dog;
  delete cat;
  return 0;
}

int main() {
  const auto* cab = new Corgie_and_BritishShorthair();
  test(*cab);
  delete cab;
  const auto* gas = new GermanSpitz_and_Siamese();
  test(*gas);
  delete gas;
  return 0;
}
