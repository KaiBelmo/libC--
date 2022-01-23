include = ./include
source  = $(wildcard ./source/*.c)
main = main.c
flags = -Werror -Wextra -Wall -g

forward_list:
	gcc -o forward_list.out $(main) $(source) -I $(include)
