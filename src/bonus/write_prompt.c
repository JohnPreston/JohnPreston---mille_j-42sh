/*
** write_prompt.c for write_prompt in /home/mille_j//rendu/c/42sh/src/bonus
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Nov 14 17:03:34 2010 john mille
** Last update Sat Dec 18 10:52:05 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "tools.h"
#include "my.h"

char		*get_user(t_vars *v)
{
  char		*user;
  int		to_find;

  user = NULL;
  to_find = find_pos_in_env(v->env, "USER");
  if (to_find != NOT_FOUND)
    user = my_strdup3(v->env[to_find], '=');
  return (user);
}

char		*get_host(t_vars *v)
{
  char		*host;
  int		to_find;

  host = NULL;
  to_find = find_pos_in_env(v->env, "HOST");
  if (to_find != NOT_FOUND)
    host = my_strdup3(v->env[to_find], '=');
  return (host);
}

static char	*make1(char *user, char *host, char *prompt)
{
  char		*tmp;

  tmp = user;
  user = my_strcat(user, "@");
  tmp = my_xxfree(tmp);
  prompt = my_strcat(user, host);
  tmp = prompt;
  host = my_xxfree(host);
  user = my_xxfree(user);
  prompt = my_strcat(prompt, " $>");
  tmp = my_xxfree(tmp);
  return (prompt);
}

char		*write_prompt(t_vars *v)
{
  char		*prompt;
  char		*user;
  char		*host;

  user = get_user(v);
  host = get_host(v);
  prompt = NULL;
  if (user && host)
    prompt = make1(user, host, prompt);
  else if (user && !host)
    {
      prompt = my_strcat(user, " $>");
      user = my_xxfree(user);
    }
  else if (!user && host)
    {
      prompt = my_strcat(host, "$>");
      host = my_xxfree(host);
    }
  else if (!host && !user)
    prompt = my_strdup("$>");
  return (prompt);
}
