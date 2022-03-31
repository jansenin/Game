#ifndef MODEL_BASICOBJECTS_INTERFACE_TICKABLE_H_
#define MODEL_BASICOBJECTS_INTERFACE_TICKABLE_H_

#include "../../../Utilities/time.h"

class Tickable {
 public:
  virtual void Tick(Time delta) = 0;
};

#endif  // MODEL_BASICOBJECTS_INTERFACE_TICKABLE_H_
