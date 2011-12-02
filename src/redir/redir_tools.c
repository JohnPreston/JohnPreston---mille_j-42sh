/*
** redir_tools.c for redir tools in /home/mille_j//42sh/src/redir
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Dec 15 15:54:06 2010 john mille
** Last update Sat Dec 18 22:25:30 2010 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"
#include "gets.h"
#include "redirs.h"
#include "tools.h"
#include "my.h"

int		*count(t_redir *r)
{
  char		**argv;
  int		i;
  int		*nb;

  i = 0;
  nb = my_xmalloc(5 * sizeof(*nb));
  argv = get_argv(r->prompt);
  nb[0] = 0;
  nb[1] = 0;
  nb[2] = 0;
  nb[3] = 0;
  while (argv[i])
    {
      if (!my_strcmp(argv[i], ">"))
	nb[0] += 1;
      else if (!my_strcmp(argv[i], ">>"))
	nb[1] += 1;
      else if (!my_strcmp(argv[i], "<"))
	nb[2] += 1;
      else if (!my_strcmp(argv[i], "<<"))
	nb[3] += 1;
      i += 1;
    }
  my_xfree_tab(argv);
  return (nb);
}

char		**delete_first_elem_in_tab(char **old_array)
{
  char		**new_array;
  int		i;
  int		j;

  new_array = my_xmalloc((my_tablen(old_array)) * sizeof(*new_array));
  i = 0;
  j = 1;
  while (old_array[j])
    {
      new_array[i] = my_strdup(old_array[j]);
      i += 1;
      j += 1;
    }
  new_array[i] = NULL;
  old_array = my_xfree_tab(old_array);
  return (new_array);
}

int		redir_error(t_vars *redir, t_redir *r, int code)
{
  if (code == 1)
    my_puterror("Missing name for redirect.\n");
  else if (code == 2)
    my_puterror("Invalid null command.\n");
  else if (code == 3)
    my_puterror("Ambiguous output redirect.\n");
  else if (code == 4)
    my_puterror("Command not found.\n");
  else if (code == 2 || code == 4)
    redir->argv = my_xfree_tab(redir->argv);
  else if (code == 5)
    my_puterror("Invalid null command.\n");
  else if (code == 6)
    {
      my_puterror(r->the_file);
      my_puterror(": No such file or directory.\n");
    }
  return (KO);
}

t_redir		*free_redirs_vars(t_redir *r)
{
  r->before_tab = my_xfree_tab(r->before_tab);
  r->after_tab = my_xfree_tab(r->after_tab);
  r->prompt = my_xxfree(r->prompt);
  r->before_str = my_xxfree(r->before_str);
  r->after_str = my_xxfree(r->after_str);
  r->the_file = my_xxfree(r->the_file);
  r->f1 = my_xxfree(r->f1);
  r->f2 = my_xxfree(r->f2);
  r = my_xfree(r);
  r = NULL;
  return (r);
}

char		*rebuild_name(t_vars *v, char *orig_name)
{
  char		*home;
  char		*name;
  char		*tmp;

  home = get_home(v);
  if (my_strlen(orig_name) &&
      my_strncmp(orig_name, "~/", my_strlen("~/")) == 0)
    {
      tmp = my_strdup3(orig_name, '/');
      name = my_strcat(home, tmp);
      tmp = my_xxfree(tmp);
    }
  else
    name = my_strdup(orig_name);
  home = my_xxfree(home);
  return (name);
}
