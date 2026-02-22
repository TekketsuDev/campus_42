#ifdef PUSH_SWAP.H
# define PUSH_SWAP

typedef struct s_stack
{
	int	value;
	int	index;
	t_stack next_node;
	t_stack previous_node;

} t_stack;

/* 
 * Stack operations
*/

t_stack		*init_stack(int value);


/*
 * Operations
*/





#endif // PUSH_SWAP.H
