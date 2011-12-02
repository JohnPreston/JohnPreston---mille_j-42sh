/*
** is_refir_right.c for redir in /home/mille_j//42sh/src/redir
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Fri Nov 26 14:00:38 2010 john mille
** Last update Tue Dec 14 11:02:24 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "tools.h"
#include "my.h"

int		is_redir_right(t_vars *v)
{
  int		i;

  i = 0;
  while (v->argv[i])
    {
      if ((find_char(v->argv[i], '>') != -1 &&
	   my_strstr(v->argv[i], ">") != -1) ||
	  my_strcmp(v->argv[i], ">") == 0)
	return (REDI_RIGH);
      i += 1;
    }
  return (SMTH_ELSE);
}

int		is_dble_redir_right(t_vars *v)
{
  int		i;

  i = 0;
  while (v->argv[i])
    {
      if ((find_char(v->argv[i], '>') != -1 &&
	   my_strstr(v->argv[i], ">>") != -1) ||
	  my_strcmp(v->argv[i], ">>") == 0)
	return (DB_RE_RIG);
      i += 1;
    }
  return (SMTH_ELSE);
}

int		is_redir_left(t_vars *v)
{
  int		i;

  i = 0;
  while (v->argv[i])
    {
      if ((find_char(v->argv[i], '<') != -1 &&
	   my_strstr(v->argv[i], "<") != -1) ||
	  my_strcmp(v->argv[i], "<") == 0)
	return (REDI_LEFT);
      i += 1;
    }
  return (SMTH_ELSE);
}

int		is_dble_redir_left(t_vars *v)
{
  int		i;

  i = 0;
  while (v->argv[i])
    {
      if ((find_char(v->argv[i], '<') != -1 &&
	   my_strstr(v->argv[i], "<<") != -1) ||
	  my_strcmp(v->argv[i], "<<") == 0)
	return (DB_RE_LEF);
      i += 1;
    }
  return (SMTH_ELSE);
}
