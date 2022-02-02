include = ./include
source  = $(wildcard ./source/*.c) 
main = main.c
flags = -ggdb #-fsanitize=address #-Werror -Wextra -Wall

stack:
	gcc -o queue.out $(main) $(source) -I $(include) $(flags)