SRCS_DIR := ./src
BUILD_DIR := ./build

SRCS := $(shell find $(SRCS_DIR) -name "*.c")
OBJS := $(subst $(SRCS_DIR),$(BUILD_DIR),$(SRCS))
OBJS := $(OBJS:.c=.o)

app.out: $(OBJS)
	gcc $(OBJS) -o $@

build/%.o : src/%.c
	gcc -c $< -o $@

clean:
	rm -f app.out
	rm -f build/*.o