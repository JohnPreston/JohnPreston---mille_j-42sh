/*
** redir_right.c for redir right in /home/mille_j//42sh/src/redir
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Dec 15 13:43:16 2010 john mille
** Last update Sat Dec 18 22:25:53 2010 john mille
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

void		init_redir_simp(t_vars *v, t_redir *r, char redir)
{
  r->is = which_it_is(v);
  r->prompt = my_strdup(v->prompt);
  r->before_str = my_strdup2(r->prompt, redir);
  r->after_str = my_strdup3(r->prompt, redir);
  r->before_tab = get_argv(r->before_str);
  r->after_tab = get_argv(r->after_str);
  r->the_file = rebuild_name(v, r->after_tab[0]);
  if (my_tablen(r->after_tab))
    r->after_tab = delete_first_elem_in_tab(r->after_tab);
}

int		redir_right(t_vars *v)
{
  t_vars	*redir;
  t_redir	*r_r;
  int		exe;

  r_r = my_xmalloc(sizeof(*r_r));
  redir = my_xmalloc(sizeof(*redir));
  init_vars(redir);
  init_redir_simp(v, r_r, '>');
  if (!check_nb(r_r) || !check_redir_right(redir, r_r))
    {
      redir = free_t_vars(redir);
      r_r = free_redirs_vars(r_r);
      return (EXIT_FAILURE);
    }
  exe = do_r_r(redir, r_r);
  redir = free_t_vars(redir);
  r_r = free_redirs_vars(r_r);
  return (exe);
}

int		redir_left(t_vars *v)
{
  t_vars	*redir;
  t_redir	*r_l;
  int		exe;

  r_l = my_xmalloc(sizeof(*r_l));
  redir = my_xmalloc(sizeof(*redir));
  init_vars(redir);
  init_redir_simp(v, r_l, '<');
  if (!check_nb(r_l) || !check_redir_left(redir, r_l))
    {
      redir = free_t_vars(redir);
      r_l = free_redirs_vars(r_l);
      return (EXIT_FAILURE);
    }
  exe = do_r_l(redir, r_l);
  redir = free_t_vars(redir);
  r_l = free_redirs_vars(r_l);
  return (exe);
}
