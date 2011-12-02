/*
** is_builtin_echo.c for is_builtin_echo in /home/mille_j//42sh/src/parser
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Nov 17 15:59:22 2010 john mille
** Last update Wed Nov 17 16:08:13 2010 john mille
*/

#include "42sh.h"
#include "my.h"

int		is_builtin_echo(t_vars *v)
{
  if (v->argc >= 1 && my_strcmp(v->argv[0], "echo") == 0)
    return (BUILT_ECH);
  return (SMTH_ELSE);
}
