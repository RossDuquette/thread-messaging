#ifndef CONSUMER2_H_
#define CONSUMER2_H_

#include "thread-msg/module.h"

class Consumer_try : public Module {
    public:
        Consumer_try(int id);

        void main() override;

    private:
        void loop();
};

#endif
