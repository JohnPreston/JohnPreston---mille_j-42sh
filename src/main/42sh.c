/*
** 42sh.c for 42sh in /home/mille_j//42sh/src/main
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Dec  5 01:19:34 2010 john mille
** Last update Sat Dec 18 18:43:47 2010 john mille
*/

#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "42sh.h"
#include "parser.h"
#include "tools.h"
#include "lexer.h"
#include "gets.h"
#include "execs.h"
#include "bonus.h"
#include "my.h"

static char	*prompt;

void		sig1()
{
  signal(SIGINT, sig1);
  my_putstr("\b\b          \n");
  my_puterror(prompt);
}

void		gere_signal()
{
  signal(SIGINT, sig1);
}

int			main()
{
  t_vars		*v;
  int			i;

  i = 0;
  v = my_xmalloc(sizeof(*v));
  init_vars(v);
  while (EPITECH_WINS)
    {
      prompt = write_prompt(v);
      gere_signal(v);
      my_putstr(prompt);
      if ((v->prompt = get_prompt(0, v)))
	{
	  v->argc = get_argc(v->prompt);
	  v->argv = get_argv(v->prompt);
	  lexer(v);
	  v->exe = global_exec(v);
	  v->prompt = my_xxfree(v->prompt);
	  v->argv = my_xfree_tab(v->argv);
	}
      prompt = my_xxfree(prompt);
    }
  return (EXIT_SUCCESS);
}
