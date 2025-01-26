//
// Created by lemito on 1/26/25.
//

#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include <cmath>
#include <cstdint>
#include <print>

// это класс, который будет рождаться методом
class powerator {
 public:
  virtual ~powerator() = default;
  [[nodiscard]] virtual constexpr double_t Pow(
      double_t a, int32_t b) const = 0;  // некая полезная функция
};

class cmath_powerator final : public powerator {
  [[nodiscard]] constexpr double_t Pow(const double_t a, const int32_t b) const override {
    return pow(a, b);
  }
};

class my_powerator final : public powerator {
  [[nodiscard]] constexpr double_t Pow(double_t a, int32_t b) const override {
    if (b == 0) return 1;
    if (b < 0) {
      a = 1 / a;
      b = -b;
    }
    double_t res = 1;
    while (b > 0) {
      if (b & 1) {
        res *= a;
      }
      a *= a;
      b >>= 1;
    }
    return res;
  }
};

// главный класс, в котором содержиться метод-factory
class Calculator {
 public:
  virtual ~Calculator() = default;
  [[nodiscard]] virtual powerator* factory()
      const = 0;  // собственно, сам метод фабрики, создающий некий объект
  [[nodiscard]] double_t MagicPow(const double_t a, const int32_t b) const {
    // std::println("Meow");
    const powerator* obj = this->factory();
    const auto res = obj->Pow(a, b);  // вот тут этот объект выполняет функцию
    delete obj;
    return res;
  };
};

// реализации классов под конкретную реализацию фабрик (типов)
class Calculator1 final : public Calculator {
  [[nodiscard]] powerator* factory() const override { return new cmath_powerator(); }
};

class Calculator2 final : public Calculator {
  [[nodiscard]] powerator* factory() const override { return new my_powerator(); }
};

#endif  // FACTORYMETHOD_H
