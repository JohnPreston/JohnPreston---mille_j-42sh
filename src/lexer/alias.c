/*
** alias.c for alias in /home/mille_j//42sh/src/lexer
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sat Dec 18 20:33:53 2010 john mille
** Last update Sat Dec 18 20:34:40 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "builtins_alias.h"
#include "lexer.h"
#include "tools.h"
#include "gets.h"
#include "my.h"

void		build_argv(t_vars *v)
{
  char		*alias;
  int		i;

  i = is_there_an_alias(v);
  if (i)
    {
      alias = get_alias(v, v->argv[i - 1]);
      v->argv = update_elem_in_tab(v->argv, alias, (i - 1));
      alias = my_xxfree(alias);
      v->prompt = my_xxfree(v->prompt);
      v->prompt = concat_tab_elems(v->argv, " ");
      v->argv = my_xfree_tab(v->argv);
      v->argc = get_argc(v->prompt);
      v->argv = get_argv(v->prompt);
    }
}

int		is_there_an_alias(t_vars *v)
{
  char		*tmp;
  int		i;
  int		j;

  i = 0;
  while (v->argv[i])
    {
      j = 0;
      while (v->alias[j])
	{
	  tmp = my_strdup2(v->alias[j], '=');
	  if (my_strcmp(v->argv[i], tmp) == 0)
	    {
	      tmp = my_xxfree(tmp);
	      return (i + 1);
	    }
	  tmp = my_xxfree(tmp);
	  j += 1;
      	}
      i += 1;
    }
  return (KO);
}
