/*
** check_builtins_env_syntax.c for check_builtins_env_syntax for 42sh in /home/mille_j//rendu/c/42sh/src
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 22:16:49 2010 john mille
** Last update Sun Dec 19 14:06:07 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "tools.h"
#include "builtins_alias.h"
#include "my.h"

int		check_setalias_syntax(t_vars *v)
{
  if (v->argc == 1 && my_strcmp(v->argv[0], "alias") == 0)
    {
      my_show_tab(v->alias, '\n');
      return (SYNTAX_KO);
    }
  else if ((v->argc >= 3 && v->argc <= 5) &&
	   find_char(v->argv[1], '=') == FOUND)
    {
      my_puterror("alias: Syntax Error.\n");
      return (SYNTAX_KO);
    }
  else if (v->argc > 5 || v->argc == 2)
    {
      my_puterror("alias: From 2 to 5 arguments max.\n");
      return (SYNTAX_KO);
    }
  return (SYNTAX_OK);
}

int		check_unsetalias_syntax(t_vars *v)
{
  if (v->argc == 1)
    return (SYNTAX_KO);
  else if (v->argc == 2 && my_strcmp(v->argv[1], "*") == 0)
    return (ALL);
  return (SYNTAX_OK);
}
