#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
}					t_stack;

/* stack */
t_node				*node_new(int value);
void	stack_init(t_stack *stack);
void	stack_add_front(t_stack *stack, t_node *node);
void	stack_add_back(t_stack *stack, t_node *node);
t_node	*stack_pop_front(t_stack *stack);
t_node	*stack_pop_back(t_stack *stack);
void	stack_clear(t_stack *stack);

/* operations */
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

#endif
