/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:00:36 by yiken             #+#    #+#             */
/*   Updated: 2024/04/26 09:54:26 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path(char *path, char *cmd)
{
	if (path && access(path, X_OK) != 0)
	{
		write(2, cmd, ft_strlen(cmd));
		write(2, ": command not found\n", 20);
		free(path);
		path = 0;
	}
	return (path);
}

void	exec_command(t_pipex *pipex)
{
	char	**argv;
	char	*binary_path;

	argv = ft_split(pipex->arg, ' ');
	binary_path = check_path(get_binary_path(argv[0], pipex->envp), pipex->arg);
	if (!binary_path || is_corrupted(argv, pipex->arg, ' '))
		free_resources(argv, binary_path);
	execve(binary_path, argv, pipex->envp);
	perror("execve");
	free_resources(argv, binary_path);
}
