/*
** builtins_env.h for builtins env in /home/mille_j//rendu/c/42sh/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Nov 11 17:01:00 2010 john mille
** Last update Sun Nov 14 01:49:55 2010 john mille
*/

#ifndef		__BUILTINS_ENV_H__
# define	__BUILTINS_ENV_H__

# include "42sh.h"
# include "tools.h"

/*****************************************************************************/

typedef struct	s_builtins_env
{
  int		id;
  int		is;
  char		*name;
  int		(*func)(t_vars *v);
}		t_builtins_env;

/*****************************************************************************/
/*****************************************************************************/

int		check_setenv_syntax(t_vars *v);
int		check_unsetenv_syntax(t_vars *v);
int		check_env_syntax(t_vars *v);

int		my_env(t_vars *v);
int		my_setenv(t_vars *v);
int		my_unsetenv(t_vars *v);
int		my_up_or_setenv(t_vars *v);
int		my_update_env(t_vars *v, int pos);

/*****************************************************************************/

#endif		/* !__BUILTINS_ENV_H__ */
