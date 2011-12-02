## Makefile for makefile in /home/mille_j//rendu/c/42sh
## 
## Made by john mille
## Login   <John@epitech.net>
## 
## Started on  Thu Nov 11 16:51:00 2010 john mille
## Last update Sun Dec 19 20:51:42 2010 john mille
##

NAME		=		42sh

SRCDIR		=		./src/
HDDIR		=		./include/
LDDIR		=		./lib/
BONUS		=		$(SRCDIR)bonus/
BONUS_ALIAS	=		$(SRCDIR)bonus_alias/
BUILTIN_CD	=		$(SRCDIR)builtin_cd/
BUILTIN_ECHO	=		$(SRCDIR)builtin_echo/
BUILTIN_ENV	=		$(SRCDIR)builtin_env/
BUILTIN_EXIT	=		$(SRCDIR)builtin_exit/
EXEC		=		$(SRCDIR)exec/
GETS		=		$(SRCDIR)gets/
LEXER		=		$(SRCDIR)lexer/
PARSER		=		$(SRCDIR)parser/
PIPES		=		$(SRCDIR)pipes/
REDIR		=		$(SRCDIR)redir/
TOOLS		=		$(SRCDIR)/tools/

SRCS		=		$(SRCDIR)/main/42sh.c				\
				$(LDDIR)my_getnbr.c				\
				$(LDDIR)my_memset.c				\
				$(LDDIR)my_put_tools.c				\
				$(LDDIR)my_strcat.c				\
				$(LDDIR)my_strcmp.c				\
				$(LDDIR)my_strcpy.c				\
				$(LDDIR)my_strdup.c				\
				$(LDDIR)my_strlen.c				\
				$(LDDIR)my_xfree.c				\
				$(LDDIR)my_xmalloc.c				\
				$(LDDIR)tab_tools.c				\
				$(BONUS)write_prompt.c				\
				$(BONUS)get_conf_file.c				\
				$(BONUS_ALIAS)check_alias_syntax.c		\
				$(BONUS_ALIAS)my_alias.c			\
				$(BONUS_ALIAS)get_alias.c			\
				$(BUILTIN_CD)my_cd.c				\
				$(BUILTIN_CD)make_pwd.c				\
				$(BUILTIN_CD)go_from_root.c			\
				$(BUILTIN_ECHO)my_echo.c			\
				$(BUILTIN_ENV)check_builtins_env_syntax.c	\
				$(BUILTIN_ENV)my_builtins_env.c			\
				$(BUILTIN_EXIT)builtin_exit.c			\
				$(EXEC)exec_builtins_alias.c			\
				$(EXEC)exec_builtins_env.c			\
				$(EXEC)exec_prog_syst.c				\
				$(EXEC)global_exec.c				\
				$(EXEC)exec_mult_execs.c			\
				$(EXEC)exec_and.c				\
				$(EXEC)exec_or.c				\
				$(EXEC)exec_return.c				\
				$(GETS)get_the_path.c				\
				$(GETS)get_argc_argv.c				\
				$(GETS)get_mult_exec.c				\
				$(GETS)get_env_path.c				\
				$(GETS)get_cd_path.c				\
				$(GETS)get_and_argv.c				\
				$(GETS)get_or_argv.c				\
				$(GETS)get_pipes_execs.c			\
				$(GETS)get_redir_right_argv.c			\
				$(GETS)get_redir_left_argv.c			\
				$(GETS)get_file_lines.c				\
				$(LEXER)lexer.c					\
				$(LEXER)alias.c					\
				$(LEXER)home.c					\
				$(LEXER)strstr.c				\
				$(PARSER)which_to_apply.c			\
				$(PARSER)is_mult_execs.c			\
				$(PARSER)is_builtin_cd.c			\
				$(PARSER)is_builtin_echo.c			\
				$(PARSER)is_builtin_env.c			\
				$(PARSER)is_builtin_alias.c			\
				$(PARSER)is_exec.c				\
				$(PARSER)is_builtin_exit.c			\
				$(PARSER)is_redir.c				\
				$(PARSER)is_and.c				\
				$(PARSER)is_or.c				\
				$(PARSER)prior_or_and.c				\
				$(PARSER)is_mult_pipes.c			\
				$(PIPES)pipe.c					\
				$(PIPES)check_pipe.c				\
				$(REDIR)check_error.c				\
				$(REDIR)db_redir_left.c				\
				$(REDIR)db_redir_right.c			\
				$(REDIR)do_db_r_l.c				\
				$(REDIR)do_db_r_r.c				\
				$(REDIR)do_redir_left.c				\
				$(REDIR)do_redir_right.c			\
				$(REDIR)redir_tools2.c				\
				$(REDIR)redir_tools.c				\
				$(REDIR)simp_redir.c				\
				$(TOOLS)get_env_var.c				\
				$(TOOLS)init_vars.c				\
				$(TOOLS)env_tools.c				\
				$(TOOLS)get_prompt.c				\
				$(TOOLS)tools.c					\
				$(TOOLS)create_argv_spec.c			\
				$(TOOLS)get_home.c				\
				$(TOOLS)get_file.c				\
				$(TOOLS)get_pwd.c				\
				$(TOOLS)tab_functions.c				\
				$(TOOLS)tab_tools.c				\
				$(TOOLS)xclose.c				\
				$(TOOLS)xfunc.c					\
				$(TOOLS)free_t_vars.c

OBJS		=		$(SRCS:.c=.o)
CC		=		/usr/bin/gcc
CFLAGS		=		-W -Wall -Werror
HDFLAGS		+=		-I$(HDDIR)

RM		=		rm -f
ECHO		=		echo -e
TAG		=		etags

NORME		=		/home/mille_j/norme -nocheat

$(NAME)		: $(OBJS)
		-@$(CC) $(CFLAGS) $(HDFLAGS) -o $(NAME) $(OBJS)
		@$(ECHO) '\033[0;32m> Compiled Without Error\033[0m'

clean		:
		-@$(RM) $(OBJS)
		-@$(RM) *~
		-@$(RM) #*#
		@$(ECHO) '\033[0;35m> Directory cleaned\033[0m'

all		: $(NAME)

fclean		: clean
		-@$(RM) $(NAME)
		@$(ECHO) '\033[0;35m> Remove executable\033[0m'

norme		:
		$(NORME) $(SRCS)

re		: fclean all

.PHONY		: all clean re fclean tag debug

tag		:
		-@$(TAG) $(SRCS)
		@$(ECHO) '\033[0;32m> TAGS Done\033[0m'
.c.o		:
		-@$(CC) $(CFLAGS) $(HDFLAGS) -c $< -o $@
