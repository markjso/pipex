/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:36:16 by jmarks            #+#    #+#             */
/*   Updated: 2022/08/04 14:32:31 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* the **get_path function searches for the PATH= variable in the envp using ft_strncmp
   Places all possible listed paths in the PATH line into a string double array
   using ft_split and the delimiter ':'. Adds a "/" to the end of each path to
   make them valid paths using ft_strjoin. To see this in action typ env into a 
   terminal. This returns all the environment variables. The PATH variable contains
   a list of paths seperated by a ':' - /usr/local/bin:/usr/bin etc we seperate these
   with ft_split which then means they are now /usr/local/bin and /usr/bin. To make
   them valid paths we add a "/" to the end of each one using ft_strjoin to make
   them a valid path /usr/local/bin/ and /usr/bin/ */
   
   #include "pipex.h"

char	**get_path(char **envp)
{
	char	**env_paths;
	char	*tmp;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	tmp = envp[i] + 5;
	env_paths = ft_split(tmp, ':');
	i = 0;
	while (env_paths[i])
	{
		tmp = env_paths[i];
		env_paths[i] = ft_strjoin(tmp, "/");
		free(tmp);
		i++;
	}
	return (env_paths);
}

/* the *find_cmd_path function looks for the cmd path within the paths returned in
   our get_path function. First we join the command name to the end of the path using
   ft_strjoin then test if it is accessible and executable using access to check the path
   name. (access() checks whether the calling process can access the file pathname).
   We keep looping until we find it in the paths returned in get_path. If we find
   it return it, otherwise free the path and return NULL.*/

char	*find_cmd_path(char *cmd, char **path)
{
	char	*cmd_path;
	int		i;

	i = 0;
	path = get_path(path);
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

/* the execute_cmd function executes the command found at argv[3] in the pipex 
main using execve. Execve() function is used for the execution of the program 
that is referred to by pathname (eg wc or ls). If the command has two parts
(eg ls -la) it will split it at the space. If the command cannot be found it 
writes pipex: command not found: and the name of the command and exits the function.
*/

void	execute_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*exe_path;

	args = ft_split(cmd, ' ');
	exe_path = find_cmd_path(args[0], envp);
	execve(exe_path, args, envp);
	write(2, "pipex: ", 7);
	write(2, "command not found: ", 20);
	write(2, cmd, ft_strlen(cmd));
	exit(127);
}
