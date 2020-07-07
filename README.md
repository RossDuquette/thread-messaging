# thread-msg-example

This is an example on how to use the `thread-msg` library.
It is recommended to familiarize yourself with the library
first.

To create a new module, you must:
* Update `modules.h`
* Update `main.cpp` (unless creating a child module. See `thread-msg` for more details)
* Update Makefile
* Add custom Module class in the `modules/` directory that inherits from `thread-msg/module.h`

To create a new topic, you must:
* Update `topics.h`
* Update Makefile
* Add custom Msg class in the `topics/` directory that inherits from `thread-msg/msg.h`
