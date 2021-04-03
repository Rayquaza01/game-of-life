# makefile based off of this blog
# https://spin.atomicobject.com/2016/08/26/makefile-c-projects/

TARGET ?= dist/output

BUILD_DIR ?= obj
SRC_DIRS ?= src

SRCS := $(shell find $(SRC_DIRS) -name *.cc)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -g
LFLAGS ?= -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

$(TARGET): $(OBJS)
	mkdir -p $(dir $@)
	g++ $(OBJS) -o $@ $(LFLAGS)

$(BUILD_DIR)/%.cc.o: %.cc
	mkdir -p $(dir $@)
	g++ $(CPPFLAGS) -c $< -o $@

.phony: clean

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)
