THE_SOURCE = srcs/main.cpp
#THE_SOURCE = srcs/main_time.cpp

SRCS = $(THE_SOURCE)
OBJS = $(addprefix ${OBJDIR}/,${SRCS:.cpp=.o})
OBJS_STD = $(addprefix ${OBJDIR_STD}/,${SRCS:.cpp=.o})

NAME = ft_containers
NAME_STD = std_containers
DEPF = -MMD -MP
DEP = ${OBJS:.o=.d}
OBJDIR = helper_files
OBJDIR_STD = helper_files_std
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address
all: ${NAME} $(NAME_STD)


$(NAME)	: ${OBJS}
	${CC} ${CFLAGS} ${DEPF} ${OBJS} -o $@

$(NAME_STD)	: ${OBJS_STD}
	${CC} ${CFLAGS} ${DEPF} ${OBJS_STD} -o $@

${OBJDIR}/%.o:%.cpp
	@mkdir -p ${@D}
	${CC} ${CFLAGS} ${DEPF} -c $< -o $@

${OBJDIR_STD}/%.o:%.cpp
	@mkdir -p ${@D}
	${CC} ${CFLAGS} ${DEPF} -c $< -D STD -o $@

clean:
	rm -rf ${OBJDIR} ${OBJDIR_STD}

fclean: clean
	${RM} ${NAME} ${NAME_STD}

re: fclean all

.PHONY: all clean fclean re

-include ${DEP}