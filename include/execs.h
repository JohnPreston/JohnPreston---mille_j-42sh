/*
** execs.h for execs in /home/mille_j//rendu/c/42sh/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Nov 11 18:34:08 2010 john mille
** Last update Sun Dec 19 12:38:11 2010 john mille
*/

#ifndef		__EXECS_H__
# define	__EXECS_H__

#include <sys/types.h>
#include "42sh.h"

/*****************************************************************************/

typedef struct	s_exec
{
  int		i;
  int		exe;
  char		*bin_path;
  char		*bin_name;
  char		**path;
}		t_exec;

typedef	struct	s_pipes
{
  pid_t		shell;
  pid_t		son;
  char		**execs;
  int		fd[2];
  int		stat;
  int		status;
  int		i;
}		t_pipes;

/*****************************************************************************/

# define	CANNOT_ACCESS 0
# define	CAN_ACCESS    1

void            exec_1(t_vars *v, char *argv1, int *fd);
void            exec_2(t_vars *v, char *argv2, int *fd);

int		can_access(const char *path);
int		check_pipe(t_vars *v, char **argv);
char		**get_the_path(t_vars *v);

int		exec_return(int status);
int		mult_pipe(t_vars *v);
int		exec_or(t_vars *v);
int		exec_and(t_vars *v);
int		my_cd(t_vars *v);
int		make_pipe(t_vars *v);
int		make_pipe2(t_vars *v);
int		exec_builtin_exit(t_vars *v);
int		my_echo(t_vars *v);
int		exec_builtins_env(t_vars *v);
int		exec_prog_syst(t_vars *v);
int		exec_mult_execs(t_vars *v);
int		exec_builtins_alias(t_vars *v);
int		global_exec(t_vars *v);


/*****************************************************************************/

#endif		/* !__EXECS_H__ */
