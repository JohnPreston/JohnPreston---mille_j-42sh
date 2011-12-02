/*
** exec_mult_execs.c for mult execs in /home/mille_j//rendu/c/42sh/src/exec
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Nov 14 15:55:10 2010 john mille
** Last update Sat Dec 18 22:00:18 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "gets.h"
#include "parser.h"
#include "execs.h"
#include "lexer.h"
#include "tools.h"
#include "my.h"

static int	loop(t_vars *mult, char **execs)
{
  int		exe;
  int		i;

  i = 0;
  exe = 0;
  while (execs[i])
    {
      if ((mult->argc = get_argc(execs[i])))
	{
	  mult->prompt = my_strdup(execs[i]);
	  mult->argv = get_argv(execs[i]);
	  lexer(mult);
	  exe = global_exec(mult);
	  mult->prompt = my_xxfree(mult->prompt);
	  mult->argv = my_xfree_tab(mult->argv);
	}
      i += 1;
    }
  return (exe);
}

int		exec_mult_execs(t_vars *v)
{
  t_vars	*mult;
  char		**execs;
  int		exe;

  execs = get_mult_argv(v->prompt);
  mult = my_xmalloc(sizeof(*mult));
  init_vars(mult);
  exe = loop(mult, execs);
  execs = my_xfree_tab(execs);
  mult = free_t_vars(mult);
  return (exe);
}
