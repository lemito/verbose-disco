//
// Created by lemito on 1/30/25.
//

#include "Prototype.h"

int main() {
  const auto Dog0 = std::make_unique<Dog>("Dog0");
  const auto Cat0 = std::make_unique<Cat>("Cat0");

  Dog0->sound();
  Cat0->sound();

  const auto Dog1 = Dog0->make_clone();
  Dog1->set_name("Dog1");
  const auto Cat1 = Cat0->make_clone();
  Cat1->set_name("Cat1");

  Dog1->sound();
  Cat1->sound();

  return 0;
}