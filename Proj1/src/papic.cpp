#include "papic.hpp"

#include <papi.h>
#include <iostream>
#include <memory>

using namespace std;


PapiC::PapiC() { event_set = PAPI_NULL; }

PapiC::~PapiC() { this->Destroy(); }

int PapiC::Init() {
    int ret = PAPI_library_init(static_cast<int>(PAPI_VER_CURRENT));

    if(ret != static_cast<int>(PAPI_VER_CURRENT) && ret < 0)
        cerr << "[Runtime_Error] PAPI_library_init" << endl;

    if (ret < 0) {
        fprintf(stderr, "[Runtime_Error] PAPI_library_init %d: %s\n", ret,
            PAPI_strerror(ret));
        cerr << "[Runtime_Error] PAPI_library_init" << endl;
    }

    cout << "PAPI Version Number: MAJOR: " << PAPI_VERSION_MAJOR(ret)
         << "\t MINOR: " << PAPI_VERSION_MINOR(ret)
         << "\t REVISION: " << PAPI_VERSION_REVISION(ret) << endl;

    return ret;
}

int PapiC::InstallEvents() {
    this->Destroy();

    int ret = PAPI_create_eventset(&event_set);

    if(ret != PAPI_OK) {
        event_set = PAPI_NULL;
        return ret;
    }

    ret = AddEvent(PAPI_L1_DCM);
    if(ret != PAPI_OK)
        return ret;

    ret = AddEvent(PAPI_L1_ICM);
    if(ret != PAPI_OK)
        return ret;

    ret = AddEvent(PAPI_L1_TCM);
    if(ret != PAPI_OK)
        return ret;


    ret = AddEvent(PAPI_L2_DCM);
    if(ret != PAPI_OK)
        return ret;

    ret = AddEvent(PAPI_L2_ICM);
    if(ret != PAPI_OK)
        return ret;

    ret = AddEvent(PAPI_L2_TCM);
    if(ret != PAPI_OK)
        return ret;


    ret = AddEvent(PAPI_L3_DCA);
    if(ret != PAPI_OK)
        return ret;


    ret = AddEvent(PAPI_L3_ICA);
    if(ret != PAPI_OK)
        return ret;

    ret = AddEvent(PAPI_TOT_INS);
    if(ret != PAPI_OK)
        return ret;

    return ret;
}

int PapiC::Start() {
    int ret = PAPI_start(event_set);
    if(ret != PAPI_OK)
        cerr << "[Fail] PAPI_start" << endl;

    return ret;
}

int PapiC::StopAndReset() {
    auto values = make_unique<long long[]>(installed_events.size());

    int ret = PAPI_stop(event_set, values.get());
    if(ret != PAPI_OK)
        cerr << "[Fail] PAPI_stop" << endl;
    else
        PrintCounters(values.get());

    ret = PAPI_reset(event_set);
    if(ret != PAPI_OK)
        cerr << "[Fail] PAPI_reset" << endl;

    return ret;
}

int PapiC::Destroy() {
    if(event_set == PAPI_NULL)
        return PAPI_OK;

    char event_name[PAPI_MAX_STR_LEN];
    for(const int &event_id : installed_events) {
        int ret = PAPI_remove_event(event_set, event_id);

        if(ret != PAPI_OK) {
            PAPI_event_code_to_name(event_id, event_name);

            cerr << "[Fail] " << event_name << endl;
        }
    }

    int ret = PAPI_destroy_eventset(&event_set);
    if(ret != PAPI_OK)
        cerr << "[Fail] PAPI_destroy_eventset" << endl;
    else
        event_set = PAPI_NULL;

    return ret;
}

int PapiC::AddEvent(int event_id) {
    int ret = PAPI_add_event(event_set, event_id);

    if(ret == PAPI_OK)
        installed_events.push_back(event_id);

    else {
        char event_name[PAPI_MAX_STR_LEN];
        PAPI_event_code_to_name(event_id, event_name);

        fprintf(stderr, "[Fail] AddEvent %s\n", event_name);
    }

    return ret;
}

void PapiC::PrintCounters(long long *values) {
    char event_name[PAPI_MAX_STR_LEN];
    size_t event_index = 0;

    for(; event_index < installed_events.size(); ++event_index) {
        PAPI_event_code_to_name(installed_events[event_index], event_name);
        cout << event_name << ": " << values[event_index] << endl;
    }
}
