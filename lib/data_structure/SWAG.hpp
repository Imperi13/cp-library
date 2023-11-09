#pragma once

#include <cassert>
#include <stack>

template <typename Semigroup>
class SWAG {
 public:
  using value_t = typename Semigroup::value_t;
  using size_t = std::size_t;

 private:
  using P = std::pair<value_t, value_t>;
  std::stack<P> front, back;

 public:
  SWAG() {}

  size_t size() { return front.size() + back.size(); }
  bool empty() { return size() == 0; }

  value_t fold_all() {
    assert(!empty());
    if (front.empty()) return back.top().second;
    if (back.empty()) return front.top().second;
    return Semigroup::op(front.top().second, back.top().second);
  }

  void push_back(value_t val) {
    if (back.empty())
      back.emplace(val, val);
    else {
      P tmp = back.top();
      back.emplace(val, Semigroup::op(tmp.second, val));
    }
  }

  void push_front(value_t val) {
    if (front.empty())
      front.emplace(val, val);
    else {
      P tmp = front.top();
      front.emplace(val, Semigroup::op(val, tmp.second));
    }
  }

  void pop_back() {
    assert(!empty());
    if (!back.empty()) {
      back.pop();
      return;
    }
    size_t n = front.size();
    std::stack<value_t> tmp;
    for (size_t i = 0; i < n / 2; i++) {
      tmp.emplace(front.top().first);
      front.pop();
    }
    while (!front.empty()) {
      push_back(front.top().first);
      front.pop();
    }
    while (!tmp.empty()) {
      push_front(tmp.top());
      tmp.pop();
    }
    back.pop();
  }

  void pop_front() {
    assert(!empty());
    if (!front.empty()) {
      front.pop();
      return;
    }
    size_t n = back.size();
    std::stack<value_t> tmp;
    for (std::size_t i = 0; i < n / 2; i++) {
      tmp.emplace(back.top().first);
      back.pop();
    }
    while (!back.empty()) {
      push_front(back.top().first);
      back.pop();
    }
    while (!tmp.empty()) {
      push_back(tmp.top());
      tmp.pop();
    }
    front.pop();
  }
};