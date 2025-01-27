//
// Created by lemito on 1/25/25.
//

/*
простой пример - пусть продуктом будет класс, модержащий строку-слово.
Строитель1 строит слово MEOW. Потенциально, второй строит слово MICHAEL.
Director(бригадир) руководит порядком построения
*/

#ifndef BUILDER_H
#define BUILDER_H
#include <ostream>
#include <vector>

template <typename T>
class Word {
 public:
  std::string _name{};
  std::vector<T> _data;
  Word() = default;
  ~Word() = default;

  friend std::ostream &operator<<(std::ostream &os, const Word &obj) {
    for (auto &elem : obj._data) {
      os << elem << " ";
    }
    return os;
  }
};

// Строитель - абстрактный класс, ничего не делает, только описывает
class Builder {
 public:
  virtual ~Builder() = default;
  [[nodiscard]] virtual const Builder *AddM() const = 0;
  virtual Builder *setName(const std::string &name) = 0;
  // ...
};

class MeowBuilder final : public Builder {
  Word<char> *_obj{};
  void _create() { _obj = new Word<char>(); }

 public:
  MeowBuilder() { _create(); }
  ~MeowBuilder() override { delete _obj; }
  [[nodiscard]] const MeowBuilder *AddM() const override {
    _obj->_data.push_back('m');
    return this;
  }
  [[nodiscard]] const MeowBuilder *AddE() const {
    _obj->_data.push_back('e');
    return this;
  }
  [[nodiscard]] const MeowBuilder *AddO() const {
    _obj->_data.push_back('o');
    return this;
  }
  [[nodiscard]] const MeowBuilder *AddW() const {
    _obj->_data.push_back('w');
    return this;
  }

  MeowBuilder *setName(const std::string &name) override {
    this->_obj->_name = name;
    return this;
  }

  Word<char>* buildM() {
    AddM();
    return flush();
  }

  Word<char> *build() {
    AddM()->AddE()->AddO()->AddW();
    // AddE();
    // AddO();
    // AddW();
    return flush();
  }

  Word<char> *flush() {
    Word<char> *res = _obj;  // сохраняем указ
    _create();               // делаем сразу новый объект
    return res;
  }
};

// для покзательности -- может возвращаться и <int> и так далее
template <typename T>
class MichaelBuilder : public Builder {};

template <typename T>
class Director {
  Builder *builder = nullptr;

 public:
  void setBuilder(Builder *bld) { builder = bld; }
  Word<T> *buildM() {
    const auto tp = dynamic_cast<MeowBuilder *>(builder);
    return tp->buildM();
  };
  Word<T> *buildAll() const {
    const auto tp = dynamic_cast<MeowBuilder *>(builder);
    return tp->build();
  };
};

#endif  // BUILDER_H
