/*
** builtin_exit.c for builtin_exit in /home/mille_j//rendu/c/42sh/src/builtin_exit
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Nov 14 17:28:19 2010 john mille
** Last update Sat Dec 18 19:29:15 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "my.h"

void		exit_and_free_all(t_vars *v, int val)
{
  v->cd_minus = my_xxfree(v->cd_minus);
  v->alias = my_xfree_tab(v->alias);
  v->env = my_xfree_tab(v->env);
  v->argv = my_xfree_tab(v->argv);
  v->prompt = my_xxfree(v->prompt);
  v = my_xfree(v);
  v = NULL;
  exit(val);
}

int		str_is_num(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	return (1);
      i += 1;
    }
  return (0);
}

int		exec_builtin_exit(t_vars *v)
{
  int		tmp;

  if (v->argc == 2 && !str_is_num(v->argv[1]))
    my_puterror("exit: Expression Syntax.\n");
  if (v->argc == 1)
    exit_and_free_all(v, EXIT_SUCCESS);
  else if (v->argc == 2 && str_is_num(v->argv[1]))
    {
      tmp = my_getnbr(v->argv[1]);
      exit_and_free_all(v, tmp);
    }
  return (EXIT_FAILURE);
}
