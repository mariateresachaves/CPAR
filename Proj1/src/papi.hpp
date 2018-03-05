#ifndef PAPI_HPP_
#define PAPI_HPP_

#include <vector>
#include <iomanip>


class Papi {
 private:
  std::vector<int> installed_events;
  int eventset;

 public:
  Papi();
  ~Papi();
  int Init();
  int InstallEvents();
  int Start();
  int StopAndReset();
  int Destroy();
  long GetRealCycles();
  long GetRealuSec();

 private:
  int AddEvent(int);
  void PrintCounters(long long *values);
};

#endif  // PAPI_HPP_
