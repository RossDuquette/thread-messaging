#ifndef CONSUMER_H_
#define CONSUMER_H_

#include "thread-msg/module.h"

class Consumer : public Module {
    public:
        Consumer(int id);

        void main() override;

    private:
        void loop();
};

#endif
