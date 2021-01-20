#ifndef LATENCY_TEST_ECHO_H_
#define LATENCY_TEST_ECHO_H_

#include "thread-msg/module.h"

class LatencyTestEcho : public Module {
    public:
        LatencyTestEcho(int id);

        void main() override;

    private:
        void loop();
};

#endif
