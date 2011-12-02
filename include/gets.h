/*
** gets.h for gets in /home/mille_j//rendu/c/42sh/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Nov 11 17:29:55 2010 john mille
** Last update Thu Dec 16 20:33:45 2010 john mille
*/

#ifndef		__GETS_H__
# define	__GETS_H__

/*****************************************************************************/

int		get_argc(char *str);
int		get_or_argc(char *str);
int		get_and_argc(char *str);
int		get_mukt_argc(char *str);
int		get_argc_pipes(char *str);
int		get_nb_pwd(char *str);
int		get_nb_env_path(char *str);
int		get_file_nb_lines(char *str);
int		get_redir_left_argc(char *str);
int		get_redir_right_argc(char *str);

char		**get_argv(char *str);
char		**get_or_argv(char *str);
char		**get_and_argv(char *str);
char		**get_file_lines(char *str);
char		**get_mult_argv(char *str);
char		**get_cd_path(char *str);
char		**get_env_path(char *str);
char		**get_argv_pipes(char *str);
char		**get_redir_left_argv(char *str);
char		**get_redir_right_argv(char *str);

/*****************************************************************************/

#endif		/* !__GETS_H__ */
