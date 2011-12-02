/*
** xfunc.c for xfunc in /home/mille_j//42sh/src/tools
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Dec  9 15:00:50 2010 john mille
** Last update Thu Dec  9 15:11:20 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "my.h"

int		my_xpipe(int fd[2])
{
  int		xpipe;

  xpipe = pipe(fd);
  if (xpipe == -1)
    {
      my_puterror("Unable to create the pipe.\n");
      exit(EXIT_FAILURE);
    }
  return (xpipe);
}

int		my_xdup2(int fd1, int fd2)
{
  int		xdup2;

  xdup2 = dup2(fd1, fd2);
  if (xdup2 == -1)
    {
      my_puterror("Unable to dup2() the fds.\n");
      exit(EXIT_FAILURE);
    }
  return (xdup2);
}

pid_t		my_xfork()
{
  int		xfork;

  xfork = fork();
  if (xfork == -1)
    my_puterror("Unable to fork() a child.\n");
  return (xfork);
}
