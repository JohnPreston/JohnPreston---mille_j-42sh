/*
** exec_return.c for return in /home/mille_j//42sh/src/pipes
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Dec  9 15:06:31 2010 john mille
** Last update Fri Dec 10 10:00:03 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "my.h"

int		exec_return(int status)
{
  if (status == 12)
    my_puterror("Bus Error.\n");
  else if (status == 11)
    my_puterror("Segmentation Fault.\n");
  return (status);
}
