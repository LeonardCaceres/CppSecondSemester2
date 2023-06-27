#pragma once

#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T>>
class Stack {
 public:
  Container c;

  Stack() = default;
  explicit Stack(const Container& cont) : c(cont) {
  }
  template <typename Iter>
  Stack(Iter first, Iter last) : c(first, last) {
  }
  Stack(Stack&& other) {
    Stack();
    std::swap(c, other.c);
  }
  Stack& operator=(Stack&& other) {
    std::swap(c, other.c);
    return *this;
  }
  T& Top() {
    return c.back();
  }
  const T& Top() const {
    return c.back();
  }
  bool Empty() const {
    return c.empty();
  }
  uint64_t Size() const {
    return c.size();
  }
  void Push(const T& value) {
    c.emplace_back(value);
  }
  void Push(T&& value) {
    c.emplace_back(std::move(value));
  }
  template <typename... Args>
  void Emplace(Args&&... args) {
    c.emplace_back(std::forward<Args>(args)...);
  }
  void Pop() {
    c.pop_back();
  }
  void Swap(Stack& other) {
    std::swap(c, other.c);
  }
};