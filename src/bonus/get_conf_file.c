/*
** get_alias_file_conf.c for alias conf in /home/mille_j//42sh/src/bonus_alias
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Mon Dec  6 13:57:33 2010 john mille
** Last update Fri Dec  2 13:20:33 2011 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "execs.h"
#include "builtins_alias.h"
#include "gets.h"
#include "tools.h"
#include "my.h"

static char	*get_the_conf_file(const char *path)
{
  char		*prompt;
  char		*buff;
  char		*tmp;
  int		nb_read;
  int		fd;

  fd = my_xopen(path);
  if (fd == -1)
    return (NULL);
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

void		get_conf_file(t_vars *v)
{
  char		**conf_lines;
  char		*conf;
  int		i;

  i = 0;
  if ((conf = get_the_conf_file(".42shrc")))
    {
      conf_lines = get_file_lines(conf);
      while (conf_lines[i])
	{
	  if ((v->argc = get_argc(conf_lines[i])) >  1)
	    {
	      v->argv = get_argv(conf_lines[i]);
	      global_exec(v);
	      v->argv = my_xfree_tab(v->argv);
	    }
	  else
	    my_puterror("Bad config line format in config file.\n");
	  i += 1;
	}
      conf_lines = my_xfree_tab(conf_lines);
      conf = my_xxfree(conf);
    }
}
