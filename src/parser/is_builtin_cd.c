/*
** is_builtin_cd.c for builtin cd in /home/mille_j//42sh/src/parser
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Nov 16 23:06:10 2010 john mille
** Last update Tue Nov 16 23:37:30 2010 john mille
*/

#include "42sh.h"
#include "my.h"

int		is_builtin_cd(t_vars *v)
{
  if (my_strcmp(v->argv[0], "cd") == 0)
    return (BUILT_CD);
  return (SMTH_ELSE);
}
