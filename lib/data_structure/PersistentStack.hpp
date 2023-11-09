#pragma once

#include <cassert>
#include <memory>

template <typename T>
class PersistentStack {
 public:
  using value_t = T;
  using size_t = std::size_t;

 private:
  struct Node {
    value_t val;
    std::shared_ptr<Node> next;
    Node(value_t val_, std::shared_ptr<Node> next_ = nullptr)
        : val(val_), next(next_) {}
  };

  using node_ptr = std::shared_ptr<Node>;
  node_ptr root;

  PersistentStack(const node_ptr& root_) : root(root_) {}

 public:
  PersistentStack() : root() {}

  bool empty() { return !root; }
  value_t top() {
    assert(root);
    return root->val;
  }

  PersistentStack push(value_t value) {
    return PersistentStack(std::make_shared<Node>(value, root));
  }

  PersistentStack pop() {
    assert(root);
    return PersistentStack(root->next);
  }
};