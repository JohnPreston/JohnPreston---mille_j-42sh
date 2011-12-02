/*
** is_builtin_cd.c for is builtin cd in /home/mille_j//rendu/c/42sh/src/parser
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Nov 14 17:37:41 2010 john mille
** Last update Sun Nov 14 17:40:17 2010 john mille
*/

#include "42sh.h"
#include "my.h"

int		is_builtin_exit(t_vars *v)
{
  if (v->argc <= 2 && my_strcmp(v->argv[0], "exit") == 0)
    return (BUILT_EXI);
  return (SMTH_ELSE);
}
