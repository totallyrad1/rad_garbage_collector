/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad_gc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:33:01 by asnaji            #+#    #+#             */
/*   Updated: 2024/01/01 18:05:06 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rad_gc.h"

void	addmallocedptr(void *ptr, t_gc **gc)
{
	t_gc	*curr;
	t_gc	*new;

	curr = *gc;
	new = malloc(sizeof(t_gc));
	if (!new)
		return ;
	new->mallocedptr = ptr;
	new->next = NULL;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	*rad_malloc(size_t size, t_gc **gc)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	addmallocedptr(ptr, gc);
	return (ptr);
}

void	rad_free(t_gc *gc)
{
	t_gc	*curr;
	t_gc	*next;

	curr = gc;
	while (curr)
	{
		next = curr->next;
		free(curr->mallocedptr);
		curr->mallocedptr = NULL;
		free(curr);
		curr = NULL;
		curr = next;
	}
}
