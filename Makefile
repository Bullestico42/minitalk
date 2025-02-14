NAME_CLIENT = client
NAME_SERVER = server
CLIENT = server.dSYM
LIBFT = libft/libft.a
PRINTF = printf/printf.a

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

HEAD = inc/minitalk.h

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

CC = cc -g -O0
CF = -Wall -Werror -Wextra #-fsanitize=address -static-libasan

AR = ar rcs
RM = rm -rf

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all: ${NAME_CLIENT} ${NAME_SERVER}

# Binary creation

${NAME_CLIENT}: ${SRCS_CLIENT} ${HEAD} ${PRINTF} ${LIBFT}
	${CC} ${CF} ${SRCS_CLIENT} ${PRINTF} ${LIBFT} -o ${NAME_CLIENT}

${NAME_SERVER}: ${SRCS_SERVER} ${HEAD} ${PRINTF} ${LIBFT}
	${CC} ${CF} ${SRCS_SERVER} ${PRINTF} ${LIBFT} -o ${NAME_SERVER}

${PRINTF}:
	make re -C printf/

${LIBFT}:
	make re -C libft/

# Mandatory rules

clean:
	${RM} libft/*.o src/*.o libft/*.o
	make clean -C libft/
	make clean -C printf/

fclean: clean
	${RM} ${NAME_CLIENT} ${NAME_SERVER} ${CLIENT}
	make fclean -C libft/
	make fclean -C printf/

re: fclean all

.PHONY: all clean fclean re