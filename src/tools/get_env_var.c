/*
** get_env_var.c for get env var in /home/mille_j//42sh/src/builtin_cd
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Nov 16 22:10:26 2010 john mille
** Last update Tue Nov 16 23:32:33 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "tools.h"
#include "my.h"

char		*get_env_var(t_vars *v, char *find)
{
  char		*var;
  int		to_find;

  var = NULL;
  to_find = find_pos_in_env(v->env, find);
  if (to_find != NOT_FOUND)
    var = my_strdup3(v->env[to_find], '=');
  return (var);
}
