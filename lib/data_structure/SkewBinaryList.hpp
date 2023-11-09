#pragma once

#include <cassert>
#include <list>

#include "./utility/type_alias.hpp"

template <typename T>
class SkewBinaryList {
 public:
  using value_t = T;

 private:
  struct Node {
    value_t val;
    size_t cnt;
    Node *left, *right;
    Node(value_t val_, Node *left_ = nullptr, Node *right_ = nullptr)
        : val(val_), cnt(1), left(left_), right(right_) {
      if (left_) cnt += left_->cnt;
      if (right_) cnt += right_->cnt;
    }
    ~Node() {
      if (left)delete left;
      if (right)delete right;
      left = nullptr;
      right = nullptr;
    }
  };

  using node_ptr = Node*;

  size_t cnt;
  std::list<node_ptr> roots;

 public:
  SkewBinaryList() : cnt(0), roots() {}

  SkewBinaryList(const SkewBinaryList&) = delete;
  SkewBinaryList& operator=(const SkewBinaryList&) = delete;

  ~SkewBinaryList() {
    for (auto&& e : roots) {
      delete e;
      e = nullptr;
    }
  }

  size_t size() { return cnt; }
  bool empty() { return size() == 0; }

  value_t front() {
    assert(!empty());
    return roots.front()->val;
  }

  void push_front(value_t x) {
    cnt++;
    if (roots.size() < 2) {
      roots.emplace_front(new Node(x));
      return;
    }
    node_ptr first = *roots.begin();
    node_ptr second = *(++roots.begin());
    if(first->cnt != second ->cnt){
      roots.emplace_front(new Node(x));
      return;   
    }else{
      roots.pop_front();
      roots.pop_front();
      roots.emplace_front(new Node(x,first,second));
    }
  }

  void pop_front(){
    assert(!empty());
    if(roots.front()->cnt == 1){
      delete roots.front();
      roots.pop_front();
      return;
    }
    node_ptr erase_node = roots.front();
    roots.pop_front();
    roots.push_front(erase_node->right);
    erase_node->right=nullptr;
    roots.push_front(erase_node->left);
    erase_node->left=nullptr;
    delete erase_node;
    return;
  }
};