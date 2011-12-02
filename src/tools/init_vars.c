/*
** init_vars.c for init_vars in /home/mille_j//rendu/c/42sh/src
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 23:59:17 2010 john mille
** Last update Sun Dec 19 11:51:04 2010 john mille
*/

#include <term.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "42sh.h"
#include "tools.h"
#include "bonus.h"
#include "my.h"

static char	**get_extern_env()
{
  extern char	**environ;
  char		**env;
  int		i;

  i = 0;
  env = my_xmalloc((my_tablen(environ) + 1) * sizeof(*env));
  while (environ[i])
    {
      env[i] = my_strdup(environ[i]);
      i += 1;
    }
  env[i] = NULL;
  return (env);
}

void		init_vars(t_vars *v)
{
  v->argc = 0;
  v->sign = 0;
  v->cd_minus = NULL;
  v->prompt = NULL;
  v->alias = my_xmalloc(sizeof(*v->alias));
  v->argv = NULL;
  v->env = get_extern_env();
  if (ioctl(0, TIOCGETA, &v->t) < 0)
  v->cd_minus = get_env_var(v, "PWD");
  get_conf_file(v);
}
