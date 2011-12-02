/*
** get_home.c for get home in /home/mille_j//42sh/src/builtin_cd
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Nov 16 22:40:41 2010 john mille
** Last update Sat Dec 18 14:17:35 2010 john mille
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include "42sh.h"
#include "tools.h"
#include "my.h"

char		*get_home_via_username(t_vars *v)
{
  char		*home;
  char		*tmp;

  home = NULL;
  tmp = get_env_var(v, "USERNAME");
  if (tmp)
    {
      home = my_strcat("/home/", tmp);
      tmp = my_xxfree(tmp);
      tmp = home;
      home = my_strcat(tmp, "/");
      tmp = my_xxfree(tmp);
    }
  return (home);
}

void		home_error()
{
  signal(SIGINT, home_error);
  my_puterror("\b\b           \nPlease, enter your login : ");
}

char		*test_and_move(t_vars *v, char *home, char *buffer)
{
  char		*tmp;
  DIR 		*test;

  buffer[my_strlen(buffer) - 1] = 47;
  home = my_strcat("/home/", buffer);
  if ((test = opendir(home)))
    {
      my_xchdir(home);
      tmp = my_strcat("HOME=", home);
      v->env = add_elem_to_tab(v->env, tmp);
      tmp = my_xxfree(tmp);
      buffer = my_xxfree(buffer);
      test = my_xfree(test);
      return (home);
    }
  test = my_xfree(test);
  home = my_xxfree(home);
  buffer = my_xxfree(buffer);
  return (NULL);
}

char		*ask_home(t_vars *v)
{
  char		*home;
  char		*buffer;

  home = NULL;
  while (EPITECH_WINS)
    {
      signal(SIGINT, home_error);
      my_puterror("Please, enter your login : ");
      if ((buffer = get_line(0)) && my_strcmp(buffer, "\n"))
	home = test_and_move(v, home, buffer);
      if (home)
	return (home);
    }
  return (home);
}

char		*get_home(t_vars *v)
{
  char		*home;
  char		*tmp;

  home = get_env_var(v, "HOME");
  if (!home)
    {
      if ((home = get_home_via_username(v)))
	{
	  tmp = my_strcat("HOME=", home);
	  v->env = add_elem_to_tab(v->env, tmp);
	  tmp = my_xxfree(tmp);
	  return (home);
	}
      else
	home = ask_home(v);
    }
  return (home);
}
