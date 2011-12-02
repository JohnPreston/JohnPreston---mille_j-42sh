/*
** do_db_r_l.c for do db redir left in /home/mille_j//42sh/src/redir
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Dec 16 19:58:30 2010 john mille
** Last update Sat Dec 18 20:46:23 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include "42sh.h"
#include "parser.h"
#include "execs.h"
#include "lexer.h"
#include "redirs.h"
#include "tools.h"
#include "my.h"

static int	xread(int fd, char *buff, unsigned int size)
{
  int	       nb_read;

  nb_read = my_xread(fd, buff, size);
  if (nb_read == 0)
    my_putstr("\n");
  return (nb_read);
}

char		*get_line(const int fd)
{
  char		*prompt;
  char		*buff;
  char		*tmp;
  int		nb_read;

  prompt = NULL;
  buff = my_xxmalloc(BUFF_SIZE * sizeof(*buff));
  nb_read = xread(fd, buff, BUFF_SIZE);
  if (!nb_read)
    return (prompt);
  while (find_char(buff, '\n') == NOT_FOUND)
    {
      tmp = prompt;
      prompt = my_strcat(tmp, buff);
      tmp = my_xxfree(tmp);
      my_memset(buff, 0, BUFF_SIZE);
      nb_read = xread(fd, buff, BUFF_SIZE);
    }
  tmp = prompt;
  prompt = my_strcat(tmp, buff);
  tmp = my_xxfree(tmp);
  tmp = my_xxfree(buff);
  return (prompt);
}

void		blank(int sig)
{
  signal(SIGINT, blank);
  sig = 0;
  my_putstr("\b\b   \r?");
}

char		**get_each_lines(t_redir *r)
{
  char		**array;
  char		*read;

  my_puterror("?");
  array = my_xmalloc(sizeof(*array));
  signal(SIGINT, blank);
  while (my_strncmp((read = get_line(0)), r->the_file, my_strlen(r->the_file)))
    {
      signal(SIGINT, blank);
      my_puterror("?");
      array = add_elem_to_tab(array, read);
      my_xxfree(read);
    }
  return (array);
}

int		do_db_r_l(t_vars *redir, t_redir *r)
{
  char		**array;
  char		*line;
  char		**argv;
  int		exe;
  int		fd;

  array = get_each_lines(r);
  line = concat_tab_elems(array, "");
  fd = my_xopen2(".tmp");
  write(fd, line, my_strlen(line));
  fd = my_xclose(fd);
  argv = my_xmalloc(sizeof(*argv));
  exe = 0;
  if (my_tablen(r->before_tab))
    argv = concat_tabs(argv, r->before_tab);
  if (my_tablen(r->after_tab))
    argv = concat_tabs(argv, r->after_tab);
  if (my_tablen(argv))
    exe = dup_and_exec(redir, argv);
  return (exe);
}
