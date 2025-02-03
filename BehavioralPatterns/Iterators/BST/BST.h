//
// Created by lemito on 1/28/25.
//

/*
       10
    5     15
  3  6  14  16

TODO: самобалансировка
*/

#ifndef BST_H
#define BST_H

#include <functional>
#include <initializer_list>
#include <iostream>
#include <stack>

// шаблон: T - тип, C - компоратор
template <typename T, typename C = std::less<T>, typename... Args>
class BST {
 public:
  class Node {
   public:
    T _data;
    Node* _parent;
    Node* _left;
    Node* _right;

    Node() : _data(0), _parent(nullptr), _left(nullptr), _right(nullptr){};
    explicit Node(T data)
        : _data(data), _parent(nullptr), _left(nullptr), _right(nullptr){};
    ~Node() { _parent = _left = _right = nullptr; }
    Node(Node& n) = delete;
    Node& operator=(const Node& n) = delete;
  };

  Node* _root = nullptr;
  std::size_t node_cnt;
  std::size_t _height;
  C cmp;  // компаратор

  // TODO: можно ли сделать it--, it-2 и тп операция RAI
  class InorderIterator {
    using difference_type = std::ptrdiff_t;
    using value_type = T;

   private:
    std::stack<Node*> _path;
    Node* cur;

    void go_to_left(Node* n) {
      while (n) {
        _path.push(n);
        n = n->_left;
      }
    }

    Node* TPOP(std::stack<Node*>& st) {
      if (st.empty()) return nullptr;
      auto res = st.top();
      st.pop();
      return res;
    }

   public:
    explicit InorderIterator(Node* n) {
      go_to_left(n);

      cur = TPOP(_path);
    }

    /*
       10
    5     15
  3  6  14  16

    st: 5 10
    cur: 3

    st: 10
    cur: 5
    st: 6 10

    st: 10
    cur: 6

    st:
    cur: 10
    st: 14 15

    st: 15
    cur: 14

    st:
    cur: 15

    st: 16
    cur: 15

    st:
    cur: 16

    */
    InorderIterator& operator++() {
      if (cur == nullptr) return *this;
      if (cur->_right != nullptr) go_to_left(cur->_right);
      cur = TPOP(_path);
      return *this;
    }

    InorderIterator operator++(int) {
      InorderIterator tmp = *this;
      ++(*this);
      return tmp;
    }

    bool operator==(const InorderIterator& other) { return cur == other.cur; }
    bool operator!=(const InorderIterator& other) { return cur != other.cur; }
    T& operator*() { return cur->_data; }
  };

  class RInorderIterator {
    using difference_type = std::ptrdiff_t;
    using value_type = T;

   private:
    std::stack<Node*> _path;
    Node* cur;

    void go_to_right(Node* n) {
      while (n) {
        _path.push(n);
        n = n->_right;
      }
    }

    Node* TPOP(std::stack<Node*>& st) {
      if (st.empty()) return nullptr;
      auto res = st.top();
      st.pop();
      return res;
    }

   public:
    explicit RInorderIterator(Node* n) {
      go_to_right(n);

      cur = TPOP(_path);
    }

    RInorderIterator& operator++() {
      if (cur == nullptr) return *this;
      if (cur->_right != nullptr) go_to_right(cur->_left);
      cur = TPOP(_path);
      return *this;
    }

    RInorderIterator operator++(int) {
      RInorderIterator tmp = *this;
      ++(*this);
      return tmp;
    }

    bool operator==(const RInorderIterator& other) { return cur == other.cur; }
    bool operator!=(const RInorderIterator& other) { return cur != other.cur; }
    T& operator*() { return cur->_data; }
  };

  constexpr InorderIterator begin() { return InorderIterator(_root); };
  constexpr InorderIterator end() { return InorderIterator(nullptr); };
  constexpr RInorderIterator rbegin() { return RInorderIterator(_root); };
  constexpr RInorderIterator rend() { return RInorderIterator(nullptr); };

  constexpr size_t get_height() const { return _height; }

  explicit BST(const C& comparator = C(std::less<T>()))
      : _root(nullptr), node_cnt(0), cmp(comparator) {}
  ~BST() { _clear(_root); };

  void _copy(Node* n) {
    if (n == nullptr) return;
    insert(n->_data);
    _copy(n->_left);
    _copy(n->_right);
  }

  void _clear(Node* n) {
    if (n == nullptr) return;
    _clear(n->_left);
    _clear(n->_right);
    n->_left = n->_parent = n->_right = nullptr;
    delete n;
  }

  BST(const BST& other) : _root(nullptr), node_cnt(0), cmp(other.cmp) {
    Node* cur = other._root;
    _copy(cur);
  }

  BST& operator=(const BST& other) {
    if (this == &other) return *this;
    _clear(_root);
    node_cnt = 0;
    cmp = other.cmp;
    _copy(other._root);
    return *this;
  }

  Node* _max_node(Node* from) {
    if (from == nullptr) return nullptr;
    Node* cur = from;
    while (cur->_right) {
      cur = cur->_right;
    }
    return cur;
  }
  Node* _min_node(Node* from) {
    if (from == nullptr) return nullptr;
    Node* cur = from;
    while (cur->_left) {
      cur = cur->_left;
    }
    return cur;
  }

  void insert(T data) {
    Node* obj = new Node(data);
    if (_root == nullptr) {
      _root = obj;
      node_cnt++;
      return;
    }
    Node* cur = _root;
    while (cur) {
      if (cmp(data, cur->_data)) {
        if (cur->_left == nullptr) {
          cur->_left = obj;
          obj->_parent = cur;
          node_cnt++;
          return;
        }
        cur = cur->_left;
      } else if (cmp(cur->_data, data)) {
        if (cur->_right == nullptr) {
          obj->_parent = cur;
          cur->_right = obj;
          node_cnt++;
          return;
        }
        cur = cur->_right;
      } else {
        delete obj;
        return;
      }
    }
  };

  void big_insert(std::initializer_list<T> ins) {
    for (const auto& elem : ins) {
      this->insert(elem);
    }
  }
  // void big_insert(Args... args) { constexpr size_t cnt = sizeof...(args); }

  void remove(T data) {
    Node* cur = _root;
    while (cur) {
      if (cmp(data, cur->_data)) {
        cur = cur->_left;
      } else if (cmp(cur->_data, data)) {
        cur = cur->_right;
      } else {
        Node* for_swap = _min_node(cur);
        // std::cout << for_swap->_data;
        cur->_data = for_swap->_data;

        if (for_swap->_parent && for_swap->_parent->_left == for_swap) {
          for_swap->_parent->_left = nullptr;
        } else if (for_swap->_parent && for_swap->_parent->_right == for_swap) {
          for_swap->_parent->_right = nullptr;
        }
        delete for_swap;
        node_cnt--;
        return;
      }
    }
    return;
  };

  void big_remove() {}

  constexpr bool isContain(T data) {
    Node* cur = _root;
    while (cur) {
      if (cmp(data, cur->_data)) {
        cur = cur->_left;
      } else if (cmp(cur->_data, data)) {
        cur = cur->_right;
      } else {
        return true;
      }
    }
    return false;
  };
};

#endif  // BST_H