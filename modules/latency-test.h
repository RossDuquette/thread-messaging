#ifndef LATENCY_TEST_H_
#define LATENCY_TEST_H_

#include "thread-msg/module.h"

class LatencyTest : public Module {
    public:
        LatencyTest(int id);

        void main() override;
};

#endif
