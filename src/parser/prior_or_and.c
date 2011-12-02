/*
** prior_or_and.c for priorite entre && et || in /home/mille_j//42/src/parser
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Fri Dec  3 02:30:09 2010 john mille
** Last update Fri Dec  3 03:03:46 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "parser.h"
#include "my.h"

int		which_one_in_first(t_vars *v)
{
  static int	pass;
  int		pos_and;
  int		pos_or;

  if (is_and(v) || is_or(v))
    {
      if (pass == 0)
	{
	  pass = 1;
	  return (OPERA_BIN);
	}
      pos_and = my_strstr(v->prompt, "&&");
      pos_or = my_strstr(v->prompt, "||");
      pass = 0;
      if (pos_and < 0)
	return (OR_BIN_OP);
      else if (pos_or < 0)
	return (AND_BIN_O);
      else if ((pos_and >= 0 && pos_or >= 0) && pos_or < pos_and)
	return (OR_BIN_OP);
      else if ((pos_and >= 0 && pos_or >= 0) && pos_and < pos_or)
	return (AND_BIN_O);
    }
  return (SMTH_ELSE);
}
