#include "papi.hpp"

using namespace std;


Papi::Papi() { eventset = PAPI_NULL; }

Papi::~Papi() { this->destroy(); }

int Papi::init() {
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

    return retval;
}

int Papi::install_events() {
    this->destroy();

    int retval = PAPI_create_eventset(&eventset);

    if(retval != PAPI_OK) {
        eventset = PAPI_NULL;
        return retval;
    }

    // Level 1 data cache misses
    retval = add_event(PAPI_L1_DCM);
    if(retval != PAPI_OK)
        return retval;

    // Level 1 instruction cache misses
    retval = add_event(PAPI_L1_ICM);
    if(retval != PAPI_OK)
        return retval;

    // Level 1 cache misses
    retval = add_event(PAPI_L1_TCM);
    if(retval != PAPI_OK)
        return retval;

    // Level 2 cache misses
    retval = add_event(PAPI_L2_TCM);
    if(retval != PAPI_OK)
        return retval;

    // Level 3 total cache misses
    retval = add_event(PAPI_L3_TCM);
    if(retval != PAPI_OK)
        return retval;

    // Total instructions executed
    retval = add_event(PAPI_TOT_INS);
    if(retval != PAPI_OK)
        return retval;

    // Total cycles executed
    /*retval = add_event(PAPI_TOT_CYC);
    if(retval != PAPI_OK)
        return retval;

    // Level 2 data cache misses
    retval = add_event(PAPI_L2_DCM);
    if(retval != PAPI_OK)
        return retval;

    // Level 2 instruction cache misses
    retval = add_event(PAPI_L2_ICM);
    if(retval != PAPI_OK)
        return retval;

    // Floating point operations executed
    retval = add_event(PAPI_FP_OPS);
    if(retval != PAPI_OK)
        return retval;

    // L2 D Cache Access
    retval = add_event(PAPI_L2_DCA);
    if(retval != PAPI_OK)
        return retval;

    // L3 D Cache Access
    retval = add_event(PAPI_L3_DCA);
    if(retval != PAPI_OK)
        return retval;

    // L3 instruction cache accesses
    retval = add_event(PAPI_L3_ICA);
    if(retval != PAPI_OK)
        return retval;

    // L3 instruction cache reads
    retval = add_event(PAPI_L3_ICR);
    if(retval != PAPI_OK)
        return retval;

    // L3 total cache accesses
    retval = add_event(PAPI_L3_TCA);
    if(retval != PAPI_OK)
        return retval;

    // Reference clock cycles
    retval = add_event(PAPI_REF_CYC);
    if(retval != PAPI_OK)
        return retval;

    // Data translation lookaside buffer misses
    retval = add_event(PAPI_TLB_DM);
    if(retval != PAPI_OK)
        return retval;

    // Instr translation lookaside buffer misses
    retval = add_event(PAPI_TLB_IM);
    if(retval != PAPI_OK)
        return retval;

    // Level 1 load misses
    retval = add_event(PAPI_L1_LDM);
    if(retval != PAPI_OK)
        return retval;

    // Level 1 store misses
    retval = add_event(PAPI_L1_STM);
    if(retval != PAPI_OK)
        return retval;

    // Level 2 store misses
    retval = add_event(PAPI_L2_STM);
    if(retval != PAPI_OK)
        return retval;

    // Cycles with No Instruction Issue
    retval = add_event(PAPI_STL_ICY);
    if(retval != PAPI_OK)
        return retval;

    // Unconditional branch instructions executed
    retval = add_event(PAPI_BR_UCN);
    if(retval != PAPI_OK)
        return retval;

    // Conditional branch instructions executed
    retval = add_event(PAPI_BR_CN);
    if(retval != PAPI_OK)
        return retval;

    // Conditional branch instructions taken
    retval = add_event(PAPI_BR_TKN);
    if(retval != PAPI_OK)
        return retval;

    // Conditional branch instructions not taken
    retval = add_event(PAPI_BR_NTK);
    if(retval != PAPI_OK)
        return retval;

    // Conditional branch instructions mispred
    retval = add_event(PAPI_BR_MSP);
    if(retval != PAPI_OK)
        return retval;

    // Conditional branch instructions corr. pred
    retval = add_event(PAPI_BR_PRC);
    if(retval != PAPI_OK)
        return retval;

    // Floating point instructions executed
    retval = add_event(PAPI_FP_INS);
    if(retval != PAPI_OK)
        return retval;

    // Load instructions executed
    retval = add_event(PAPI_LD_INS);
    if(retval != PAPI_OK)
        return retval;

    // Store instructions executed
    retval = add_event(PAPI_SR_INS);
    if(retval != PAPI_OK)
        return retval;

    // L2 D Cache Hit
    retval = add_event(PAPI_L2_DCH);
    if(retval != PAPI_OK)
        return retval;

    // L2 D Cache Read
    retval = add_event(PAPI_L2_DCR);
    if(retval != PAPI_OK)
        return retval;

    // L3 D Cache Read
    retval = add_event(PAPI_L3_DCR);
    if(retval != PAPI_OK)
        return retval;

    // L2 D Cache Write
    retval = add_event(PAPI_L2_DCW);
    if(retval != PAPI_OK)
        return retval;

    // L3 D Cache Write
    retval = add_event(PAPI_L3_DCW);
    if(retval != PAPI_OK)
        return retval;

    // L2 instruction cache hits
    retval = add_event(PAPI_L2_ICH);
    if(retval != PAPI_OK)
        return retval;

    // L2 instruction cache accesses
    retval = add_event(PAPI_L2_ICA);
    if(retval != PAPI_OK)
        return retval;

    // L2 instruction cache reads
    retval = add_event(PAPI_L2_ICR);
    if(retval != PAPI_OK)
        return retval;

    // L2 total cache accesses
    retval = add_event(PAPI_L2_TCA);
    if(retval != PAPI_OK)
        return retval;

    // L2 total cache reads
    retval = add_event(PAPI_L2_TCR);
    if(retval != PAPI_OK)
        return retval;

    // L3 total cache reads
    retval = add_event(PAPI_L3_TCR);
    if(retval != PAPI_OK)
        return retval;

    // L2 total cache writes
    retval = add_event(PAPI_L2_TCW);
    if(retval != PAPI_OK)
        return retval;

    // L3 total cache writes
    retval = add_event(PAPI_L3_TCW);
    if(retval != PAPI_OK)
        return retval;

    // FD ins
    retval = add_event(PAPI_FDV_INS);
    if(retval != PAPI_OK)
        return retval;*/

    // Floating point operations executed; optimized to count scaled single precision vector operations
    /*retval = add_event(PAPI_SP_OPS);
    if(retval != PAPI_OK)
        return retval;

    // Floating point operations executed; optimized to count scaled double precision vector operations
    retval = add_event(PAPI_DP_OPS);
    if(retval != PAPI_OK)
        return retval;

    // Single precision vector/SIMD instructions
    retval = add_event(PAPI_VEC_SP);
    if(retval != PAPI_OK)
        return retval;

    // Double precision vector/SIMD instructions
    retval = add_event(PAPI_VEC_DP);
    if(retval != PAPI_OK)
        return retval;*/

    return retval;
}

int Papi::start() {
    int retval = PAPI_start(eventset);

    if(retval != PAPI_OK)
        cerr << "[Fail] PAPI start" << endl;

    return retval;
}

int Papi::stop_and_reset() {
    auto values = make_unique<long long[]>(installed_events.size());

    int retval = PAPI_stop(eventset, values.get());
    if(retval != PAPI_OK)
        cerr << "[Fail] PAPI stop" << endl;
    else
        print_counters(values.get());

    retval = PAPI_reset(eventset);
    if(retval != PAPI_OK)
        cerr << "[Fail] PAPI reset" << endl;

    return retval;
}

int Papi::destroy() {
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

// Gets the time in clock cycles
long long Papi::get_real_cycles() {
    return PAPI_get_real_cyc();
}

long long Papi::get_real_usec() {
    return PAPI_get_real_usec();
}

int Papi::add_event(int event_id) {
    int retval = PAPI_add_event(eventset, event_id);

    if(retval == PAPI_OK)
        installed_events.push_back(event_id);

    else {
        char event_name[PAPI_MAX_STR_LEN];
        PAPI_event_code_to_name(event_id, event_name);

        fprintf(stderr, "[Fail] add_event %s\n", event_name);
    }

    return retval;
}

void Papi::print_counters(long long *values) {
    char event_name[PAPI_MAX_STR_LEN];
    size_t event_index = 0;

    for(; event_index < installed_events.size(); ++event_index) {
        PAPI_event_code_to_name(installed_events[event_index], event_name);
        cout << event_name << " = " << values[event_index] << endl;
    }
}
