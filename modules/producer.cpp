#include <stdint.h>
#include <string.h>

#include "thread-msg/sleep-rt.h"
#include "producer.h"
#include "topics/tester.h"
#include "topics.h"

Producer::Producer(int id) :
    Module(id)
{
}

void Producer::main()
{
    const float HZ = 1.0;
    const uint64_t runtime_usecs = 1000; // Over-estimate of actual runtime
    FreqSleeperRT sleeper(HZ, runtime_usecs);
    while (1) {
        loop();
        sleeper.sleep();
    }
}

void Producer::loop()
{
    TesterMsg msg("tester", 423);
    msgr.send(TOPIC_TESTER, &msg);
}
