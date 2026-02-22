typedef struct s_stack
{
	int	value;
	int	index;
	t_stack next_node;
	t_stack previous_node;

} t_stack;
// Ordenar stack t_stack_num en orden ascendente

t_stack		*init_stack(int value)
{
	new_node = malloc(sizeof(t_stack));
	new_node->value = value;
	new_node->previous_node = NULL;
	new_node->next_node = NULL;
}
//Algoritmo Simple (0(n^2))

int		*bubble_sort ()
{

}
int		*selection_sort ()
{

}

int		*insertion_sort ()
{

}

int		*extraction_sort ()
{

}

int main (int argc, char *argv[])
{
	t_stack a;
	t_stack b;

	ft_printf
	return (0);
}
