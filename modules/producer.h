#ifndef PRODUCER_H_
#define PRODUCER_H_

#include "thread-msg/module.h"

class Producer : public Module {
    public:
        Producer(int id);

        void main() override;

    private:
        void loop();
};

#endif
