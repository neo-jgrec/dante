##
## EPITECH PROJECT, 2022
## Libraries
## File description:
## Makefile
##

.SECONDEXPANSION:
LIB_DIR					:=	$(shell realpath lib)/
COMPILED_LIBS			:=	$(shell find $(LIB_DIR) -mindepth 1 -maxdepth 1	\
							 -type d ! -name ".*"							\
							| sed 's/$(subst /,\/,$(LIB_DIR))//')
COMPILED_LIBS_ARCHIVES	:=	$(shell echo $(COMPILED_LIBS) | tr '[:upper:]' '[:lower:]')
COMPILED_LIBS_ARCHIVES	:=	$(COMPILED_LIBS_ARCHIVES:%=$(LIB_DIR)lib%.a)

export LIB_DIR
export COMPILED_LIBS
export COMPILED_LIBS_ARCHIVES
