#ifndef TOPIC_STDOUT_H_
#define TOPIC_STDOUT_H_

#include "thread-msg/msg.h"

class StdoutMsg : public Msg {
    public:
        StdoutMsg();
        StdoutMsg(const char* format, ...);

        char* msg;
};

#endif
