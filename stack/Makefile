include = ./include
source  = $(wildcard ./source/*.c) 
main = main.c
flags = -ggdb #-fsanitize=address #-Werror -Wextra -Wall

stack:
	gcc -o stack.out $(main) $(source) -I $(include) $(flags)