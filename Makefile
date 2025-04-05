NAME = philo

INCLUDE = philo.h

CFLAGS = -Wall -Wextra -Werror 

RM = rm -f 

CC = cc 

SRC = ./mand/filling.c ./mand/parsing.c ./mand/safe.c ./mand/safe.c ./mand/

OBJ = $(SRC .c=.o)

all: 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
