/*
** parser.h for parser in /home/mille_j//rendu/c/42sh/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Nov 11 17:04:31 2010 john mille
** Last update Fri Dec  3 03:45:08 2010 john mille
*/

#ifndef		__PARSER_H__
# define	__PARSER_H__

/*****************************************************************************/

#include "42sh.h"

typedef struct	s_it_is
{
  int		id;
  int		is;
  int		(*func)(t_vars *v);
}		t_it_is;

int		is_or(t_vars *v);
int		is_and(t_vars *v);
int		is_pipe(t_vars *v);
int		is_builtin_echo(t_vars *v);
int		is_builtin_cd(t_vars *v);
int		is_builtin_env(t_vars *v);
int		is_prog_syst(t_vars *v);
int		is_mult_execs(t_vars *v);
int		is_builtin_exit(t_vars *v);
int		is_builtin_echo(t_vars *v);
int		is_builtin_alias(t_vars *v);
int		is_redir_right(t_vars *v);
int		is_redir_left(t_vars *v);
int		is_dble_redir_right(t_vars *v);
int		is_dble_redir_left(t_vars *v);
int		is_mult_pipe(t_vars *v);
int		which_one_in_first(t_vars *v);
int		which_it_is(t_vars *v);

/*****************************************************************************/

#endif		/* !__PARSER_H__ */
