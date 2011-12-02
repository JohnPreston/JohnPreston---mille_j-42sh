/*
** lexer.h for lext in /home/mille_j//rendu/c/42sh/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Nov 11 19:01:39 2010 john mille
** Last update Fri Dec 10 16:14:45 2010 john mille
*/
#ifndef		__LEXER_H__
# define	__LEXER_H__

# include "42sh.h"

/*****************************************************************************/

typedef struct	s_lexer
{
  int		id;
  int		is;
  int		(*func)(t_vars *v);
}		t_lexer;

typedef struct	s_vars_lexer
{
  char		*tmp1;
  char		*tmp2;
  char		*tmp3;
  char		*tmp4;
  int		var;
  int		i;
}		t_vars_lexer;

/*****************************************************************************/

int		is_builtin_alias(t_vars *v);
int		is_there_an_alias(t_vars *v);
int		there_is_home(t_vars *v);
int		there_is_env_var(t_vars *v);

int		find_which_env_var(t_vars *v, int option);

char		*my_strndup1(char *str);
char		*my_strndup2(char *str, int len);

void		build_argv(t_vars *v);
void		lexer(t_vars *v);
void		modify_prompt_for_env_var(t_vars *v);
void		modify_prompt_for_home(t_vars *v);

/*****************************************************************************/

#endif		/* !__LEXER_H__ */
