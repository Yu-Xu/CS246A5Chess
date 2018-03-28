#ifndef _OBSERVER_H_
#define _OBSERVER_H_

// DO NOT MODIFY THIS FILE!

class Subject;

class Observer {
 public:
  virtual void notify(bool player, int r, int c, std::string type, std::vector<std::pair<int, int>> &v) = 0; // pass the Subject that called the notify method
  virtual ~Observer() = default;
  virtual void print() = 0;
};

#endif
