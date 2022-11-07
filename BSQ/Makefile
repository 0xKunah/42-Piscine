NAME	=	bsq

SRC		=	src

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -f

SRCS	=	${SRC}/parser/ft_checker.c	${SRC}/parser/ft_parse_stdin.c	\
			${SRC}/parser/ft_len.c		${SRC}/parser/ft_parse.c		\
			${SRC}/parser/ft_split.c	${SRC}/parser/ft_strdup.c		\
			${SRC}/solver/coords.c		${SRC}/solver/grid.c			\
			${SRC}/solver/math.c		${SRC}/solver/solve.c			\
			${SRC}/solver/square.c		${SRC}/print.c					\

MAIN	=	${SRC}/main.c

TEST	=	${SRC}/main.test.c

MAPGEN	=	./mapgen

OBJS	=	${SRCS:.c=.o}

HEADERS	=	includes/

all: ${OBJS}
	${CC} ${SRCS} ${MAIN} ${CFLAGS} -I ${HEADERS} -o ${NAME}

test:
	${CC} ${SRCS} ${TEST} ${CFLAGS} -I ${HEADERS} -o ${NAME}.test

run:
	${MAPGEN} 9 9 4 | ./${NAME}

debug:
	${CC} -g ${SRCS} ${MAIN} ${CFLAGS} -I ${HEADERS} -o ${NAME}
	lldb ./${NAME}

debug_test:
	${CC} -g ${SRCS} ${TEST} ${CFLAGS} -I ${HEADERS} -o ${NAME}.test
	lldb ./${NAME}.test

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): all

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
