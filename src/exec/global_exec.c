/*
** global_exec.c for global_exec in /home/mille_j//rendu/c/42sh/src/exec
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Nov 14 01:54:17 2010 john mille
** Last update Sat Dec 18 17:42:30 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "lexer.h"
#include "redirs.h"
#include "parser.h"
#include "execs.h"
#include "my.h"

t_it_is		gl_it_is[] = {
  {1, MULT_EXEC, exec_mult_execs},
  {1, AND_BIN_O, exec_and},
  {1, OR_BIN_OP, exec_or},
  {1, DB_RE_LEF, db_redir_left},
  {1, REDI_LEFT, redir_left},
  {1, DB_RE_RIG, db_redir_right},
  {1, REDI_RIGH, redir_right},
  {1, MULT_PIPE, make_pipe},
  {1, BUILT_EXI, exec_builtin_exit},
  {1, BUILT_ENV, exec_builtins_env},
  {1, BUILT_CD, my_cd},
  {1, BUILT_ALI, exec_builtins_alias},
  {1, BUILT_ECH, my_echo},
  {1, PROG_SYST, exec_prog_syst},
  {0, SMTH_ELSE, NULL},
};

int		global_exec(t_vars *v)
{
  int		exe;
  int		is;
  int		i;

  i = 0;
  is = which_it_is(v);
  exe = EXIT_FAILURE;
  while (gl_it_is[i].id)
    {
      if (gl_it_is[i].is == is)
	{
	  exe = gl_it_is[i].func(v);
	  return (exe);
	}
      i += 1;
    }
  if (v->argc && is == SMTH_ELSE)
    {
      my_puterror(v->argv[0]);
      my_puterror(": Command Not Found.\n");
    }
  return (exe);
}
