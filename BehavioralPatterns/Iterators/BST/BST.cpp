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
int main(int argc, char const *argv[]) {
  BST<int> tree, a;
  tree.insert(10);
  tree.insert(5);
  tree.insert(15);
  tree.insert(3);
  tree.insert(6);
  tree.insert(14);
  tree.insert(16);
  std::cout << tree.isContain(5) << tree.isContain(4) << tree.isContain(6)
            << tree.isContain(100) << "\n";
  auto meow = tree.begin();
  for (auto it = tree.begin(); it != tree.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n" << *meow << std::endl;
  tree.remove(14);
  BST<int> c = tree;
  a = tree;
  return 0;
}
