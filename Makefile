#!/usr/bin/make -f
BIN := monty
CC := gcc

SRCS_DIR := .
OBJS_DIR := obj
# directories with header files
INCLUDE_DIRS := $(SRCS_DIR)

# all .c files
SRCS = $(shell ls $(SRCS_DIR)/*.c)
# .o file names
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
# auto-genarated files for .h files make rules
# https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html#index-M
DEP_FILES = $(OBJS:.o=.d) $(TESTS_BINS:%=%.d)

# https://clang.llvm.org/docs/AddressSanitizer.html
ADDRESS_SANITISER := -fsanitize=address
# https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html
UNDEFINED_SANITISER := -fsanitize=undefined

# Include flags
INCL_FLAGS = $(addprefix -iquote,$(INCLUDE_DIRS))
# https://www.gnu.org/software/make/manual/html_node/Automatic-Prerequisites.html
# https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html#index-MMD
CPPFLAGS := -MMD

OPTIMISATION_FLAGS := -Og
DEBUG_FLAGS := -g3 -fno-omit-frame-pointer
C_STANDARD := --std=c89
WARN_FLAGS := -pedantic -Wall -Wextra -Wno-format -Werror

INSTRUMENTATION_FLAGS = $(ADDRESS_SANITISER) $(UNDEFINED_SANITISER)
CFLAGS = $(C_STANDARD) $(WARN_FLAGS) $(INCL_FLAGS) $(CPPFLAGS) $(OPTIMISATION_FLAGS) $(DEBUG_FLAGS) $(INSTRUMENTATION_FLAGS)


$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

$(OBJS_DIR):
	@mkdir -p $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<


.PHONY: clean
clean:
	$(RM) -vdr --preserve-root -- $(OBJS_DIR) $(BIN)

sinclude $(DEP_FILES)
