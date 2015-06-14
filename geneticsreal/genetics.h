/*
** genetics.h for smth in /home/Luk/Bossage/somethingelse/geneticsreal
** 
** Made by Lukas Parant
** Login   <Luk@epitech.net>
** 
** Started on  Sat Jun 13 16:42:34 2015 Lukas Parant
** Last update Sun Jun 14 16:12:26 2015 Lukas Parant
*/

#ifndef GENETICS_H_
# define GENETICS_H_

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct          s_neuron
{
  float                 coef;
  struct s_neuron       *next;
}			t_neuron;

typedef struct	s_ia
{
  t_neuron	*neurons;
  int		efficiency;
}		t_ia;

#endif
