/*
** free_t_vars.c for free t_vars * in /home/mille_j//42sh/src/exec
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Dec 15 11:57:31 2010 john mille
** Last update Wed Dec 15 23:59:31 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "tools.h"
#include "my.h"

t_vars		*free_t_vars(t_vars *v)
{
  v->cd_minus = my_xxfree(v->cd_minus);
  v->alias = my_xfree_tab(v->alias);
  v->env = my_xfree_tab(v->env);
  v = my_xfree(v);
  v = NULL;
  return (v);
}
