/*
** pipe.c for pipe in /home/mille_j//42sh/src/pipes
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Nov 16 15:19:15 2010 john mille
** Last update Sun Dec 19 14:04:24 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "42sh.h"
#include "tools.h"
#include "execs.h"
#include "lexer.h"
#include "gets.h"
#include "bonus.h"
#include "parser.h"
#include "execs.h"
#include "my.h"

int		leave_and_free(char **argv)
{
  argv = my_xfree_tab(argv);
  return (EXIT_FAILURE);
}

void		exec_sons(char **argv, int *fd)
{
  t_vars	*v;
  int		tmp;

  fd[0] = my_xclose(fd[0]);
  fd[1] = my_xdup2(fd[1], 1);
  v = my_xmalloc(sizeof(*v));
  init_vars(v);
  argv = delete_last_elem_in_tab(argv);
  v->prompt = concat_tab_elems2(argv, " | ");
  v->argc = get_argc(v->prompt);
  v->argv = get_argv(v->prompt);
  lexer(v);
  tmp = global_exec(v);
  v->prompt = my_xxfree(v->prompt);
  v->argv = my_xfree_tab(v->argv);
  v = free_t_vars(v);
  exit(tmp);
}

void		exec_dad(char *arg, int *fd)
{
  t_vars	*dad;
  int		tmp;

  dad = my_xmalloc(sizeof(*dad));
  init_vars(dad);
  fd[1] = my_xclose(fd[1]);
  fd[0] = my_xdup2(fd[0], 0);
  dad->prompt = my_strdup(arg);
  dad->argc = get_argc(dad->prompt);
  dad->argv = get_argv(dad->prompt);
  lexer(dad);
  tmp = global_exec(dad);
  dad->prompt = my_xxfree(dad->prompt);
  dad->argv = my_xfree_tab(dad->argv);
  dad = free_t_vars(dad);
  exit(tmp);
}

int		close_to_exit(int *fd, int status)
{
  fd[0] = my_xclose(fd[0]);
  fd[1] = my_xclose(fd[1]);
  return (status);
}

int		make_pipe(t_vars *v)
{
  t_pipes		c;

  c.execs = get_argv_pipes(v->prompt);
  if (check_pipe(v, c.execs) == KO)
    return (leave_and_free(c.execs));
  c.i = my_tablen(c.execs) - 1;
  if ((c.shell = my_xfork()) == 0)
    {
      my_xpipe(c.fd);
      if ((c.son = my_xfork()) == 0)
	exec_sons(c.execs, c.fd);
      else if (c.i)
	{
	  exec_dad(c.execs[c.i], c.fd);
	  waitpid(c.son, &c.status, 0);
	}
      exit(close_to_exit(c.fd, c.status));
    }
  else
    waitpid(c.shell, &c.stat, 0);
  c.execs = my_xfree_tab(c.execs);
  return (c.stat);
}
