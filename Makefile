PROG_NAME ?= thread-msg-example
LIB_NAME ?= thread-msg
DEBUG ?= n
VERBOSE ?= n

OBJ_DIR = obj
MODULES_DIR = modules
TOPICS_DIR = topics

SRCS += main.cpp
SRCS += $(MODULES_DIR)/consumer.cpp
SRCS += $(MODULES_DIR)/consumer_try.cpp
SRCS += $(MODULES_DIR)/latency-test.cpp
SRCS += $(MODULES_DIR)/latency-test-echo.cpp
SRCS += $(MODULES_DIR)/producer.cpp
SRCS += $(MODULES_DIR)/stdout.cpp
SRCS += $(TOPICS_DIR)/stdout.cpp
SRCS += $(TOPICS_DIR)/tester.cpp

LIB_DIR = $(LIB_NAME)
LIB = $(LIB_DIR)/lib$(LIB_NAME).a

ifeq ($(VERBOSE),y)
CC = g++
LD = g++
else
CC = @echo '   ' CC $@; g++
LD = @echo '   ' LD $@; g++
endif

INC_DIRS += .
INC_DIRS += ./$(MODULES_DIR)
INC_DIRS += ./$(TOPICS_DIR)

CFLAGS += $(addprefix -I, $(INC_DIRS))
CFLAGS += -O0
CFLAGS += -Wno-format-truncation
ifeq ($(DEBUG),y)
CFLAGS += -g
endif

LDFLAGS += -lpthread
LDFLAGS += -L$(LIB_DIR) -l$(LIB_NAME)

DEPS := $(shell find . -name "*.h")
OBJS := $(addprefix $(OBJ_DIR)/, $(patsubst %.cpp,%.o,$(SRCS)))

all: lib $(PROG_NAME)

lib:
	@$(MAKE) -C $(LIB_DIR)

$(PROG_NAME): $(OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: %.cpp $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)
	rm -f $(PROG_NAME)
