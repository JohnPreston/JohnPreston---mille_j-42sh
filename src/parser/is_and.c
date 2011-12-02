/*
** is_and.c for is and in /home/mille_j//42/src/parser
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Fri Dec  3 01:52:37 2010 john mille
** Last update Thu Dec  9 18:23:56 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "tools.h"
#include "my.h"

int		is_and(t_vars *v)
{
  int		i;

  i = 0;
  while (v->argv[i])
    {
      if ((find_char(v->argv[i], '&') != -1 &&
	   my_strstr(v->argv[i], "&&") != -1) ||
	  my_strcmp(v->argv[i], "&&") == 0)
	return (AND_BIN_O);
      i += 1;
    }
  return (SMTH_ELSE);
}
