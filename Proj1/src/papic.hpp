#ifndef PAPIC_HPP_
#define PAPIC_HPP_

#include <vector>


class PapiC {
 private:
  std::vector<int> installed_events;
  int event_set;

 public:
  PapiC();
  ~PapiC();
  int Init();
  int InstallEvents();
  int Start();
  int StopAndReset();
  int Destroy();

 private:
  int AddEvent(int);
  void PrintCounters(long long *values);
};

#endif  // PAPIC_HPP_
