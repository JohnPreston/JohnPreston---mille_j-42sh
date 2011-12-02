/*
** my_builtins_env.c for my_builtins_env.c in /home/mille_j//rendu/c/42sh/src
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 22:10:31 2010 john mille
** Last update Sun Dec 19 13:44:59 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "builtins_alias.h"
#include "tools.h"
#include "my.h"

int		my_setalias(t_vars *v)
{
  t_alias_vars	c;

  if (check_setalias_syntax(v) == SYNTAX_KO)
    return (EXIT_FAILURE);
  else
    {
      c.tmp = my_strcat(v->argv[1], "=");
      c.tmp2 = nconcat_tab_elems(v->argv, " ", 2, v->argc);
      c.elem = my_strcat(c.tmp, c.tmp2);
      v->alias = add_elem_to_tab(v->alias, c.elem);
      c.tmp = my_xxfree(c.tmp);
      c.tmp2 = my_xxfree(c.tmp2);
      c.elem = my_xxfree(c.elem);
    }
  return (EXIT_SUCCESS);
}

int		my_unsetalias(t_vars *v)
{
  int		to_find;
  int		i;

  i = 1;
  if (check_unsetalias_syntax(v) == ALL)
    {
      v->alias = my_xfree_tab(v->alias);
      v->alias = my_xmalloc(sizeof(*v->alias));
      v->alias[0] = NULL;
    }
  if (check_unsetalias_syntax(v) == SYNTAX_KO)
    return (EXIT_FAILURE);
  else
    {
      while (v->argv[i])
	{
	  to_find = find_pos_in_env(v->alias, v->argv[i]);
	  if (to_find != NOT_FOUND)
	    v->alias = delete_elem_in_tab(v->alias, to_find);
	  i += 1;
	}
    }
  return (EXIT_SUCCESS);
}

int		my_update_alias(t_vars *v, int to_find)
{
  t_alias_vars	c;

  c.elem = NULL;
  if (check_setalias_syntax(v) == SYNTAX_KO ||
      to_find == NOT_FOUND)
    return (EXIT_FAILURE);
  else
    {
      c.tmp = my_strcat(v->argv[1], "=");
      c.tmp2 = nconcat_tab_elems(v->argv, " ", 2, v->argc);
      c.elem = my_strcat(c.tmp, c.tmp2);
      v->alias = update_elem_in_tab(v->alias, c.elem, to_find);
      c.tmp = my_xxfree(c.tmp);
      c.tmp2 = my_xxfree(c.tmp2);
      c.elem = my_xxfree(c.elem);
    }
  return (EXIT_SUCCESS);
}

int		my_up_or_setalias(t_vars *v)
{
  int		exec;
  int		to_find;

  to_find = find_pos_in_env(v->alias, v->argv[1]);
  if (to_find != NOT_FOUND)
    exec = my_update_alias(v, to_find);
  else
    exec = my_setalias(v);
  return (exec);
}
