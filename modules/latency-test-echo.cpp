#include "latency-test-echo.h"
#include "topics/tester.h"
#include "topics.h"

LatencyTestEcho::LatencyTestEcho(int id) :
    Module(id)
{
}

void LatencyTestEcho::main()
{
    while (1) {
        loop();
    }
}

void LatencyTestEcho::loop()
{
    TesterMsg msg;
    msgr.recv(TOPIC_TESTER, &msg); // blocking
    msgr.send(TOPIC_TESTER, &msg);
}
