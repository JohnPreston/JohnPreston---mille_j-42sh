/*
** exec_builtins_env.c for builtin_env in /home/mille_j//rendu/c/42sh/src/exec
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Nov 14 01:48:51 2010 john mille
** Last update Sat Dec 18 22:13:44 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "builtins_env.h"
#include "my.h"

t_builtins_env	gl_builtins_env[] = {
  {1, 1, "unsetenv", my_unsetenv},
  {2, 2, "setenv", my_up_or_setenv},
  {3, 3, "env", my_env},
  {4, 4, NULL, NULL},
};

int		exec_builtins_env(t_vars *v)
{
  int		exe;
  int		i;

  i = 0;
  exe = 0;
  while (gl_builtins_env[i].name)
    {
      if (v->argc >= 1 && my_strcmp(v->argv[0], gl_builtins_env[i].name) == 0)
	exe = gl_builtins_env[i].func(v);
      i += 1;
    }
  return (exe);
}
