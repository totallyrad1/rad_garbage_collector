/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad_gc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:33:01 by asnaji            #+#    #+#             */
/*   Updated: 2024/01/31 19:49:43 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rad_gc.h"

static void	rad_free(t_gc *gc)
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

static void	addmallocedptr(void *ptr, t_gc **gc, int flag)
{
	t_gc	*curr;
	t_gc	*new;

	if(flag == 0)
		(*gc)->mallocedptr = ptr;
	else 
	{
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
}

void	*rad_malloc(size_t size, int flag)
{
	void		*ptr;
	static t_gc	*gc;
	static int	first_iter = 0;

	if(flag == 0)
	{
		ptr = malloc(size);
		if (!ptr)
			return (NULL);
	}
	else if (flag == 1)
		return (first_iter = 0, rad_free(gc), NULL);
	if (first_iter == 0)
	{
		gc = malloc(sizeof(t_gc));
		if(!gc)
			return (NULL);
		addmallocedptr(ptr, &gc, first_iter);
		first_iter = 1;
	}
	else if (first_iter == 1)
		addmallocedptr(ptr, &gc, first_iter);
	return (ptr);
}
