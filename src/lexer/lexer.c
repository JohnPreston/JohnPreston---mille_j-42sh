/*
** lexer.c for lexer in /home/mille_j//rendu/c/42sh/src/lexer
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Nov 14 19:27:53 2010 john mille
** Last update Sun Dec 19 20:47:55 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "builtins_alias.h"
#include "tools.h"
#include "parser.h"
#include "lexer.h"
#include "my.h"

void		lexer(t_vars *v)
{
  static int	loop;

  if (v->alias && which_it_is(v) != BUILT_ALI)
    {
      if (loop < 10 && is_there_an_alias(v))
	{
	  loop += 1;
	  build_argv(v);
	  lexer(v);
	}
      else if (loop == 10)
	loop = 0;
    }
  else if (there_is_home(v))
    modify_prompt_for_home(v);
  loop = 0;
}
