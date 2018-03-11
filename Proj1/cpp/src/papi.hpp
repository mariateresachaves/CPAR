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
  int init();
  int install_events();
  int start();
  int stop_and_reset();
  int destroy();
  long long get_real_cycles();
  long long get_real_usec();

 private:
  int add_event(int);
  void print_counters(long long *values);
};

#endif  // PAPI_HPP_
