/*
** env_tools.c for env tools in /home/mille_j//rendu/c/42sh/src/tools
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Nov 11 16:55:11 2010 john mille
** Last update Fri Dec  3 18:39:56 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "my.h"

int		find_pos_in_env(char **env, char *to_find)
{
  int		i;

  i = 0;
  if (!env)
    return (NOT_FOUND);
 if (!to_find)
   return (NOT_FOUND);
 while (env[i])
    {
      if (my_strncmp(env[i], to_find, my_strlen2(env[i], '=')) == 0 &&
	  my_strlen(to_find) == my_strlen2(env[i], '='))
	return (i);
      i += 1;
    }
  return (NOT_FOUND);
}
