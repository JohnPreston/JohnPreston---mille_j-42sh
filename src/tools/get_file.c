/*
** get_file.c for get file in /home/mille_j//42sh/src/tools
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Dec  1 21:11:30 2010 john mille
** Last update Thu Dec 16 13:59:18 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "42sh.h"
#include "my.h"

int		my_xopen(const char *path)
{
  int		fd;

  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (-1);
  return (fd);
}

int		my_xopen2(const char *path)
{
  int		fd;

  fd = open(path, O_RDWR | O_TRUNC | O_CREAT, 00644);
  if (fd == -1)
    return (-1);
  return (fd);
}

int		my_xopen3(const char *path)
{
  int		fd;

  fd = open(path, O_WRONLY | O_APPEND | O_CREAT, 00644);
  if (fd == -1)
    return (-1);
  return (fd);
}

int		my_xwrite(const int fd, char *str, unsigned int len)
{
  int		nb_write;

  nb_write = write(fd, str, len);
  if (nb_write == -1)
    {
      my_puterror("unable to write in the file descriptor given.\n");
      return (-1);
    }
  return (nb_write);
}

char		*get_file(const char *path)
{
  char		*prompt;
  char		*buff;
  char		*tmp;
  int		nb_read;
  int		fd;

  fd = my_xopen(path);
  if (fd == -1)
    fd = my_xopen3(path);
  prompt = my_xxmalloc(sizeof(*prompt));
  buff = my_xxmalloc(BUFF_SIZE * sizeof(*buff));
  nb_read = my_xread(fd, buff, BUFF_SIZE);
  while (nb_read == BUFF_SIZE)
    {
      tmp = prompt;
      prompt = my_strcat(tmp, buff);
      tmp = my_xxfree(tmp);
      my_memset(buff, '\0', BUFF_SIZE);
      nb_read = my_xread(fd, buff, BUFF_SIZE);
    }
  tmp = prompt;
  prompt = my_strcat(tmp, buff);
  tmp = my_xxfree(tmp);
  buff = my_xxfree(buff);
  return (prompt);
}
