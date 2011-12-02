/*
** redirs.h for redirections in /home/mille_j//42sh/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Dec  1 10:10:40 2010 john mille
** Last update Sat Dec 18 18:00:11 2010 john mille
*/

#ifndef		__REDIRS_H__
# define	__REDIRS_H__

# include "42sh.h"

/******************************************************************************/

typedef struct	s_redir
{
  char		**before_tab;
  char		**after_tab;
  char		*prompt;
  char		*before_str;
  char		*after_str;
  char		*the_file;
  char		*f1;
  char		*f2;
  int		is;
}		t_redir;


/******************************************************************************/

int		dup_and_exec(t_vars *redir, char **argv);
int		check_redir_right(t_vars *v, t_redir *r);
int		check_redir_left(t_vars *v, t_redir *r);
int		check_db_redir_left(t_vars *v, t_redir *r);
int		global_check(t_redir *r);
int		check_nb(t_redir *r);

int		redir_error(t_vars *redir, t_redir *r, int code);
int		redir_right(t_vars *v);
int		redir_left(t_vars *v);
int		db_redir_right(t_vars *v);
int		db_redir_left(t_vars *v);

int		do_r_r(t_vars *redir, t_redir *r);
int		do_r_l(t_vars *redir, t_redir *r);
int		do_db_r_r(t_vars *redir, t_redir *r);
int		do_db_r_l(t_vars *redir, t_redir *r);

int		*count(t_redir *r);

char		*rebuild_name(t_vars *v, char *orig_name);

t_redir		*free_redirs_vars(t_redir *r);

/******************************************************************************/

#endif		/* !__REDIRS_H__ */
