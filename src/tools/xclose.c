/*
** xclose.c for my_xclose in /home/mille_j//42sh/src/tools
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sat Dec 18 20:39:39 2010 john mille
** Last update Sat Dec 18 20:47:41 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>

int		my_xclose(const int fd)
{
  int		xclose;

  xclose = close(fd);
  if (xclose == -1)
    return (EXIT_SUCCESS);
  return (EXIT_SUCCESS);
}
