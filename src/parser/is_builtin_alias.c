/*
** exec_builtin_env.c for builtins env in /home/mille_j//rendu/c/42sh/src
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Oct  5 01:30:31 2010 john mille
** Last update Sun Dec 19 13:44:45 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "builtins_alias.h"
#include "my.h"

t_builtins_alias	gl_builtins_alias[] = {
  {1, 1, "unalias", my_unsetalias},
  {2, 2, "alias", my_up_or_setalias},
  {4, 4, NULL, NULL},
};

int		is_builtin_alias(t_vars *v)
{
  int		i;

  i = 0;
  while (gl_builtins_alias[i].name)
    {
      if (v->argc >= 1 &&
	  my_strcmp(v->argv[0], gl_builtins_alias[i].name) == 0)
	return (BUILT_ALI);
      i += 1;
    }
  return (SMTH_ELSE);
}
