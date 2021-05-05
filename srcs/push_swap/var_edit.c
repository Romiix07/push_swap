#include "push_swap.h"

void	var_edit(t_algo *var, int size)
{
	var->up = 0;
	var->down = 0;
	var->loop = 0;
	if (size <= 100)
		var->chunk_size = 18;
	else if (size <= 200)
		var->chunk_size = 25;
	else if (size <= 300)
		var->chunk_size = 30;
	else if (size <= 400)
		var->chunk_size = 35;
	else if (size <= 550)
		var->chunk_size = 40;
	else if (size <= 600)
		var->chunk_size = 45;
	else if (size > 600)
		var->chunk_size = 50;
}
