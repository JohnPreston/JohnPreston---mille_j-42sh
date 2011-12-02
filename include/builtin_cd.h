/*
** builtin_cd.h for builtin cd in /home/mille_j//42sh/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Nov 16 23:02:10 2010 john mille
** Last update Wed Dec 15 22:42:51 2010 john mille
*/

#ifndef			__BUILTIN_CD_H__
# define		__BUILTIN_CD_H__

#include "42sh.h"

/******************************************************************************/

int		move_from_root(t_vars *v, char *curr_path);

char            **make_pwd_tab(char **pwd, char *curr_path);
char            **add_path_to_pwd(t_vars *v);

/******************************************************************************/


#endif			/* !__BUILTIN_CD_H__ */
