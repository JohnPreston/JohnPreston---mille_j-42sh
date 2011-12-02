/*
** get_alias.c for get_alias in /home/mille_j//rendu/c/42sh/src/bonus_alias
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Nov 14 19:13:09 2010 john mille
** Last update Fri Dec 17 18:50:15 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "tools.h"
#include "my.h"

char		*get_alias(t_vars *v, char *searched)
{
  char		*alias;
  int		to_find;

  alias = NULL;
  to_find = find_pos_in_env(v->alias, searched);
  if (to_find != NOT_FOUND)
    alias = my_strdup3(v->alias[to_find], '=');
  return (alias);
}
