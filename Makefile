##
## EPITECH PROJECT, 2023
## dante
## File description:
## Makefile
##

PROJECT_NAME			=	dante

DIR_GENERATOR			:=	generator
DIR_SOLVER				:=	solver

all:
	@$(MAKE) -s -C $(DIR_GENERATOR)
	@$(MAKE) -s -C $(DIR_SOLVER)

debug:
	@$(MAKE) -s -C $(DIR_GENERATOR) debug
	@$(MAKE) -s -C $(DIR_SOLVER) debug

clean:
	@$(MAKE) -s -C $(DIR_GENERATOR) clean
	@$(MAKE) -s -C $(DIR_SOLVER) clean

fclean:
	@$(MAKE) -s -C $(DIR_GENERATOR) fclean
	@$(MAKE) -s -C $(DIR_SOLVER) fclean

re:	fclean all

tests_run:
	@$(MAKE) -s -C $(DIR_GENERATOR) tests_run
	@$(MAKE) -s -C $(DIR_SOLVER) tests_run
	gcovr --exclude='.*main\.c' --exclude tests/

.PHONY: all clean fclean re debug

.SILENT: all $(NAME) clean fclean re debug

%:
	@echo -e "\033[1;31m[ERROR]\033[0m" "No rule to make target '$@'"
