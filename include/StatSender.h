// Copyright 2021 ak-kuznetsov <a.kuznetsov2701@mail.ru>

#ifndef TEMPLATE_STATSENDER_H
#define TEMPLATE_STATSENDER_H
#include <fstream>
#include <string_view>

#include "Log.h"
#include "header.h"

class StatSender {
 public:
  void OnLoaded(const std::vector<Item>& new_items);

  void Skip(const Item& item);

  virtual ~StatSender() = default;

 private:
  virtual void AsyncSend(const std::vector<Item>& items, std::string_view path);

  std::ofstream fstr{"network", std::ios::binary};
};
#endif  // TEMPLATE_STATSENDER_H
