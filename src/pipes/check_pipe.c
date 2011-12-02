/*
** check_pipe.c for check pipe in /home/mille_j//42sh/src/pipes
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Nov 16 16:51:16 2010 john mille
** Last update Sun Dec 19 12:45:14 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "parser.h"
#include "tools.h"
#include "lexer.h"
#include "gets.h"
#include "my.h"

int		pipe_error(t_vars *test, int code)
{
  if (code == 1)
    {
      my_puterror(test->argv[0]);
      my_puterror(": Command not found.\n");
      test->prompt = my_xxfree(test->prompt);
      test->argv = my_xfree_tab(test->argv);
      free_t_vars(test);
    }
  else if (code == 2)
    my_puterror("Invalid Null Command.\n");
  return (KO);
}

int		check_pipe_nb(t_vars *v, char ** argv)
{
  int		nb;
  int		i;

  i = 0;
  nb = 0;
  while (v->prompt[i])
    {
      if (v->prompt[i] == '|')
	nb += 1;
      i += 1;
    }
  if (nb != (my_tablen(argv) - 1))
    {
      my_puterror("Invalid Command Null.\n");
      return (KO);
    }
  return (OK);
}

int		check_execs(t_vars *v, char **execs)
{
  t_vars	*test;
  int		i;

  i = -1;
  test = my_xmalloc(sizeof(*test));
  init_vars(test);
  while (execs[++i])
    {
      if ((test->argc = get_argc(execs[i])))
	{
	  test->prompt = my_strdup(execs[i]);
	  test->argv = get_argv(test->prompt);
	  test->alias = tab_cpy(v->alias);
	  lexer(test);
	  if (which_it_is(test) == SMTH_ELSE)
	    return (pipe_error(test, 1));
	  test->prompt = my_xxfree(test->prompt);
	  test->argv = my_xfree_tab(test->argv);
	}
      else
	return (pipe_error(test, 2));
    }
  free_t_vars(test);
  return (OK);
}

int		check_pipe(t_vars *v, char **argv)
{
  if (check_pipe_nb(v, argv) == OK)
    {
      if (check_execs(v, argv) == OK)
	return (OK);
    }
  return (KO);
}
