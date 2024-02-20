CFLAGS = -Wall -Wextra -Wextra
TARGET_NAME = rush-02
SRC_DIR = src
LIB_DIR = lib
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

all:		${TARGET_NAME}

%.o: %.c
	cc $(CFLAGS) -c $< -o  $@ -I $(LIB_DIR)

$(TARGET_NAME): $(OBJS)
	cc $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET_NAME)

re: fclean all
