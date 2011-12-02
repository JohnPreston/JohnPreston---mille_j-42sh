/*
** is_mult_execs.c for is mult execs in /home/mille_j//rendu/c/42sh/src/parser
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Nov 14 16:02:32 2010 john mille
** Last update Thu Dec 16 09:08:44 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "tools.h"
#include "my.h"

int		is_mult_execs(t_vars *v)
{
  int		i;

  i = 0;
  while (v->argv[i])
    {
      if ((find_char(v->argv[i], ';') != -1 &&
	   my_strstr(v->argv[i], ";") != -1) ||
	  my_strcmp(v->argv[i], ";") == 0)
	return (MULT_EXEC);
	i += 1;
    }
  return (SMTH_ELSE);
}
