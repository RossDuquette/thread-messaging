#include <stdarg.h>
#include <stdio.h>

#include "thread-msg/conf.h"
#include "stdout.h"

StdoutMsg::StdoutMsg()
{
    msg = (char*) &data[0];
}

StdoutMsg::StdoutMsg(const char* format, ...) :
    StdoutMsg()
{
    va_list p_list;
    va_start(p_list, format);
    vsnprintf(msg, MAX_MSG_LEN, format, p_list);
}
