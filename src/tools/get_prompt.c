/*
** get_prompt.c for get prompt in /home/mille_j//rendu/c/42sh/src/tools
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Nov 11 16:19:12 2010 john mille
** Last update Thu Dec 16 09:17:52 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"
#include "tools.h"
#include "my.h"

int		my_xread(const int fd, char *buff, unsigned int size)
{
  int		nb_read;

  nb_read = read(fd, buff, size);
  if (nb_read == -1)
    exit(EXIT_FAILURE);
  return (nb_read);
}

int		my_xxread(int fd, char *buff, unsigned int size, t_vars *v)
{
  int	       nb_read;

  nb_read = my_xread(fd, buff, size);
  if (nb_read == 0)
    {
      my_putstr("exit\n");
      v->cd_minus = my_xxfree(v->cd_minus);
      v->prompt = my_xxfree(v->prompt);
      v->env = my_xfree_tab(v->env);
      v->alias = my_xfree_tab(v->alias);
      v = my_xfree(v);
      exit(EXIT_FAILURE);
    }
  return (nb_read);
}

char		*get_prompt(const int fd, t_vars *v)
{
  char		*prompt;
  char		*buff;
  char		*tmp;
  int		nb_read;

  prompt = NULL;
  buff = my_xxmalloc(BUFF_SIZE * sizeof(*buff));
  nb_read = my_xxread(fd, buff, BUFF_SIZE, v);
  while (find_char(buff, '\n') == NOT_FOUND)
    {
      tmp = prompt;
      prompt = my_strcat(tmp, buff);
      tmp = my_xxfree(tmp);
      my_memset(buff, 0, BUFF_SIZE);
      nb_read = my_xread(fd, buff, BUFF_SIZE);
    }
  tmp = prompt;
  prompt = my_strcat(tmp, buff);
  tmp = my_xxfree(tmp);
  tmp = my_xxfree(buff);
  return (prompt);
}
