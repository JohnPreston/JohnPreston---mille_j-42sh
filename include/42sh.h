/*
** 42sh.h for 42sh in /home/mille_j//rendu/c/42sh/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Nov 11 15:39:46 2010 john mille
** Last update Sat Dec 18 11:53:11 2010 john mille
*/

#include <term.h>
#include <sys/ioctl.h>

#ifndef			__42SH_H__
# define		__42SH_H__

/************** DEFINES ******************************************************/

# define		BUFF_SIZE 1024

# define		EPITECH_WINS 42

# define		KO 0
# define		OK 1

# define		SYNTAX_OK 1
# define		SYNTAX_KO 0

# define		NOT_FOUND -1
# define		FOUND 0

# define		ALL 2

# define		EXEC_SUCCESS 0
# define		EXEC_FAILURE 1

# define		NOT_IN_LEXE 0
# define		LEXER_ALIAS 1
# define		LEXER_HOME  2
# define		LEXER_ENV_V 3

# define		SMTH_ELSE 0
# define		BUILT_ENV 1
# define		BUILT_EXI 2
# define		BUILT_CD  3
# define		BUILT_ALI 4
# define		BUILT_ECH 5
# define		PROG_SYST 6
# define		MULT_PIPE 7
# define		REDI_RIGH 8
# define		DB_RE_RIG 9
# define		REDI_LEFT 10
# define		DB_RE_LEF 11
# define		AND_BIN_O 12
# define		OR_BIN_OP 13
# define		OPERA_BIN 14
# define		MULT_EXEC 15

# define		TIOCGETA TCGETA
# define		TIOCSETA TCSETA
# define		termios termio

/*****************************************************************************/
/************** STRUCTURES ***************************************************/

typedef struct		s_vars
{
  int			argc;
  int			exe;
  int			sign;
  char			*cd_minus;
  char			*prompt;
  char			**alias;
  char			**argv;
  char			**env;
  struct termios	t;
}			t_vars;

typedef struct		s_apply
{
  int			id;
  int			is;
  int			(*func)(t_vars *v);
}			t_apply;

/*****************************************************************************/

#endif			/* !__42SH_H__ */
