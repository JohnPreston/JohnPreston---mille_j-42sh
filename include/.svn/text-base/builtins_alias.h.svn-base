/*
** builtins_env.h for builtins env in /home/mille_j//rendu/c/42sh/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Nov 11 17:01:00 2010 john mille
** Last update Sat Dec 11 00:33:37 2010 john mille
*/

#ifndef		__BUILTINS_ALIAS_H__
# define	__BUILTINS_ALIAS_H__

# include "42sh.h"
# include "tools.h"

/*****************************************************************************/

typedef struct	s_builtins_alias
{
  int		id;
  int		is;
  char		*name;
  int		(*func)(t_vars *v);
}		t_builtins_alias;

typedef	struct	s_alias_vars
{
  char		*elem;
  char		*tmp;
  char		*tmp2;
}		t_alias_vars;

/*****************************************************************************/
/*****************************************************************************/

int		check_setalias_syntax(t_vars *v);
int		check_unsetalias_syntax(t_vars *v);
int		check_alias_syntax(t_vars *v);

int		my_alias(t_vars *v);
int		my_setalias(t_vars *v);
int		my_unsetalias(t_vars *v);
int		my_up_or_setalias(t_vars *v);
int		my_update_alias(t_vars *v, int pos);

char		*get_alias(t_vars *v, char *searched);

/*****************************************************************************/

#endif		/* !__BUILTINS_ALIAS_H__ */
