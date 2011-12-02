/*
** redir_right.c for redir right in /home/mille_j//42sh/src/redir
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Dec 15 13:43:16 2010 john mille
** Last update Sun Dec 19 15:14:27 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "42sh.h"
#include "lexer.h"
#include "execs.h"
#include "parser.h"
#include "redirs.h"
#include "tools.h"
#include "gets.h"
#include "my.h"

void		init_db_r_l(t_vars *v, t_redir *r)
{
  char		**array;

  r->is = which_it_is(v);
  lexer(v);
  r->prompt = my_strdup(v->prompt);
  array = get_redir_left_argv(v->prompt);
  if (my_tablen(array) >= 2)
    {
      r->before_tab = get_argv(array[0]);
      r->after_tab = get_argv(array[1]);
      r->the_file = rebuild_name(v, r->after_tab[0]);
      array = my_xfree_tab(array);
    }
  if (my_tablen(r->after_tab))
    r->after_tab = delete_first_elem_in_tab(r->after_tab);
}

int		db_redir_left(t_vars *v)
{
  t_vars	*redir;
  t_redir	*r_l;
  int		exe;

  r_l = my_xmalloc(sizeof(*r_l));
  redir = my_xmalloc(sizeof(*redir));
  init_vars(redir);
  init_db_r_l(v, r_l);
  if (check_nb(r_l) != OK || check_db_redir_left(redir, r_l) == KO)
    {
      redir = free_t_vars(redir);
      r_l = free_redirs_vars(r_l);
      return (EXIT_FAILURE);
    }
  exe = do_db_r_l(redir, r_l);
  redir = free_t_vars(redir);
  r_l = free_redirs_vars(r_l);
  return (exe);
}
