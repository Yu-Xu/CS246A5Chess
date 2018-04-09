#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Observer {
 public:
  virtual bool notify() = 0;
  virtual ~Observer();
};

#endif
