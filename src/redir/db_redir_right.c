/*
** redir_right.c for redir right in /home/mille_j//42sh/src/redir
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Dec 15 13:43:16 2010 john mille
** Last update Sat Dec 18 18:40:36 2010 john mille
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

void		init_db_r_r(t_vars *v, t_redir *r)
{
  char		**array;

  r->is = which_it_is(v);
  lexer(v);
  r->prompt = my_strdup(v->prompt);
  array = get_redir_right_argv(v->prompt);
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

int		db_redir_right(t_vars *v)
{
  t_vars	*redir;
  t_redir	*r_r;
  int		exe;

  r_r = my_xmalloc(sizeof(*r_r));
  redir = my_xmalloc(sizeof(*redir));
  init_vars(redir);
  init_db_r_r(v, r_r);
  if (!check_nb(r_r) || !check_redir_right(redir, r_r))
    {
      redir = free_t_vars(redir);
      r_r = free_redirs_vars(r_r);
      return (EXIT_FAILURE);
    }
  exe = do_db_r_r(redir, r_r);
  redir = free_t_vars(redir);
  r_r = free_redirs_vars(r_r);
  return (exe);
}
