CC ?= gcc
CFLAGS ?= -Wall -Wextra -O2
LDFLAGS ?=

TARGET = socket_server
SRC = src/socket_server.c

 

all: $(TARGET)

$(TARGET): $(SRC)

    $(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:

    rm -f $(TARGET)
