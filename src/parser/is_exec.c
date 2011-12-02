/*
** is_exec.c for is exec in /home/mille_j//rendu/c/42sh/src/parser
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Nov 11 19:25:13 2010 john mille
** Last update Thu Dec 16 09:09:16 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"
#include "execs.h"
#include "tools.h"
#include "my.h"

int		can_access(const char *path)
{
  int		exec;

  exec = access(path, X_OK);
  if (exec == -1)
    return (CANNOT_ACCESS);
  return (CAN_ACCESS);
}

int		is_prog_syst(t_vars *v)
{
  t_exec	c;

  if (v->argc >= 1 && can_access(v->argv[0]))
    return (PROG_SYST);
  else if (v->argc >= 1 && (c.path = get_the_path(v)))
    {
      c.i = 0;
      while (c.path[c.i])
	{
	  c.bin_path = my_strcat(c.path[c.i], "/");
	  c.bin_name = my_strcat(c.bin_path, v->argv[0]);
	  if (can_access(c.bin_name))
	    {
	      c.bin_path = my_xxfree(c.bin_path);
	      c.bin_name = my_xxfree(c.bin_name);
	      c.path = my_xfree_tab(c.path);
	      return (PROG_SYST);
	    }
	  c.bin_name = my_xxfree(c.bin_name);
	  c.bin_path = my_xxfree(c.bin_path);
	  c.i += 1;
	}
      c.path = my_xfree_tab(c.path);
    }
  return (SMTH_ELSE);
}
