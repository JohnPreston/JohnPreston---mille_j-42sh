/*
** exec_and.c for exec and in /home/mille_j//42/src/exec
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Fri Dec  3 01:39:50 2010 john mille
** Last update Fri Dec 17 18:24:57 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "42sh.h"
#include "execs.h"
#include "lexer.h"
#include "gets.h"
#include "tools.h"
#include "my.h"

static int	check_commands(char **execs)
{
  int		i;

  i = 1;
  while (execs[i])
    {
      if (!get_argc(execs[i]))
	return (KO);
      i += 1;
    }
  return (OK);
}

static int	error()
{
  my_puterror("Invalid Command Null.\n");
  return (EXIT_FAILURE);
}

static int	loop(t_vars *and, char **execs)
{
  int		exe;
  int		i;

  i = 0;
  exe = 0;
  while (execs[i] && !exe)
    {
      if ((and->argc = get_argc(execs[i])))
  	{
  	  and->prompt = my_strdup(execs[i]);
  	  and->argv = get_argv(and->prompt);
	  lexer(and);
  	  exe = global_exec(and);
	  and->prompt = my_xxfree(and->prompt);
	  and->argv = my_xfree_tab(and->argv);
	}
      i += 1;
    }
  return (exe);
}

int		exec_and(t_vars *v)
{
  t_vars	*and;
  char		**execs;
  int		ok;
  int		exe;

  execs = get_and_argv(v->prompt);
  ok = check_commands(execs);
  and = my_xmalloc(sizeof(*and));
  init_vars(and);
  if (!ok)
    return (error());
  exe = loop(and, execs);
  execs = my_xfree_tab(execs);
  and = free_t_vars(and);
  return (exe);
}
