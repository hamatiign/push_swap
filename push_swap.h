/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkajikaw <kkajikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:28:52 by kkajikaw          #+#    #+#             */
/*   Updated: 2026/09/17 20:28:53 by kkajikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

# define SIMPLE_SORT_MAX_DISORDER  0.2
# define MEDIUM_SORT_MAX_DISORDER  0.5

typedef struct s_stats {
  int total;
  int sa;
  int sb;
  int ss;
  int pa;
  int pb;
  int ra;
  int rb;
  int rr;
  int rra;
  int rrb;
  int rrr;
} t_stats;

typedef struct s_node {
  int value;
  int rank;
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

typedef struct s_context {
  t_stats stats;
  t_strategy strategy;
  double disorder;
  int bench;
} t_context;

double compute_disorder(t_stack *a);
void simple_sort(t_stack *a, t_stack *b, t_context *ctx);
void medium_sort(t_stack *a, t_stack *b, t_context *ctx);
void complex_sort(t_stack *a, t_stack *b, t_context *ctx);
void print_bench(t_context *ctx);
void print_disorder(double disorder);

/* stack */
t_node *node_new(int value);
void stack_init(t_stack *stack);
void stack_add_front(t_stack *stack, t_node *node);
void stack_add_back(t_stack *stack, t_node *node);
t_node *stack_pop_front(t_stack *stack);
t_node *stack_pop_back(t_stack *stack);
void stack_clear(t_stack *stack);
void set_rank(t_stack *stack);
void	stats_init(t_stats *stats);

/* operations */
void sa(t_stack *a, t_context *ctx);
void sb(t_stack *b, t_context *ctx);
void ss(t_stack *a, t_stack *b, t_context *ctx);

void ra(t_stack *a, t_context *ctx);
void rb(t_stack *b, t_context *ctx);
void rr(t_stack *a, t_stack *b, t_context *ctx);
void rra(t_stack *a, t_context *ctx);
void rrb(t_stack *b, t_context *ctx);
void rrr(t_stack *a, t_stack *b, t_context *ctx);

void pa(t_stack *a, t_stack *b, t_context *ctx);
void pb(t_stack *a, t_stack *b, t_context *ctx);

/* utils */
int ps_strcmp(const char *s1, const char *s2);
int ps_isdigit(int c);
int ps_atoi(const char *s, int *value);
void ps_putstr_stderr(char *s);
int is_sorted(t_stack *stack);
int get_node_index(t_stack *stack, t_node *target);
t_node *get_min_node(t_stack *stack);
t_node *get_max_node(t_stack *stack);
int	ft_printf_fd(int fd, const char *format, ...);

/* test */
void print_stack(t_stack *stack);
int parse_args(t_stack *a, t_context *ctx, int argc, char **argv);
#endif
