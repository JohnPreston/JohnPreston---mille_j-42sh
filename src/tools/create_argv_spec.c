/*
** create_argv_spec.c for create argv spec in /home/mille_j//42sh/src/redir
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Fri Nov 26 14:57:54 2010 john mille
** Last update Fri Nov 26 15:01:05 2010 john mille
*/

#include <stdlib.h>
#include "tools.h"
#include "my.h"

char		**create_argv1(t_vars *v, char *str)
{
  char		**new;
  int		i;

  i = 0;
  new = my_xmalloc(sizeof(*new));
  new[0] = NULL;
  while (v->argv[i] && my_strcmp(v->argv[i], str))
    {
      if (my_strcmp(v->argv[i], str))
	new = add_elem_to_tab(new, v->argv[i]);
      i += 1;
    }
  return (new);
}

char		**create_argv2(t_vars *v, char *str)
{
  char		**new;
  int		i;

  i = 0;
  new = my_xmalloc(sizeof(*new));
  new[0] = NULL;
  while (v->argv[i] && my_strcmp(v->argv[i], str))
    i += 1;
  i += 1;
  while (v->argv[i])
    {
      new = add_elem_to_tab(new, v->argv[i]);
      i += 1;
    }
  return (new);
}
