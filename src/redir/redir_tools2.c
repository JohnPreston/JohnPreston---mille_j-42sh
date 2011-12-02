/*
** redir_tools2.c for redir tools in /home/mille_j//42sh/src/redir
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Dec 16 21:36:04 2010 john mille
** Last update Sat Dec 18 20:45:01 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "42sh.h"
#include "execs.h"
#include "parser.h"
#include "lexer.h"
#include "redirs.h"
#include "tools.h"
#include "gets.h"
#include "my.h"

char		**concat_tabs(char **tab1, char **tab2)
{
  char		**new;
  int		i;
  int		j;

  i = 0;
  j = 0;
  new = my_xmalloc((my_tablen(tab1) + my_tablen(tab2) + 1) * sizeof(*new));
  while (tab1[i])
    {
      new[i] = my_strdup(tab1[i]);
      i += 1;
    }
  while (tab2[j])
    {
      new[i] = my_strdup(tab2[j]);
      i += 1;
      j += 1;
    }
  new[i] = NULL;
  return (new);
}

int		dup_and_exec(t_vars *redir, char **array)
{
  pid_t		shell;
  int		exe;
  int		status;
  int		fd;

  redir->argv = array;
  redir->argc = my_tablen(redir->argv);
  redir->prompt = concat_tab_elems(redir->argv, " ");
  fd = my_xopen(".tmp");
  if ((shell = my_xfork()) == 0)
    {
      fd = my_xdup2(fd, 0);
      lexer(redir);
      exe = global_exec(redir);
      fd = my_xclose(fd);
      exit(exe);
    }
  else
    waitpid(shell, &status, 0);
  return (status);
}
