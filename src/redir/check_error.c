/*
** check_error.c for check error in /home/mille_j//42sh/src/redir
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Dec 15 16:15:20 2010 john mille
** Last update Sun Dec 19 15:02:43 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "42sh.h"
#include "parser.h"
#include "redirs.h"
#include "tools.h"
#include "gets.h"
#include "my.h"

int		check_nb(t_redir *r)
{
  int		*nb;

  nb = count(r);
  if ((nb[0] && nb[1]) || (nb[2] && nb[3]))
    {
      nb = my_xfree(nb);
      my_puterror("Ambiguous output redirect.\n");
      return (KO);
    }
  else if (nb[0] > 1  || nb[1] > 1 || nb[2] > 1 || nb[3] > 1)
    {
      nb = my_xfree(nb);
      my_puterror("Ambiguous output redirect.\n");
      return (KO);
    }
  nb = my_xfree(nb);
  return (OK);
}

int		check_redir_right(t_vars *redir, t_redir *r)
{
  if (!my_strlen(r->the_file))
    return (redir_error(redir, r, 1));
  else if (my_xopen2(r->the_file) == -1)
    return (redir_error(redir, r, 6));
  else if (!my_tablen(r->before_tab) && !my_tablen(r->after_tab))
    return (redir_error(redir, r, 2));
  else if (my_tablen(r->after_tab))
    {
      redir->argv = r->after_tab;
      redir->argc = my_tablen(redir->argv);
      if (which_it_is(redir) > 6)
	return (redir_error(redir, r, 3));
      if (which_it_is(redir) == SMTH_ELSE)
	return (redir_error(redir, r, 4));
    }
  else
    {
      redir->argv = r->before_tab;
      redir->argc = my_tablen(redir->argv);
      if (which_it_is(redir) == SMTH_ELSE)
	return (redir_error(redir, r, 4));
    }
  return (OK);
}

int		check_redir_left(t_vars *redir, t_redir *r)
{
  if (!my_strlen(r->the_file))
    return (redir_error(redir, r, 1));
  else if (my_xopen(r->the_file) == -1)
    return (redir_error(redir, r, 6));
  else if (!my_tablen(r->before_tab) && !my_tablen(r->after_tab))
    return (redir_error(redir, r, 2));
  else if (my_tablen(r->before_tab))
    {
      redir->argv = r->before_tab;
      redir->argc = my_tablen(redir->argv);
      if (which_it_is(redir) == 7)
      	return (redir_error(redir, r, 3));
      if (which_it_is(redir) == SMTH_ELSE)
	return (redir_error(redir, r, 4));
    }
  else
    {
      redir->argv = r->after_tab;
      redir->argc = my_tablen(redir->argv);
      if (which_it_is(redir) == SMTH_ELSE)
	return (redir_error(redir, r, 4));
    }
  return (OK);
}

int		check_db_redir_left(t_vars *redir, t_redir *r)
{
  if (my_strlen(r->the_file) < 1)
    return (redir_error(redir, r, 1));
  else if (!my_tablen(r->before_tab) && !my_tablen(r->after_tab))
    return (redir_error(redir, r, 2));
  else if (!my_tablen(r->before_tab) && !my_tablen(r->after_tab))
	return (redir_error(redir, r, 5));
  return (OK);
}
