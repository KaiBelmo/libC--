include = ./include
source  = $(wildcard ./source/*.c) 
main = main.c
flags = #-Werror -Wextra -Wall -ggdb #-fsanitize=address

vector:
	gcc -o vector.out $(main) $(source) -I $(include) $(flags)