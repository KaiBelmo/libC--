include = ./include
source  = $(wildcard ./source/*.c) 
main = main.c
flags = -ggdb -Werror -Wextra -Wall #-fsanitize=address 

vector:
	gcc -o deque.out $(main) $(source) -I $(include) $(flags)