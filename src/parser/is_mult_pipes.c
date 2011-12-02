/*
** is_mult_pipes.c for is mult pipe in /home/mille_j//42/src/parser
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Fri Dec  3 03:41:27 2010 john mille
** Last update Thu Dec  9 17:47:07 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "tools.h"
#include "my.h"

int		is_mult_pipe(t_vars *v)
{
  int		nb;
  int		i;

  i = 0;
  nb = 0;
  while (v->argv[i])
    {
      if ((find_char(v->argv[i], '|') != -1 &&
	   my_strstr(v->argv[i], "|") != -1) ||
	  my_strcmp(v->argv[i], "|") == 0)
	nb += 1;
      i += 1;
    }
  if (nb >= 1)
    return (MULT_PIPE);
  return (SMTH_ELSE);
}
