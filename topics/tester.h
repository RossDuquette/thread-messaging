#ifndef TOPIC_TESTER_H_
#define TOPIC_TESTER_H_

#include "thread-msg/msg.h"

class TesterMsg : public Msg {
    public:
        TesterMsg();
        TesterMsg(const char* name, int val);

        char* name;
        int* val;

    private:
        const int NAME_LEN;
};

#endif
