#include <sys/time.h>
#include <unistd.h>

#include "latency-test.h"
#include "thread-msg/sleep.h"
#include "topics/stdout.h"
#include "topics/tester.h"
#include "topics.h"

LatencyTest::LatencyTest(int id) :
    Module(id)
{
}

void LatencyTest::main()
{
    TesterMsg msg;
    struct timeval start;
    struct timeval end;
    uint64_t total_latency_us = 0;
    const int NUM_TESTS = 1000000;
    usleep(10000);
    for (int i = 0; i < NUM_TESTS; i++) {
        gettimeofday(&start, NULL);
        msgr.send(TOPIC_TESTER, &msg);
        StdoutMsg before("Before");
        msgr.send(TOPIC_STDOUT, &before);
        msgr.recv(TOPIC_TESTER, &msg);
        StdoutMsg after("After");
        msgr.send(TOPIC_STDOUT, &after);
        gettimeofday(&end, NULL);
        uint64_t diff_us = USECS_PER_SEC * (end.tv_sec - start.tv_sec)
                            + (end.tv_usec - start.tv_usec);
        total_latency_us += diff_us;
        StdoutMsg print_msg("Latency us: %ld %d", diff_us, i);
        msgr.send(TOPIC_STDOUT, &print_msg);
        usleep(100);
    }
    double avg_latency_us = total_latency_us / (double) NUM_TESTS;
    StdoutMsg print_msg("Avg Latency us: %f", avg_latency_us);
    msgr.send(TOPIC_STDOUT, &print_msg);
}
