#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node {
  int value;
  struct s_node *prev;
  struct s_node *next;
} t_node;

typedef struct s_stack {
  t_node *head;
  t_node *tail;
  int size;
} t_stack;

typedef enum e_strategy {
  STRATEGY_ADAPTIVE,
  STRATEGY_SIMPLE,
  STRATEGY_MEDIUM,
  STRATEGY_COMPLEX
} t_strategy;

double compute_disorder(t_stack *a);
void simple_sort(t_stack *a, t_stack *b);
void medium_sort(t_stack *a, t_stack *b);
void complex_sort(t_stack *a, t_stack *b);

/* stack */
t_node *node_new(int value);
void stack_init(t_stack *stack);
void stack_add_front(t_stack *stack, t_node *node);
void stack_add_back(t_stack *stack, t_node *node);
t_node *stack_pop_front(t_stack *stack);
t_node *stack_pop_back(t_stack *stack);
void stack_clear(t_stack *stack);

/* operations */
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);

void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);

/* utils */
int ps_strcmp(const char *s1, const char *s2);
int ps_isdigit(int c);
int ps_atoi(const char *s, int *value);

/* test */
void print_stack(t_stack *stack);
int parse_args(t_stack *a, t_strategy *strategy, int argc, char **argv);
#endif
