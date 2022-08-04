/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:06:18 by jmarks            #+#    #+#             */
/*   Updated: 2022/08/03 17:39:17 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"

# define STDIN 0
# define STDOUT 1

# define INFILE 0
# define OUTFILE 1

void	error_func(void);
int		open_file(char *file, int flag);
void	execute_cmd(char *cmd, char **envp);

#endif
