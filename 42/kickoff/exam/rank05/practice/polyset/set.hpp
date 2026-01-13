#pragma once

#include "searchable_bag.hpp"

class set
{
private:
  searchable_bag &bag;

public:
  set() = delete;
  set(searchable_bag &s_bag);
  set(const set &other) = delete;
  set &operator=(const set &other) = delete;
  ~set();

  bool has(int) const;
  void insert(int);
  void insert(int *, int);
  void print() const;
  void clear();

  const searchable_bag &get_bag() const;
};