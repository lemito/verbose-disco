//
// Created by lemito on 1/28/25.
//

#include "BST.h"

#include <iostream>
#include <memory>

int main(int argc, char const *argv[]) {
  BST<int> tree, a;
  tree.insert(5);
  tree.insert(4);
  tree.insert(6);
  std::cout << tree.isContain(5) << tree.isContain(4) << tree.isContain(6)
            << tree.isContain(100) << "\n";
  tree.remove(4);
  BST<int> c = tree;
  a = tree;
  return 0;
}
