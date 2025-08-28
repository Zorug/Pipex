/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:36:43 by cgross-s          #+#    #+#             */
/*   Updated: 2025/08/27 22:49:40 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_free_memory(char **path, char *path_command)
{
	ft_free_array(path);
	free(path_command);
}

void	ft_cleanup(t_pipex *pipex)
{
	if (pipex->fd_infile >= 0)
		close(pipex->fd_infile);
	if (pipex->fd_outfile >= 0)
		close(pipex->fd_outfile);
	if (pipex->path_cmd1)
		free(pipex->path_cmd1);
	if (pipex->path_cmd2)
		free(pipex->path_cmd2);
	if (pipex->args_cmd1)
		ft_free_array(pipex->args_cmd1);
	if (pipex->args_cmd2)
		ft_free_array(pipex->args_cmd2);
	unlink(URANDOM_PATH);
}

void	custom_error(char *file, char *message, t_pipex *pipex, int error)
{
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	ft_cleanup(pipex);
	exit(error);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
int	ft_error(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	exit(EXIT_FAILURE);
}
