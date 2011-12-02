/*
** exec_builtins_env.c for builtin_env in /home/mille_j//rendu/c/42sh/src/exec
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Nov 14 01:48:51 2010 john mille
** Last update Sun Dec 19 13:45:42 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "builtins_alias.h"
#include "my.h"

t_builtins_alias	gl_builtins_alias2[] = {
  {1, 1, "unalias", my_unsetalias},
  {1, 1, "alias", my_up_or_setalias},
  {0, 0, NULL, NULL},
};

int			exec_builtins_alias(t_vars *v)
{
  int			exe;
  int			i;

  i = 0;
  exe = 0;
  while (gl_builtins_alias2[i].name)
    {
      if (v->argc >= 1 &&
	  my_strcmp(v->argv[0], gl_builtins_alias2[i].name) == 0)
	exe = gl_builtins_alias2[i].func(v);
      i += 1;
    }
  return (exe);
}
