/*
** genetics.c for smth in /home/Luk/Bossage/somethingelse/geneticsreal
** 
** Made by Lukas Parant
** Login   <Luk@epitech.net>
** 
** Started on  Sat Jun 13 16:41:48 2015 Lukas Parant
** Last update Sun Jun 14 16:27:14 2015 Lukas Parant
*/

#include "genetics.h"

t_ia		*improve_ia(t_ia *ia1, t_ia *ia2)
{
  t_ia		*new_ia;
  t_neuron	*neur1;
  t_neuron	*neur2;

  srand(time(0));
  if ((new_ia = malloc(sizeof(*new_ia))) == NULL)
    return (NULL);
  new_ia->neurons = NULL;
  neur1 = ia1->neurons;
  neur2 = ia2->neurons;
  while (neur1 != NULL && neur2 != NULL)
    {
      if (add_neuron(neur1, neur2, new_ia, ia1->efficiency, ia2->efficiency) < 0)
	return (NULL);
      neur1 = neur1->next;
      neur2 = neur2->next;
    }
  return (new_ia);
}

int		add_neuron(t_neuron *n1, t_neuron *n2, t_ia *new, int eff1, int eff2)
{
  t_neuron	*cursor;

  if (new->neurons == NULL)
    {
      if ((new->neurons = malloc(sizeof(*(new->neurons)))) == NULL)
	return (-1);
      cursor = new->neurons;
      cursor->next = NULL;
    }
  else
    {
      cursor = new->neurons;
      while (cursor->next != NULL)
	cursor = cursor->next;
      if ((cursor->next = malloc(sizeof(*(cursor)))) == NULL)
	return (-1);
      cursor = cursor->next;
      cursor->next = NULL;
    }
  if (add_value(n1, n2, cursor, eff1, eff2) < 0)
    return (-1);
  return (0);
}

int	add_value(t_neuron *n1, t_neuron *n2, t_neuron *new, int eff1, int eff2)
{
  int	ponder;
  int	tmp_coef;

  ponder = rand() % (eff1 + eff2);
  if (ponder < eff1)
    new->coef = n1->coef;
  else
    new->coef = n2->coef;
  ponder = rand() % 1000;
  if (ponder == 0)
    {
      ponder = rand() % 6;
      tmp_coef = (int) (new->coef * 1000000);
      ponder = pow(10, ponder);
      ponder = ponder * (rand() % 10);
      tmp_coef = (tmp_coef + ponder) % 1000000;
      new->coef = ((float) tmp_coef) / 1000000;
    }
  return (0);
}

void		free_ia(t_ia *ia)
{
  t_neuron	*tmp;

  while (ia->neurons != NULL)
    {
      tmp = ia->neurons;
      ia->neurons = ia->neurons->next;
      free(tmp);
    }
  free(ia);
}

int	main()
{
  t_ia	*ia1;
  t_ia	*ia2;
  t_ia	*ia3;

  ia1 = malloc(sizeof(*ia1));
  ia2 = malloc(sizeof(*ia2));
  ia1->neurons = malloc(sizeof(*(ia1->neurons)));
  ia2->neurons = malloc(sizeof(*(ia2->neurons)));
  ia1->neurons->coef = 0.5;
  ia2->neurons->coef = 0.2;
  ia1->efficiency = 10;
  ia2->efficiency = 30;
  ia3 = improve_ia(ia1, ia2);
  printf("%f\n", ia3->neurons->coef);
  free_ia(ia1);
  free_ia(ia2);
  free_ia(ia3);
  return (0);
}
