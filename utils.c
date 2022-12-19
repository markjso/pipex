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
/* Use strerror to return a pointer to the error string describing error
errnum. Eg No such file or directory*/

void	error_func(void)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	exit(EXIT_FAILURE);
}
/* checks the INFILE exists (F_OK) and if it can be accessed (X_OK)
and returns an error if either is false. If true it opens the file
with read only access (O_RDONLY). If it is not the INFILE and it does 
not exist create a new file (O_CREAT) with read/write access(O_RDWR).
If the file exists O_TRUNC will truncate the length to 0 and give the file
owner read/write privelages (0644) */

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
