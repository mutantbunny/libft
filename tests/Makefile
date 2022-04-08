CC = gcc
AR = ar rcs
REMOVE = rm -f
CFLAGS_TEST = -ggdb -Wall -Wextra -Werror \
         -I /home/coder/criterion-2.4.0/include \
         -L /home/coder/criterion-2.4.0/lib -lcriterion

CFLAGS = -Wall -Wextra -Werror

TESTS_DIR = ./tests/

SRC_FILES = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c \
            ft_putendl_fd.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c \
            ft_substr.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c \
            ft_memset.c ft_putnbr_fd.c ft_strdup.c ft_strlcat.c ft_strmapi.c \
            ft_strrchr.c ft_tolower.c ft_calloc.c ft_isascii.c ft_itoa.c \
            ft_memcpy.c ft_putchar_fd.c ft_split.c ft_striteri.c ft_strlcpy.c \
            ft_strncmp.c ft_strtrim.c ft_toupper.c

TEST_SRC_FILES = ft_atoi_test.c ft_memchr_test.c ft_strchr_test.c \
                 ft_strnstr_test.c ft_bzero_test.c ft_memcmp_test.c \
                 ft_strdup_test.c ft_strrchr_test.c ft_calloc_test.c \
                 ft_memcpy_test.c ft_striteri_test.c ft_strtrim_test.c \
                 ft_isalnum_test.c ft_memmove_test.c ft_strjoin_test.c \
                 ft_substr_test.c ft_isalpha_test.c ft_memset_test.c \
                 ft_strlcat_test.c ft_tolower_test.c ft_isascii_test.c \
                 ft_putchar_fd_test.c ft_strlcpy_test.c ft_toupper_test.c \
                 ft_isdigit_test.c ft_putendl_fd_test.c ft_strlen_test.c \
                 ft_isprint_test.c ft_putnbr_fd_test.c ft_strmapi_test.c \
                 ft_itoa_test.c ft_split_test.c ft_strncmp_test.c

OBJ_FILES = ${SRC_FILES:.c=.o}
TEST_OBJ_FILES = ${TEST_SRC_FILES:.c=.o}
TEST_HEADER_FILES = libft_test.h
HEADER_FILES = ../libft.h
TEST_FILE = libft_test

all: ${TEST_FILE} norm test

%_test: %_test.o ../%.o FORCE
	${CC} ${CFLAGS_TEST} $@.o ../${@:_test=.o} -lbsd -o $@
	norminette ../${@:_test=.c} ${HEADER_FILES} | grep 'Error\|Warning' || true
	export LD_LIBRARY_PATH=/home/coder/criterion-2.4.0/lib; ./$@ --verbose

${TEST_FILE}: ${TEST_OBJ_FILES} ${OBJ_FILES}
	${CC} ${CFLAGS_TEST} ${TEST_OBJ_FILES} ${OBJ_FILES} -lbsd -o $@

%_test.o: %_test.c ${TEST_HEADER_FILES}
	${CC} ${CFLAGS_TEST} -c $< -o $@

%.o: ../%.c ${HEADER_FILES}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${REMOVE} ${OBJ_FILES}
	${REMOVE} ${TEST_OBJ_FILES}

fclean: clean
	${REMOVE} ${TEST_FILE}

norm:
	norminette ../*.c ../*.h | grep 'Error\|Warning' || true

re:	fclean all

test:
	export LD_LIBRARY_PATH=/home/coder/criterion-2.4.0/lib; ./${TEST_FILE} --verbose

FORCE:

.PHONY: all clean fclean norm re test FORCE