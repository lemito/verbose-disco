//
// Created by lemito on 1/26/25.
//

#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <cmath>
#include <print>

// Btn
class Dog {
 public:
  double_t length;
  explicit Dog(const double_t len) : length(len){};
  virtual ~Dog()= default;
  virtual void say_woof() const = 0;
};

// WinBtn
class Corgie final : public Dog {
 public:
  explicit Corgie(const double_t len = 30) : Dog(len){};
  ~Corgie() override = default;
  void say_woof() const override {
    std::println("Corgie with length = {} say `Woof`", length);
  };
};

// UnixBtn
class GermanSpitz final : public Dog {
 public:
  explicit GermanSpitz(const double_t len = 20) : Dog(len){};
  ~GermanSpitz() override = default;
  void say_woof() const override {
    std::println("GermanSpitz with length = {} say `Woof`", length);
  };
};

// Dialog
class Cat {
 public:
  bool wool = false;
  explicit Cat(const bool w = false) : wool(w){};
  virtual ~Cat()= default;
  virtual void say_meow() const = 0;
};

// WinDialog
class BritishShorthair final : public Cat {
 public:
  BritishShorthair() : Cat(true){};
  ~BritishShorthair() override = default;
  void say_meow() const override {
    std::println("BritishShorthair have wool = {} say `Meow`", wool);
  };
};

// UnixDialog
class Siamese final : public Cat {
 public:
  Siamese() : Cat(false){};
  ~Siamese() override = default;
  void say_meow() const override {
    std::println("Siamese have wool = {} say `Meow`", wool);
  };
};

class AbstractFactory {
 public:
  virtual ~AbstractFactory()= default;
  [[nodiscard]] virtual Dog* createDog() const = 0;
  [[nodiscard]] virtual Cat* createCat() const = 0;
};

// WinCmps
class Corgie_and_BritishShorthair final : public AbstractFactory {
 public:
  [[nodiscard]] Dog* createDog() const override { return new Corgie(); }
  [[nodiscard]] Cat* createCat() const override { return new BritishShorthair(); }
};

// UnixCmps
class GermanSpitz_and_Siamese final : public AbstractFactory {
 public:
  [[nodiscard]] Dog* createDog() const override { return new GermanSpitz(); }
  [[nodiscard]] Cat* createCat() const override { return new Siamese(); }
};

#endif  // ABSTRACTFACTORY_H
