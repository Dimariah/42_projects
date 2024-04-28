/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:24:00 by yiken             #+#    #+#             */
/*   Updated: 2024/04/26 09:54:50 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include "gnl/get_next_line.h"

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	char	*arg;
	char	**av;
	char	**envp;
	int		index;
	int		*pipefd;
	bool	here_doc;
}	t_pipex;

char	*get_full_path(char **envp);
int		is_corrupted(char **argv, char *str, char sep);
char	*get_next_word(char *str, char sep, bool reset);
char	*str_join(char *dir, char *cmd);
int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	**ft_split(char *str, char sep);
void	free_resources(char **argv, char *binary_path);
char	*get_binary_path(char *cmd, char **envp);
int		open_file(char *filename, int is_inp);
void	exec_command(t_pipex *pipex);

#endif
