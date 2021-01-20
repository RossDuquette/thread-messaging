#include <pthread.h>
#include <signal.h>
#include <stdlib.h>

#include "consumer.h"
#include "consumer_try.h"
#include "latency-test.h"
#include "latency-test-echo.h"
#include "modules.h"
#include "producer.h"
#include "stdout.h"
#include "topics.h"

static Module* modules[NUM_MODULES];
static int num_modules = 0;

static void signal_handler(int signum)
{
    for (int mod = 0; mod < num_modules; mod++) {
        delete modules[mod];
    }
    exit(signum);
}

int main()
{
    static_assert(NUM_MODULES <= MAX_NUM_MODULES);
    static_assert(NUM_TOPICS <= MAX_NUM_TOPICS);

    signal(SIGINT, signal_handler);

    //modules[num_modules++] = new Consumer(MODULE_CONSUMER);
    //modules[num_modules++] = new Consumer_try(MODULE_CONSUMER_TRY);
    //modules[num_modules++] = new Producer(MODULE_PRODUCER);
    //modules[num_modules++] = new Producer(MODULE_PRODUCER2);
    modules[num_modules++] = new LatencyTest(MODULE_LATENCY_TEST);
    modules[num_modules++] = new LatencyTestEcho(MODULE_LATENCY_TEST_ECHO);
    modules[num_modules++] = new StdOut(MODULE_STDOUT);

    for (int mod = 0; mod < num_modules; mod++) {
        modules[mod]->start();
    }

    pthread_exit(NULL);

    return 0;
}
