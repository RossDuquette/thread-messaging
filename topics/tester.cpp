#include <stdio.h>

#include "tester.h"

TesterMsg::TesterMsg() :
    NAME_LEN(32)
{
    name = (char*) &data[0];
    val  = (int*)  &data[NAME_LEN];
}

TesterMsg::TesterMsg(const char* name, int val) :
    TesterMsg()
{
    snprintf(this->name, NAME_LEN, "%s", name);
    *(this->val) = val;
}
