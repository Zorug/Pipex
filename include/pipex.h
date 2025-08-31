/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:16:41 by cgross-s          #+#    #+#             */
/*   Updated: 2025/08/31 16:38:11 by cgross-s         ###   ########.fr       */
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
	char	**paths_cmds;	// Array de paths para todos os comandos
	char	***args_cmds;	// Array de arrays de argumentos
	int		cmd_count;		// Número total de comandos
}	t_pipex;



//void	remove_spaces(char **array);
//void	handle_urandom(void);
//char	*ft_strndup(const char *s, size_t len);
//void	setup_outfile(t_pipex *pipex, char **argv);
//void	setup_infile(t_pipex *pipex, char **argv);
//char	*is_script(char *cmd);

/*error_handling.c*/
void	ft_free_memory(char **path, char *path_command);
void	ft_cleanup(t_pipex *pipex);
void	custom_error(char *file, char *message, t_pipex *pipex, int error);
void	ft_free_array(char **path);
int		ft_error(char *error_message);

/*ft_split_mod.c*/
char	*get_string(const char *s);
void	clean_words(int words, char **array);
char	**ft_split_mod(char *s);

/*ft_split_utils.c*/
int		ft_countword(const char *input);
int		array_size(char **array);
char	*remove_backslashes(char *s);
char	**remove_scape_symbol(char **s);

/*get_path.c*/
char	*ft_get_path_aux(char **envp);
char	*ft_check_command_location(char *command, char *path_i);
char	*find_path(char *path_aux, char *command);
char	*get_path(char *command, char **envp);

/*handle_urandom.c*/
int		ft_read(char **line, int fd, char limiter);
void	handle_urandom(void);

/*main.c*/
//void check_args(t_pipex *pipex, char **argv, char **envp);
//void init_pipex(t_pipex *pipex, int cmd_count);

/*parsing_utils.c*/
int		is_only_spaces(const char *str);
void	copy_non_space_strings(char **dest, char **src);
void	remove_spaces(char **array);
char	*is_script(char *cmd);

/*pipex_utils.c*/
void	setup_outfile(t_pipex *pipex, char **argv);
void	setup_infile(t_pipex *pipex, char **argv);

/*pipex.c*/
void	ft_execve(char *cmd, char **args, t_pipex *pipex, char **envp);
void	close_all_pipes(int *pipes, int pipe_count);
void	child_process(int cmd_index, int *pipes, t_pipex *pipex, char **envp, char **argv);
void	ft_exec(t_pipex *pipex, char **envp, char **argv);

#endif 