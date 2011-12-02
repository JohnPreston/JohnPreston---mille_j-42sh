/*
** tools.h for tools in /home/mille_j//rendu/c/42sh/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Nov 11 16:00:25 2010 john mille
** Last update Sat Dec 18 20:42:36 2010 john mille
*/

#include <sys/types.h>
#include "42sh.h"

#ifndef		__TOOLS_H__
# define	__TOOLS_H__

/*****************************************************************************/
/*****************************************************************************/

void		init_vars(t_vars *v);
void		print_debug(int is);

int		my_xread(int fd, char *buff, unsigned int size);
int		my_xxread(int fd, char *buff, unsigned int size, t_vars *v);
int		find_pos_in_env(char **env, char *to_find);
int		find_char(char *str, char c);
int		my_xchdir(const char *path);
int		my_xwrite(const int fd, char *str, unsigned int len);
int		my_xpipe(int fd[2]);
int		my_xdup2(int fd1, int fd2);
int		my_xclose(const int fd);
pid_t		my_xfork();

char		*get_prompt(const int fd, t_vars *v);
char		*get_env_var(t_vars *v, char *to_find);
char            *get_home(t_vars *v);
char            *ask_home(t_vars *v);
char            *get_home_via_username(t_vars *v);
char		*get_pwd(t_vars *v);
char		*get_pwd_via_home(t_vars *v);
char            *make_pwd(char **array);
char		*get_line(const int fd);

char		*concat_tab_elems(char **array, char *sep);
char		*concat_tab_elems2(char **array, char *sep);
char		*nconcat_tab_elems(char **array, char *sep, int a, int b);
char		*get_file(const char *file);

char		**delete_last_elem_in_tab(char **old_array);
char		**delete_first_elem_in_tab(char **old_array);
char		**add_elem_to_tab(char **old_array, char *elem);
char		**delete_elem_in_tab(char **old_array, int pos);
char		**update_elem_in_tab(char **old_array, char *val, int pos);
char		**create_argv1(t_vars *v, char *str);
char		**create_argv2(t_vars *v, char *str);
char            **tab_cpy(char **array);
char		**concat_tabs(char **t1, char **t2);

t_vars		*free_t_vars(t_vars *v);

/*****************************************************************************/

#endif		/* !__TOOLS_H__ */
