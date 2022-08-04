/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:31:08 by jmarks            #+#    #+#             */
/*   Updated: 2022/08/04 14:49:50 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_func(void)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	exit(EXIT_FAILURE);
}

int	open_file(char *file, int flag)
{
	if (flag == INFILE)
	{
		if (!access(file, F_OK | X_OK))
		{
			error_func();
		}
		return (open(file, O_RDONLY));
	}
	else
		return (open(file, O_RDWR | O_CREAT | O_TRUNC, 0644));
}
