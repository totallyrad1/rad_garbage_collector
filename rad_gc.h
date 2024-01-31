/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad_gc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:29:03 by asnaji            #+#    #+#             */
/*   Updated: 2024/01/31 19:49:52 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAD_GC_H
# define RAD_GC_H
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

typedef struct s_gc
{
	void		*mallocedptr;
	struct s_gc	*next;
}				t_gc;

void	*rad_malloc(size_t size, int flag);

#endif