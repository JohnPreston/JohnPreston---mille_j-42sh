/*
** do_redir_left.c for do redir left in /home/mille_j//42sh/src/redir
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Dec 16 11:50:07 2010 john mille
** Last update Sat Dec 18 20:48:05 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "42sh.h"
#include "lexer.h"
#include "gets.h"
#include "parser.h"
#include "execs.h"
#include "redirs.h"
#include "tools.h"
#include "my.h"

int		dup_the_file(t_vars *redir, t_redir *r)
{
  pid_t		shell;
  int		status;
  int		fd;
  int		exe;

  fd = my_xopen(r->the_file);
  exe = 1;
  if ((shell = my_xfork()) == 0)
    {
      fd = my_xdup2(fd, 0);
      exe = global_exec(redir);
      fd = my_xclose(fd);
      exit(exe);
    }
  else
    waitpid(shell, &status, 0);
  return (status);
}

int		do_r_l(t_vars *redir, t_redir *r)
{
  char		**argv;
  char		*str;
  int		exe;

  argv = my_xmalloc(sizeof(*argv));
  exe = 0;
  if (my_tablen(r->before_tab))
    argv = concat_tabs(argv, r->before_tab);
  if (my_tablen(r->after_tab))
    argv = concat_tabs(argv, r->after_tab);
  if (my_tablen(argv))
    {
      str = concat_tab_elems(argv, " ");
      redir->prompt = my_strdup(str);
      redir->argv = get_argv(redir->prompt);
      redir->argc = get_argc(redir->prompt);
      exe = dup_the_file(redir, r);
      argv = my_xfree_tab(argv);
      str = my_xxfree(str);
      redir->argv = my_xfree_tab(redir->argv);
      redir->prompt = my_xxfree(redir->prompt);
    }
  return (exe);
}
