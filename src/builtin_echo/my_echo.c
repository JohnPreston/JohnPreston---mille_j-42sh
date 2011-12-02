/*
** echo.c for echo in /home/mille_j//42sh/src/builtin_echo
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Nov 17 15:56:50 2010 john mille
** Last update Sat Dec 18 19:58:48 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "my.h"

int		my_echo(t_vars *v)
{
  int		i;

  i = 1;
  if (!my_strcmp(v->argv[1], "-n"))
    i = 2;
  while (v->argv[i + 1])
    {
      my_putstr(v->argv[i]);
      my_putchar(' ');
      i += 1;
    }
  my_putstr(v->argv[i]);
  if (my_strcmp(v->argv[1], "-n"))
    my_putstr("\n");
  return (EXIT_SUCCESS);
}
