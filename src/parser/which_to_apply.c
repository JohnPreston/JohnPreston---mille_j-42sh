/*
** which_to_apply.c for which to appluy in /home/mille_j//rendu/c/42sh/src/parser
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Nov 11 19:38:47 2010 john mille
** Last update Thu Dec 16 09:56:32 2010 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "42sh.h"
#include "lexer.h"
#include "parser.h"
#include "my.h"

t_it_is		gl_it_is2[] = {
  {1, MULT_EXEC, is_mult_execs},
  {1, OPERA_BIN, which_one_in_first},
  {1, DB_RE_LEF, is_dble_redir_left},
  {1, REDI_LEFT, is_redir_left},
  {1, DB_RE_RIG, is_dble_redir_right},
  {1, REDI_RIGH, is_redir_right},
  {1, MULT_PIPE, is_mult_pipe},
  {1, BUILT_EXI, is_builtin_exit},
  {1, BUILT_ALI, is_builtin_alias},
  {1, BUILT_CD, is_builtin_cd},
  {1, BUILT_ENV, is_builtin_env},
  {1, BUILT_ECH, is_builtin_echo},
  {1, PROG_SYST, is_prog_syst},
  {0, SMTH_ELSE, NULL},
};

int		which_it_is(t_vars *v)
{
  int		i;

  i = 0;
  while (gl_it_is2[i].id)
    {
      if (gl_it_is2[i].func(v) == gl_it_is2[i].is)
	return (gl_it_is2[i].func(v));
      i += 1;
    }
  return (SMTH_ELSE);
}
