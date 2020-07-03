#include <stdio.h>
#include <unistd.h>

#include "consumer_try.h"
#include "thread-msg/sleep.h"
#include "topics/stdout.h"
#include "topics/tester.h"
#include "topics.h"

Consumer_try::Consumer_try(int id) :
    Module(id)
{
}

void Consumer_try::main()
{
    const float HZ = 10.0;
    FreqSleeper sleeper(HZ);
    while (1) {
        loop();
        sleeper.sleep();
    }
}

void Consumer_try::loop()
{
    TesterMsg msg;
    if (msgr.try_recv(TOPIC_TESTER, &msg)) {
        StdoutMsg msg_to_print("Try Recieved: %s, %d", msg.name, *msg.val);
        msgr.send(TOPIC_STDOUT, &msg_to_print);
    } else {
        StdoutMsg msg_to_print("No new msgs");
        msgr.send(TOPIC_STDOUT, &msg_to_print);
    }
}
