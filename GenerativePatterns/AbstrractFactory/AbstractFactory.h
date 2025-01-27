//
// Created by lemito on 1/26/25.
//

#include <cmath>
#include <print>
#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

// Btn
class Dog {
 public:
  double_t length;
  Dog(double_t len) : length(len){};
  virtual ~Dog(){};
  virtual void say_woof() const = 0;
};

// WinBtn
class Corgie : public Dog {
 public:
  Corgie(double_t len = 30) : Dog(len){};
  ~Corgie() override = default;
  void say_woof() const override {
    std::println("Corgie with length = {} say `Woof`", length);
  };
};

// UnixBtn
class GermanSpitz : public Dog {
 public:
  GermanSpitz(double_t len = 20) : Dog(len){};
  ~GermanSpitz() override = default;
  void say_woof() const override {
    std::println("GermanSpitz with length = {} say `Woof`", length);
  };
};

// Dialog
class Cat {
 public:
  bool wool = false;
  Cat(bool w = false) : wool(w){};
  virtual ~Cat(){};
  virtual void say_meow() const = 0;
};

// WinDialog
class BritishShorthair : public Cat {
 public:
  BritishShorthair() : Cat(true){};
  ~BritishShorthair() override = default;
  void say_meow() const override {
    std::println("BritishShorthair have wool = {} say `Meow`", wool);
  };
};

// UnixDialog
class Siamese : public Cat {
 public:
  Siamese() : Cat(false){};
  ~Siamese() override = default;
  void say_meow() const override {
    std::println("Siamese have wool = {} say `Meow`", wool);
  };
};

class AbstractFactory {
 public:
  virtual ~AbstractFactory(){};
  virtual Dog* createDog() const = 0;
  virtual Cat* createCat() const = 0;
};

// WinCmps
class Corgie_and_BritishShorthair : public AbstractFactory {
 public:
  Dog* createDog() const { return new Corgie(); }
  Cat* createCat() const { return new BritishShorthair(); }
};

// UnixCmps
class GermanSpitz_and_Siamese : public AbstractFactory {
 public:
  Dog* createDog() const { return new GermanSpitz(); }
  Cat* createCat() const { return new Siamese(); }
};

#endif  // ABSTRACTFACTORY_H
