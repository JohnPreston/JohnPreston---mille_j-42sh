/*
** tool3.c for tools in /home/mille_j//rendu/c/42sh/src/builtin_cd
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Nov  9 15:24:05 2010 john mille
** Last update Fri Dec 17 14:09:39 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"
#include "lexer.h"
#include "my.h"

int		find_char(char *str, char c)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (FOUND);
      i += 1;
    }
  return (NOT_FOUND);
}

static int	char_ok(char c)
{
  if (c != '.' || c != '/')
    return (1);
  return (0);
}

int		these_chars_only(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (char_ok(str[i]))
	return (1);
      i += 1;
    }
  return (0);
}

int		my_xchdir(const char *path)
{
  int		cd;

  cd = chdir(path);
  if (cd == -1)
    {
      my_puterror("Unable to change directory.\n");
      return (0);
    }
  return (1);
}
