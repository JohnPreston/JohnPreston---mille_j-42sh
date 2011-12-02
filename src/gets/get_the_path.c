/*
** get_env_path.c for get_env_path in /home/mille_j//rendu/c/42sh/src/exec
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Nov 11 18:36:53 2010 john mille
** Last update Mon Dec 13 12:33:19 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "tools.h"
#include "gets.h"
#include "my.h"

char		**get_the_path(t_vars *v)
{
  char		**path_tab;
  char		*path_str;
  int		to_find;

  to_find = find_pos_in_env(v->env, "PATH");
  path_tab = NULL;
  if (to_find != NOT_FOUND)
    {
      path_str = my_strdup3(v->env[to_find], '=');
      path_tab = get_env_path(path_str);
      path_str = my_xxfree(path_str);
    }
  return (path_tab);
}
