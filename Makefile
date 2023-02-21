##
## EPITECH PROJECT, 2022
## Dante's star
## File description:
## Makefile
##

PROGRAMS				:=	generator solver
PROJECT_INCLUDE_DIR		:=	include/
export PROJECT_INCLUDE_DIR
include libraries.mk

.PHONY:	all $(PROGRAMS)
ifeq ($(strip $(filter $(PROGRAMS),$(MAKECMDGOALS))),)
%:	$(PROGRAMS)
	@:

$(PROGRAMS):
	@make -C$@/ $(MAKECMDGOALS)
else
$(filter $(PROGRAMS),$(MAKECMDGOALS)):
	@make -C $@/ $(filter-out $(PROGRAMS),$(MAKECMDGOALS))	\
	--no-print-directory

$(filter-out $(PROGRAMS),$(MAKECMDGOALS)):
	@:
endif
