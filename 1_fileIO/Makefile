CC = gcc
RM = rm -rf

SRC = ${wildcard *.c}
SAMPLES = ${basename $(SRC)}

all:$(SAMPLES)
%.o:%.c 
	$(CC) -c $< -o $@
clean:
	$(RM) $(SAMPLES)