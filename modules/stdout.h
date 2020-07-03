#ifndef STDOUT_H_
#define STDOUT_H_

#include "thread-msg/module.h"

class StdOut : public Module {
    public:
        StdOut(int id);

        void main() override;

    private:
        void loop();
};

#endif
