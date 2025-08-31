/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:16:41 by cgross-s          #+#    #+#             */
/*   Updated: 2025/08/31 12:33:48 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <stdio.h>
# include <time.h>
# include "../libft/libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <string.h>

# define URANDOM_PATH ".pipex_urandom"

typedef enum e_args
{
	PROGRAM,
	INFILE,
	CMD1,
//	CMD2,
	OUTFILE
}	t_args;

typedef enum e_errors
{
	NO_COMAND	= 0,
	NO_FILE	= 2,
	BAD_FD = 9
}	t_errors;

typedef struct s_pipex
{
	int		fd_infile;
	int		fd_outfile;
//	char	*path_cmd1;
//	char	*path_cmd2;
//	char	**args_cmd1;
//	char	**args_cmd2;
	char	**paths_cmds;	// Array de paths para todos os comandos
	char	***args_cmds;	// Array de arrays de argumentos
	int		cmd_count;		// Número total de comandos
}	t_pipex;

char	**ft_split_mod(char *s);
char	*get_path(char *command, char **envp);
void	ft_free_array(char **path);
void	custom_error(char *file, char *message, t_pipex *pipex, int error);
void	ft_cleanup(t_pipex *pipex);
void	remove_spaces(char **array);
void	handle_urandom(void);
void	ft_free_memory(char **path, char *path_command);
int		ft_error(char *error_message);
char	*ft_strndup(const char *s, size_t len);
int		ft_countword(const char *input);
char	**remove_scape_symbol(char **s);
void	setup_outfile(t_pipex *pipex, char **argv);
void	setup_infile(t_pipex *pipex, char **argv);
char	*is_script(char *cmd);

/*main.c*/
void check_args(t_pipex *pipex, char **argv, char **envp);

/*pipex.c*/
void	ft_execve(char *cmd, char **args, t_pipex *pipex, char **envp);
void	close_all_pipes(int *pipes, int pipe_count);
void	child_process(int cmd_index, int *pipes, t_pipex *pipex, char **envp, char **argv);
void	ft_exec(t_pipex *pipex, char **envp, char **argv);

#endif 