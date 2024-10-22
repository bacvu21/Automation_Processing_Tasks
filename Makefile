# Compiler
CC = gcc

# Executable name
TARGET = AutomationProcess

# Source files
SRC = main.c Connect_proxy.c create_new_process.c Open_brower.c

# Compiler flags
CFLAGS = -Wall

# Linker flags to link Ws2_32.lib (for Windows sockets)
LDFLAGS = -lws2_32

# Build target
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Clean up build files
clean:
	rm -f $(TARGET)
