CC = gcc
AR = ar rcs
REMOVE = rm -f
CFLAGS = -Wall -Wextra -Werror -g3

SRC_FILES = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c \
            ft_putendl_fd.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c \
            ft_substr.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c \
            ft_memset.c ft_strdup.c ft_strlcat.c ft_strmapi.c \
            ft_strrchr.c ft_tolower.c ft_calloc.c ft_isascii.c ft_itoa.c \
            ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
            ft_putnbr_fd.c ft_split.c ft_striteri.c \
            ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c

BONUS_SRC_FILES = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
                  ft_lstclear_bonus.c ft_lstdelone_bonus.c \
                  ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
                  ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJ_FILES = ${SRC_FILES:.c=.o}
BONUS_OBJ_FILES = ${BONUS_SRC_FILES:.c=.o}
HEADER_FILES = libft.h
BONUS_HEADER_FILES = libft_bonus.h
LIB_FILE = libft.a

all: ${LIB_FILE}

${LIB_FILE}: ${OBJ_FILES}
	${AR} ${LIB_FILE} ${OBJ_FILES}

bonus: ${OBJ_FILES} ${BONUS_OBJ_FILES}
	${AR} ${LIB_FILE} ${OBJ_FILES} ${BONUS_OBJ_FILES}

%_bonus.o: %_bonus.c ${HEADER_FILES} ${BONUS_HEADER_FILES}
	${CC} ${CFLAGS} -c $< -o $@

%.o: %.c ${HEADER_FILES}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${REMOVE} ${OBJ_FILES}

fclean: clean
	${REMOVE} ${LIB_FILE}

cleanbonus:
	${REMOVE} ${BONUS_OBJ_FILES}

cleanall: cleanbonus fclean

re:	fclean all

norm:
	norminette

.PHONY: all bonus clean cleanall cleanbonus fclean norm re