#pragma once

#include <array>
#include <cassert>
#include <memory>

template <typename T, std::size_t BITSIZE = 4>
class PersistentArray {
 public:
  using value_t = T;
  using size_t = std::size_t;

 private:
  struct Node {
    value_t val;
    std::array<std::shared_ptr<Node>, 1 << BITSIZE> ch;
    Node(value_t val_) : val(val_) { ch.fill(nullptr); }
  };
  using node_ptr = std::shared_ptr<Node>;

  value_t init;
  node_ptr root;

  node_ptr update(size_t k, value_t value, node_ptr now) {
    node_ptr ret =
        (now ? std::make_shared<Node>(*now) : std::make_shared<Node>(init));
    if (k == 0)
      ret->val = value;
    else {
      size_t mask = (1 << BITSIZE) - 1;
      ret->ch[k & mask] = update(k >> BITSIZE, value, ret->ch[k & mask]);
    }
    return ret;
  }

  value_t at(size_t k, node_ptr now) {
    if (!now) return init;
    if (k == 0) return now->val;
    return at(k >> BITSIZE, now->ch[k & ((1 << BITSIZE) - 1)]);
  }

  PersistentArray(value_t init_, const node_ptr& root_)
      : init(init_), root(root_) {}

 public:
  PersistentArray(value_t init_ = value_t()) : init(init_), root(nullptr) {}

  PersistentArray update(size_t k, const value_t& value) {
    return PersistentArray(init, update(k, value, root));
  }

  value_t operator[](size_t k) { return at(k, root); }
};