/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:22:46 by yiken             #+#    #+#             */
/*   Updated: 2024/04/25 12:52:08 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex, char **av, int ac, char **envp)
{
	if (ac < 5)
		exit(1);
	pipex->av = av;
	pipex->envp = envp;
	pipex->here_doc = false;
	pipex->index = 1;
}

void	child_process(t_pipex *pipex)
{
	if (pipex->index == 1)
	{
		pipex->in_fd = open_file(pipex->arg, 1);
		dup2(pipex->in_fd, STDIN_FILENO);
		close(pipex->in_fd);
		pipex->arg = pipex->av[pipex->index + 1];
	}
	close(pipex->pipefd[0]);
	dup2(pipex->pipefd[1], STDOUT_FILENO);
	close(pipex->pipefd[1]);
	exec_command(pipex);
}

void	handle_arg(t_pipex *pipex)
{
	int	pipefd[2];
	int	pid;

	if (pipe(pipefd) == -1)
	{
		close(STDIN_FILENO);
		perror("pipe");
		exit(1);
	}
	pipex->pipefd = pipefd;
	pid = fork();
	if (pid == 0)
		child_process(pipex);
	else if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	wait(0);
	if (pipex->index == 1)
		pipex->index++;
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
}

void	here_doc(char **av)
{
	int		pipefd[2];
	char	*line;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	line = get_next_line(STDIN_FILENO);
	while (line && ft_strncmp(line, av[2], 0))
	{
		write(pipefd[1], line, ft_strlen(line));
		write(pipefd[1], "\n", 1);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	init_pipex(&pipex, av, ac, envp);
	if (!ft_strncmp(av[1], "here_doc", 8))
	{
		here_doc(av);
		pipex.here_doc = true;
		pipex.index = 3;
	}
	while (pipex.index < ac - 2)
	{
		pipex.arg = av[pipex.index];
		handle_arg(&pipex);
		pipex.index++;
	}
	pipex.arg = av[pipex.index];
	pipex.out_fd = open_file(av[ac - 1], 2);
	if (!pipex.here_doc)
	{
		close(pipex.out_fd);
		pipex.out_fd = open_file(av[ac - 1], 3);
	}
	dup2(pipex.out_fd, STDOUT_FILENO);
	close(pipex.out_fd);
	exec_command(&pipex);
}
