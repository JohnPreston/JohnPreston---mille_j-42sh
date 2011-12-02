/*
** exec_prog_syst.c for exec_prog_syst in /home/mille_j//rendu/c/42sh/src/prog_syst
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Fri Oct  8 12:13:20 2010 john mille
** Last update Sun Dec 19 12:47:14 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "42sh.h"
#include "execs.h"
#include "tools.h"
#include "my.h"

int		execs_errors(int status)
{
  if (status == SIGSEGV)
    my_puterror("SEGMENTATION FAULT.\n");
  else if (status == SIGBUS)
    my_puterror("BUS ERROR.\n");
  return (status);
}

int		my_xexecve(t_vars *v, char *bin_name)
{
  pid_t		son;
  int		exec;
  int		status;

  if ((son = my_xfork()) == 0)
    exec = execve(bin_name, v->argv, v->env);
  else
    waitpid(son, &status, 0);
  ioctl(0, TIOCSETA, &v->t);
  return (execs_errors(status));
}

int		exec_prog_syst(t_vars *v)
{
  t_exec	c;

  c.exe = 0;
  if (v->argc >= 1 && can_access(v->argv[0]))
    c.exe = my_xexecve(v, v->argv[0]);
  else if (v->argc >= 1 && (c.path = get_the_path(v)))
    {
      c.i = 0;
      while (c.path[c.i])
	{
	  c.bin_path = my_strcat(c.path[c.i], "/");
	  c.bin_name = my_strcat(c.bin_path, v->argv[0]);
	  if (can_access(c.bin_name))
	    c.exe = my_xexecve(v, c.bin_name);
	  c.bin_name = my_xxfree(c.bin_name);
	  c.bin_path = my_xxfree(c.bin_path);
	  c.i += 1;
	}
      c.path = my_xfree_tab(c.path);
    }
  return (c.exe);
}
