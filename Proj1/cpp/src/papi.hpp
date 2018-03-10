#ifndef PAPI_HPP_
#define PAPI_HPP_

#include <vector>
#include <papi.h>
#include <iostream>
#include <memory>


class Papi {
 private:
  std::vector<int> installed_events;
  int eventset;
  int event_independent;

 public:
  Papi();
  ~Papi();
  int Init();
  int InstallEvents();
  int Start();
  int StopAndReset();
  int Destroy();
  long long GetRealCycles();
  long long GetRealuSec();

 private:
  int AddEvent(int);
  void PrintCounters(long long *values);
};

#endif  // PAPI_HPP_
