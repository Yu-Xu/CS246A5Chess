#include "Subject.h"
#include <iostream>
#include "observer.h"

void Subject::attach(Observer *o) {
  observers.emplace_back(o);
}

Subject::~Subject() {}

void Subject::deattach(Observer *o) {
  int size = observers.size();
  for(int i = 0; i < size; i++) {
    if (observers[i] == o) {
      // std::cout << "deattach" << std::endl;
      observers.erase(observers.begin() + i);
    }
  }
}

void Subject::notifyObservers(bool player, int r, int c,
std::string type, std::vector<std::pair<int, int>> &v) {
  for(int i = 0; i < observers.size(); i++) {
    if(observers[i] == nullptr) {
      std::cout << "null" << std::endl;
      observers.erase(observers.begin() + i);
    }
  }
  // std::cout << "size" << observers.size() << std::endl;
  // int i = 0;
  for (auto &ob : observers) {
    ob->notify(player, r, c, type, v);
  }
}

void Subject::getOb() {
  for (auto &ob : observers) {
    ob->print();
  }
}
