//
// Created by lemito on 1/28/25.
//

#include "BST.h"

#include <iostream>
#include <memory>

/*
       10
    5     15
  3  6  14  16


*/
int main() {
  BST<int> tree, a;
  tree.big_insert({10, 5, 15, 3, 6, 14, 26});
  std::cout << tree.isContain(5) << tree.isContain(4) << tree.isContain(6)
            << tree.isContain(100) << "\n";
  auto meow = tree.begin();
  for (auto it = tree.begin(); it != tree.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
  for (auto it = tree.rbegin(); it != tree.rend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
  tree.remove(14);
  BST<int> c = tree;
  a = tree;
  return 0;
}
