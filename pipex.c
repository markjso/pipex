/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:15:57 by jmarks            #+#    #+#             */
/*   Updated: 2022/08/04 17:33:23 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

/* The pipex function creates the pipe itself. First we use pipe to put the file
descriptors for the reading and writing ends of the pipe into fd[0](input) and 
fd[1] (output). It then sets pid to = fork(). This creates the child process. 
If pipe is successful (== 0) then it will close input end, swap it to fd[1] using
dup2, close the output end (fd[1]) and use the execute_cmd function to find and 
execute the command in the argument at argv[2]. If pipe fails then waitpid will
check if the child process has ended and terminate it if it has not (WNOHANG), 
close the output end and swap it to fd[0] using dup2. Then manually close both
fd[1] and fd[0] to make sure the pipe is closed at both ends. */

void	pipex(char *cmd, char **envp)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	if (pipe(fd) == -1)
		error_func();
	pid = fork();
	if (pid < 0)
		error_func();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execute_cmd(cmd, envp);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, NULL, WNOHANG);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
	}
}

/*The main function brings it all together. We have two integers, fdin
and fdout. If we don't have five arguments we return an error, otherwise
fdin will use our open_file function to open the INFILE at argv[1] (eg file.txt).
It will then switch the input to fdout using dup2. fdout will either open or create
the file name found at argv[4] (eg file1.txt) as our OUTFILE. Output is switched to 
input using dup2. Our pipex function then looks at the command at argv[2] and executes 
that. Using this information our execute_cmd function gets the command at argv[3] and
then executes this command on the command already executed at pipex and writes it 
into the OUTFILE.*/

int	main(int argc, char **argv, char **envp)
{
	int	fdin;
	int	fdout;

	if (argc == 5)
	{
		fdin = open_file(argv[1], INFILE);
		if (fdin < 0)
		{
			error_func();
		}
		dup2(fdin, STDIN_FILENO);
		fdout = open_file(argv[4], OUTFILE);
		if (fdout < 0)
		{
			error_func();
		}
		dup2(fdout, STDOUT_FILENO);
		pipex(argv[2], envp);
		execute_cmd(argv[3], envp);
	}
	else
		write(2, "Invalid number of arguments", 27);
	return (1);
}
