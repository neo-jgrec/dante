##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

PROJECT_NAME			=	solver
NAME					=	solver

SRC 					= 	src/solver.c

MAIN 					=	src/main.c

BUILD_DIR				=	build
OBJ						=	$(SRC:%.c=$(BUILD_DIR)/%.o)
OBJ_MAIN				=	$(MAIN:%.c=$(BUILD_DIR)/%.o)
OBJ						+=	$(OBJ_MAIN)

CFLAGS					:=	-I include/

WFLAGS					:=	-Wall -Wextra

CRITERION				=	-lcriterion --coverage
TEST_NAME				=	unit_tests
TEST_SRC				+=	\
							../tests/solver/basics.c \
							../tests/solver/malloc_wrapper.c
TEST_INCLUDE_DIR		=	../tests/include
LCOV 					:= 	-fprofile-arcs -ftest-coverage

all:	$(NAME)

$(NAME):	$(OBJ)
	@mkdir -p $(BUILD_DIR)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(WFLAGS) \
	&& echo -e "\033[1;32m[OK]\033[0m" $(NAME) \
	|| echo -e "\033[1;31m[KO]\033[0m" $(NAME)

$(BUILD_DIR)/%.o:	%.c
	@mkdir -p $(dir $@)
	@gcc -c -o $@ $< $(CFLAGS) $(WFLAGS) \
	&& echo -e "\033[1;32m[OK]\033[0m" $< \
	|| echo -e "\033[1;31m[KO]\033[0m" $<

debug:	CFLAGS += -g3
debug:	re

clean:
	@for file in $(BUILD_DIR)/*; do \
		if [ -d $$file ]; then \
			rm -rf $$file; \
			echo -e "\033[1;31m[DELETED]\033[0m" $$file; \
		fi;\
	done
	@echo -e "\033[1;31m[CLEAN]\033[0m" $(PROJECT_NAME)
	@rm -f $(shell find -name '*.gc*' -type f)

fclean: clean
	if [ -f $(TEST_NAME) ]; then \
		rm -f $(TEST_NAME); \
		echo -e "\033[1;31m[DELETED]\033[0m" $(TEST_NAME); \
	fi
	@rm -f $(NAME)
	@echo -e "\033[1;31m[DELETED]\033[0m" $(NAME)

re:	fclean all

tests_run:	CFLAGS += --coverage
tests_run:	LDFLAGS += -lcriterion -Wl,--wrap,malloc
tests_run:	re
	@mkdir -p $(BUILD_DIR)
	@gcc -o $(TEST_NAME) $(SRC) $(TEST_SRC) $(CFLAGS) $(WFLAGS) $(LDFLAGS) \
	$(LCOV) -I $(TEST_INCLUDE_DIR) \
	&& echo -e "\033[1;32m[OK]\033[0m" $(TEST_NAME) \
	|| echo -e "\033[1;31m[KO]\033[0m" $(TEST_NAME)
	@./$(TEST_NAME) --verbose --always-succeed

.PHONY: all clean fclean re debug tests_run

.SILENT: all clean fclean re debug tests_run

%:
	@echo -e "\033[1;31m[ERROR]\033[0m" "No rule to make target '$@'"
