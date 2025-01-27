//
// Created by lemito on 1/26/25.
//

#include "AbstractFactory.h"

int test(AbstractFactory& fac) {
  Dog* dog = fac.createDog();
  Cat* cat = fac.createCat();
  dog->say_woof();
  std::print("\n");
  cat->say_meow();
  std::print("\n");
  delete dog;
  delete cat;
  return 0;
}

int main(int argc, char const* argv[]) {
  Corgie_and_BritishShorthair* cab = new Corgie_and_BritishShorthair();
  test(*cab);
  delete cab;
  GermanSpitz_and_Siamese* gas = new GermanSpitz_and_Siamese();
  test(*gas);
  delete gas;
  return 0;
}
