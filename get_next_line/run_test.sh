#i/bin/sh


cc -Wall -Werror -Wextra -I. main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=6 && ./a.out | cat -e
