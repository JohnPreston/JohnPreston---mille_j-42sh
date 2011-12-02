/*
** exec_builtin_env.c for builtins env in /home/mille_j//rendu/c/42sh/src
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Oct  5 01:30:31 2010 john mille
** Last update Mon Dec 13 12:35:06 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "builtins_env.h"
#include "my.h"

t_builtins_env	gl_builtins_env2[] = {
  {1, 1, "unsetenv", my_unsetenv},
  {2, 2, "setenv", my_up_or_setenv},
  {3, 3, "env", my_env},
  {4, 4, NULL, NULL},
};

int		is_builtin_env(t_vars *v)
{
  int		i;

  i = 0;
  while (gl_builtins_env2[i].name)
    {
      if (v->argc >= 1 && my_strcmp(v->argv[0], gl_builtins_env2[i].name) == 0)
	return (BUILT_ENV);
      i += 1;
    }
  return (SMTH_ELSE);
}
