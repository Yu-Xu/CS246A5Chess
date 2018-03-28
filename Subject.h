#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <string>

struct Info;
class Observer;

class Subject {
  std::vector<Observer*> observers;

 public:
  void attach(Observer *o);
  void deattach(Observer *o);
  void getOb();
  void notifyObservers(bool player, int r, int c, std::string type, std::vector<std::pair<int, int>> &v);
  virtual ~Subject() = 0;
};

#endif
