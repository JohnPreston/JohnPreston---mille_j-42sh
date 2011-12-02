/*
** home.c for home in /home/mille_j//42sh/src/lexer
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Nov 17 19:44:46 2010 john mille
** Last update Sun Dec 12 15:19:01 2010 john mille
*/

#include "42sh.h"
#include "tools.h"
#include "my.h"

int		there_is_home(t_vars *v)
{
  int		i;

  i = 0;
  while (v->argv[i])
    {
      if (find_char(v->argv[i], '~') == FOUND)
	return (LEXER_HOME);
      i += 1;
    }
  return (NOT_IN_LEXE);
}

void		modify_prompt_for_home(t_vars *v)
{
  char		*home;
  char		*tmp;
  int		i;

  i = 0;
  home = get_home(v);
  while (v->argv[i])
    {
      if (find_char(v->argv[i], '~') == FOUND)
	{
	  tmp = my_strdup3(v->argv[i], '~');
	  v->argv[i] = my_xxfree(v->argv[i]);
	  v->argv[i] = my_strcat(home, tmp);
	  tmp = my_xxfree(tmp);
	}
      i += 1;
    }
  home = my_xxfree(home);
}
