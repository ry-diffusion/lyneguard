SRC	 = control.c lyneguard.c 
OBJ	 = $(SRC:.c=.o)
TARGET   = lyne_combined.o

CFLAGS  +=   -Wall -Werror -Wextra -Wpedantic -Wno-unused-variable -Wno-unused-parameter -std=c11 \
			-I. -I ../kernel

$(TARGET): $(OBJ)
	ld -r -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(OBJ) $(TARGET)
