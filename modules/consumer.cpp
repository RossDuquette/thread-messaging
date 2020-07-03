#include <string.h>

#include "consumer.h"
#include "topics/stdout.h"
#include "topics/tester.h"
#include "topics.h"

Consumer::Consumer(int id) :
    Module(id)
{
}

void Consumer::main()
{
    while (1) {
        loop();
    }
}

void Consumer::loop()
{
    TesterMsg msg;
    msgr.recv(TOPIC_TESTER, &msg); // blocking

    StdoutMsg msg_to_print("Recieved: %s, %d", msg.name, *msg.val);
    msgr.send(TOPIC_STDOUT, &msg_to_print);
}
