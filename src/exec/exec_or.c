/*
** exec_and.c for exec and in /home/mille_j//42/src/exec
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Fri Dec  3 01:39:50 2010 john mille
** Last update Fri Dec 17 18:25:17 2010 john mille
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

  i = 0;
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
  my_puterror("Invalid Null Command.\n");
  return (EXIT_FAILURE);
}

static int	loop(t_vars *or, char **execs)
{
  int		exe;
  int		i;

  i = 0;
  exe = 1;
  while (execs[i] && exe)
    {
      if ((or->argc = get_argc(execs[i])))
  	{
  	  or->prompt = my_strdup(execs[i]);
  	  or->argv = get_argv(or->prompt);
	  lexer(or);
  	  exe = global_exec(or);
	  or->prompt = my_xxfree(or->prompt);
	  or->argv = my_xfree_tab(or->argv);
	}
      i += 1;
    }
  return (exe);
}

int		exec_or(t_vars *v)
{
  t_vars	*or;
  char		**execs;
  int		ok;
  int		exe;

  or = my_xmalloc(sizeof(*or));
  init_vars(or);
  execs = get_or_argv(v->prompt);
  ok = check_commands(execs);
  if (!ok)
    return (error());
  exe = loop(or, execs);
  execs = my_xfree_tab(execs);
  or = free_t_vars(or);
  return (exe);
}
