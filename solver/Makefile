##
## EPITECH PROJECT, 2022
## Solver
## File description:
## Makefile
##

.SECONDEXPANSION:
PROGRAM					:=	solver
DISPLAY_NAME			:=	Solver
TEST_PROGRAM			:=	$(PROGRAM)_tests
TESTS_DIR				:=	$(wildcard tests/)

IGNORE_FILE				:=	.gitignore
CONDING_STYLE_LOG		:=	coding-style-reports.log

$(PROGRAM)_SRCS			:=	$(patsubst ./%,%,$(shell find -type f			\
							-name '*.c' ! -name ".*"))
$(TEST_PROGRAM)_SRCS	:=	$(shell find $(TESTS_DIR) -type f				\
							-name 'test_*.c' ! -name ".*" ! -name "main.c")

$(PROGRAM)_OBJS			:=	$($(PROGRAM)_SRCS:.c=.o)
$(TEST_PROGRAM)_OBJS	:=	$($(TEST_PROGRAM)_SRCS:.c=.o)

$(PROGRAM)_DEPS			:=	$($(PROGRAM)_SRCS:.c=.d)
$(TEST_PROGRAM)_DEPS	:=	$($(TEST_PROGRAM)_SRCS:.c=.d)
LIBS					:=	$(COMPILED_LIBS)
INCLUDE_DIRS			:=	../include/ ./
RM						:=	rm -f
CC						:=	gcc
CFLAGS					=	$(INCLUDE_DIRS:%=-I%)							\
							-W -Wall -Wextra -Wduplicated-cond				\
							-Wduplicated-branches -Wlogical-op				\
							-Wnull-dereference -Wjump-misses-init			\
							-Wdouble-promotion -Wshadow -Wformat=2
LDLIBS					=	$(shell echo $(LIBS:%=-l%) | tr '[:upper:]'		\
							'[:lower:]')
LDFLAGS					:=	$(LIB_DIR:%=-L%)

all:						$(IGNORE_FILE) $(PROGRAM)
	@:

debug:						CFLAGS += -g
debug:						all

define \n


endef
define $(IGNORE_FILE)_CONTENT
##
## EPITECH PROJECT, 2022
## $(DISPLAY_NAME)
## File description:
## $(IGNORE_FILE)
##

# Ignore object files
$(shell echo -e '$($(PROGRAM)_OBJS)' | sed -E 's/ /\\n/g')
$(shell echo -e '$($(TEST_PROGRAM)_OBJS)' | sed -E 's/ /\\n/g')

# Ignore dependency files
$(shell echo -e '$($(PROGRAM)_DEPS)' | sed -E 's/ /\\n/g')
$(shell echo -e '$($(TEST_PROGRAM)_DEPS)' | sed -E 's/ /\\n/g')

# Ignore binary files
$(PROGRAM)
$(TEST_PROGRAM)
a.out

# Ignore coverage reports
*.gc*

# Ignore coding-style logs
$(CONDING_STYLE_LOG)
endef

$(IGNORE_FILE):
	@-echo 'Generating $@ file...'
	@echo -e "$(subst ${\n},\n,$($@_CONTENT))" > $@

LINK_ECHO				=	Linking ./$@ binary...
NO_LINK_ECHO			=	No linking for ./$@.

$(TEST_PROGRAM):			LIBS += criterion

$(PROGRAM) $(TEST_PROGRAM):	LINK := true
$(PROGRAM) $(TEST_PROGRAM): $(COMPILED_LIBS_ARCHIVES) $$($$@_OBJS)
	@-echo '$(if $(LINK),$(LINK_ECHO),$(NO_LINK_ECHO))'
	@$(if $(LINK),$(CC) $(CFLAGS) -o $@ $($@_OBJS) $(LDLIBS) $(LDFLAGS),)

%.o:						%.c %.d
	@-echo 'Compiling $<...'
	@$(CC) -c $(CFLAGS) $< -o $@

%.d:						%.c
	@-echo 'Generating dependencies for $<...'
	@$(CC) $< -MM -MF $@ $(CFLAGS)

-include $($(PROGRAM)_DEPS) $($(TEST_PROGRAM)_DEPS)

$(COMPILED_LIBS_ARCHIVES):
	@-echo 'Compiling $(@:$(LIB_DIR)lib%.a=%) library archive ($@)...'
	@$(MAKE) -C $(LIB_DIR) $(@:$(LIB_DIR)lib%.a=%)

coding-style:				fclean
	@-echo 'Checking coding style...'
	@coding-style.sh . .

tests_run:					$(TEST_PROGRAM)
	@./$(TEST_PROGRAM) --verbose --always-succeed

tests_debug:				CFLAGS += -g
tests_debug:				$(TEST_PROGRAM)
	@-valgrind --trace-children=yes								\
	./$(TEST_PROGRAM) --verbose --always-succeed

coverage:					CFLAGS += --coverage
coverage:					tests_run
	@gcovr --exclude $(TESTS_DIR)
	@gcovr --exclude $(TESTS_DIR) --branches

clean:
	@$(RM) $($(PROGRAM)_OBJS) $($(TEST_PROGRAM)_OBJS)			\
	$($(PROGRAM)_DEPS) $($(TEST_PROGRAM)_DEPS)
	@-echo 'Cleaned-up objects and dependency files.'
	@find . -name '*~' -name 'vgcore.*' -name '*.gc*'			\
	-name 'a.out' -name '$(CONDING_STYLE_LOG)' -delete
	@-echo 'Cleaned-up unecessary files.'

fclean:						clean
	@$(RM) $(PROGRAM)
	@-echo 'Program deleted.'
	@$(RM) $(TEST_PROGRAM)
	@-echo 'Test program deleted.'

re:							fclean all

re_tests:					fclean tests_run

.PHONY:						all debug tests_run tests_debug	\
							clean fclean re re_tests libs	\
							coverage coding-style
