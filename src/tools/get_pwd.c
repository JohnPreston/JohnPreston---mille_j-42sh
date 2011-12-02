/*
** get_pwd.c for get pwd in /home/mille_j//42sh/src/builtin_cd
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Nov 17 12:25:42 2010 john mille
** Last update Sun Dec 12 14:53:37 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "tools.h"
#include "my.h"

char		*get_pwd_via_home(t_vars *v)
{
  char		*pwd;
  char		*tmp;

  pwd = NULL;
  tmp = get_env_var(v, "HOME");
  if (tmp)
    {
      pwd = my_strdup(tmp);
      tmp = my_xxfree(tmp);
    }
  return (pwd);
}

char		*get_pwd(t_vars *v)
{
  char		*pwd;
  char		*tmp;

  pwd = get_env_var(v, "PWD");
  if (!pwd)
    {
      if ((pwd = get_pwd_via_home(v)))
	{
	  tmp = my_strcat("PWD=", pwd);
	  v->env = add_elem_to_tab(v->env, tmp);
	  v->cd_minus = my_strdup(pwd);
	  tmp = my_xxfree(tmp);
	  my_xchdir(pwd);
	  pwd = my_xxfree(pwd);
	  return (NULL);
	}
    }
  return (pwd);
}
