#include "papi.hpp"

#include <papi.h>
#include <iostream>
#include <memory>

using namespace std;


Papi::Papi() { eventset = PAPI_NULL; }

Papi::~Papi() { this->Destroy(); }

int Papi::Init() {
    // Initialize the library
    int retval = PAPI_library_init(static_cast<int>(PAPI_VER_CURRENT));

    if(retval != static_cast<int>(PAPI_VER_CURRENT) && retval < 0) {
        cerr << "[Runtime_Error] PAPI library init error" << endl;
        exit(1);
    }

    if (retval < 0) {
        fprintf(stderr, "[Runtime_Error] PAPI library init error %d: %s\n", retval,
            PAPI_strerror(retval));
        exit(1);
    }

    cout << setw(23) << "" << setw(10) << "MAJOR"
                     << setw(10) << "MINOR"
                     << setw(10) << "REVISION" << endl;
    cout << setw(23) << "PAPI Version Number"
                     << setw(10) << PAPI_VERSION_MAJOR(retval)
                     << setw(10) << PAPI_VERSION_MINOR(retval)
                     << setw(10) << PAPI_VERSION_REVISION(retval) << endl;
    cout << endl;

    return retval;
}

int Papi::InstallEvents() {
    this->Destroy();

    int retval = PAPI_create_eventset(&eventset);

    if(retval != PAPI_OK) {
        eventset = PAPI_NULL;
        return retval;
    }

    // Level 1 data cache misses
    retval = AddEvent(PAPI_L1_DCM);
    if(retval != PAPI_OK)
        return retval;

    // Level 1 instruction cache misses
    retval = AddEvent(PAPI_L1_ICM);
    if(retval != PAPI_OK)
        return retval;

    // Level 1 total cache misses
    retval = AddEvent(PAPI_L1_TCM);
    if(retval != PAPI_OK)
        return retval;

    // Level 2 data cache misses
    retval = AddEvent(PAPI_L2_DCM);
    if(retval != PAPI_OK)
        return retval;Counters

    // Level 2 instruction cache misses
    retval = AddEvent(PAPI_L2_ICM);
    if(retval != PAPI_OK)
        return retval;

    // Level 2 total cache misses
    retval = AddEvent(PAPI_L2_TCM);
    if(retval != PAPI_OK)
        return retval;

    // L3 D Cache Access
    retval = AddEvent(PAPI_L3_DCA);
    if(retval != PAPI_OK)
        return retval;

    // L3 instruction cache accesses
    retval = AddEvent(PAPI_L3_ICA);
    if(retval != PAPI_OK)
        return retval;

    // Total instructions executed
    retval = AddEvent(PAPI_TOT_INS);
    if(retval != PAPI_OK)
        return retval;

    return retval;
}

int Papi::Start() {
    int retval = PAPI_start(eventset);

    if(retval != PAPI_OK)
        cerr << "[Fail] PAPI start" << endl;

    return retval;
}

int Papi::StopAndReset() {
    auto values = make_unique<long long[]>(installed_events.size());

    int retval = PAPI_stop(eventset, values.get());
    if(retval != PAPI_OK)
        cerr << "[Fail] PAPI stop" << endl;
    else
        PrintCounters(values.get());

    retval = PAPI_reset(eventset);
    if(retval != PAPI_OK)
        cerr << "[Fail] PAPI reset" << endl;

    return retval;
}

int Papi::Destroy() {
    if(eventset == PAPI_NULL)
        return PAPI_OK;

    char event_name[PAPI_MAX_STR_LEN];
    for(const int &event_id : installed_events) {
        int retval = PAPI_remove_event(eventset, event_id);

        if(retval != PAPI_OK) {
            PAPI_event_code_to_name(event_id, event_name);

            cerr << "[Fail] " << event_name << endl;
        }
    }

    int retval = PAPI_destroy_eventset(&eventset);
    if(retval != PAPI_OK)
        cerr << "[Fail] PAPI destroy eventset" << endl;
    else
        eventset = PAPI_NULL;

    return retval;
}

int Papi::AddEvent(int event_id) {
    int retval = PAPI_add_event(eventset, event_id);

    if(retval == PAPI_OK)
        installed_events.push_back(event_id);

    else {
        char event_name[PAPI_MAX_STR_LEN];
        PAPI_event_code_to_name(event_id, event_name);

        fprintf(stderr, "[Fail] AddEvent %s\n", event_name);
    }

    return retval;
}

void Papi::PrintCounters(long long *values) {
    char event_name[PAPI_MAX_STR_LEN];
    size_t event_index = 0;

    cout << setw(15) << "Event Name" << setw(15) << "Value" << endl << endl;

    for(; event_index < installed_events.size(); ++event_index) {
        PAPI_event_code_to_name(installed_events[event_index], event_name);
        cout << setw(15) << event_name << setw(15) << values[event_index] << endl;
    }

}
