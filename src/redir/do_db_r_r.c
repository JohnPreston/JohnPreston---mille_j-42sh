/*
** do_db_r_r.c for do db db r r in /home/mille_j//42sh/src/redir
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Dec 16 13:53:27 2010 john mille
** Last update Sat Dec 18 20:45:54 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "42sh.h"
#include "lexer.h"
#include "parser.h"
#include "execs.h"
#include "redirs.h"
#include "tools.h"
#include "my.h"

static int	create_the_file(t_vars *redir, t_redir *r)
{
  pid_t		shell;
  int		status;
  int		fd;
  int		exe;

  fd = my_xopen3(r->the_file);
  exe = 1;
  if ((shell = my_xfork()) == 0)
    {
      fd = my_xdup2(fd, 1);
      lexer(redir);
      exe = global_exec(redir);
      fd = my_xclose(fd);
      exit(exe);
    }
  else
    waitpid(shell, &status, 0);
  return (status);
}

int		do_db_r_r(t_vars *redir, t_redir *r)
{
  int		exe;

  exe = 0;
  if (!my_tablen(r->before_tab) && my_tablen(r->after_tab))
    {
      redir->argv = tab_cpy(r->after_tab);
      redir->prompt = concat_tab_elems(redir->argv, " ");
      redir->argc = my_tablen(redir->argv);
      exe = create_the_file(redir, r);
      redir->argv = my_xfree_tab(redir->argv);
      redir->prompt = my_xxfree(redir->prompt);
    }
  else if (my_tablen(r->before_tab) && !my_tablen(r->after_tab))
    {
      redir->argv = tab_cpy(r->before_tab);
      redir->prompt = concat_tab_elems(redir->argv, " ");
      redir->argc = my_tablen(redir->argv);
      exe = create_the_file(redir, r);
      redir->argv = my_xfree_tab(redir->argv);
      redir->prompt = my_xxfree(redir->prompt);
    }
  return (exe);
}
