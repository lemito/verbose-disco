//
// Created by lemito on 1/25/25.
//

#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
class Singleton {
  /* объект, который будем создавать; static, т.к. единое поле для всего класса
   * (даже если объект разный) */
  static Singleton<T> *instance;
  T _data;  // полезная нагрузка

  Singleton() = default;

 public:
  Singleton(T &data) {
    instance = nullptr;
    _data = data;
  };
  virtual ~Singleton() { delete instance; };
  /*баним правило 3*/
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;

  static Singleton &open();  // получаем поле inctance отсюда (как ссылку)
  static Singleton<T> *
  getPtr();  // получаем поле inctance отсюда (как указатель)
  /*с нач значением*/
  static Singleton &open(T &val);  // получаем поле inctance отсюда (как ссылку)
  static Singleton<T> *getPtr(
      T &val);  // получаем поле inctance отсюда (как указатель)
  static Singleton &open(T val);  // получаем поле inctance отсюда (как ссылку)
  static Singleton<T> *getPtr(
      T val);  // получаем поле inctance отсюда (как указатель)

  T getData() const;  // обычный геттер
  /*
  обычные сеттеры
  */
  void setData(T &data) { _data = data; }
  void setData(T data) { _data = data; };
};

template <typename T>
Singleton<T> &Singleton<T>::open() {
  if (instance == nullptr) {
    instance = new Singleton();
  }
  return *instance;
}

template <typename T>
inline Singleton<T> *Singleton<T>::getPtr() {
  if (instance == nullptr) {
    instance = new Singleton();
  }
  return instance;
}

template <typename T>
inline Singleton<T> &Singleton<T>::open(T &val) {
  if (instance == nullptr) {
    instance = new Singleton(val);
  }
  return *instance;
}

template <typename T>
inline Singleton<T> *Singleton<T>::getPtr(T &val) {
  if (instance == nullptr) {
    instance = new Singleton(val);
  }
  return instance;
}

template <typename T>
inline Singleton<T> &Singleton<T>::open(T val) {
  if (instance == nullptr) {
    instance = new Singleton(val);
  }
  return *instance;
}

template <typename T>
inline Singleton<T> *Singleton<T>::getPtr(T val) {
  if (instance == nullptr) {
    instance = new Singleton(val);
  }
  return instance;
}

template <typename T>
T Singleton<T>::getData() const {
  return _data;
}

#endif  // SINGLETON_H
