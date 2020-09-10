/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 15:58:29 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/09 20:30:19 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# define MAX_OUTPUTS 1024

typedef struct	s_command
{
	int			ac;
	char		**av;
	char		*cmd;
	char		*cmd_abs;
	int			in;
	int			out[MAX_OUTPUTS];
}				t_command;

typedef struct	s_terminal
{
	pid_t		pid;
	char		**env;
	int			status;
	int			mode;
	int			quote;
	int			dquote;
	t_list		*exp;
}				t_terminal;

typedef struct	s_var
{
	char		*key;
	char		*value;
}				t_var;

typedef struct	s_quoute
{
	int			q;
	int			dq;
	int			f_q;
	int			f_dq;
}				t_quote;

void			ft_minishell(void);
void			ft_show_term(void);
void			ft_read_command(char **line);
int				ft_check_input(char *input);
char			*ft_check_input_2(char *input);
void			ft_parse_input(char *cmd);
int				set_mode(char *arg);
void			ft_init_command(t_command *cmd);
void			ft_start_output(t_command *cmd, char *arg);
void			ft_start_input(t_command *cmd, char *arg);
void			ft_parse(t_command *cmd);
void			ft_handle_quote(char *c);
void			ft_handle_dquote(char *c);
void			ft_handle_letter(char *c);
void			decode_cmd(char *str);
void			encode_cmd(char *cmd);
int				ft_execute_command(t_command cmd);
void			ft_initialize(int n);
void			ft_handle_signals(void);
void			ft_translate(t_command *cmds);
void			ft_re_output(int *fds, int fd);
void			redirect(t_command cmd);
char			*get_env(char *var);
char			*get_path(char *cmd);
void			add_env(char *var);
void			ft_clear_env(char *var);
char			**copy_env(char **env);
void			ft_create(char *path, char *cmd, char *file_name[2]);
char			*replace(char *str);
int				builtin(t_command cmd);
void			ft_env(t_command cmd);
int				builtin_parent(t_command cmd);
void			ft_print_export(void);
void			quit(void);
void			ft_clear_var(void *element);
void			free_on_fail(t_command *cmds, int *j);
void			free_cmd(t_command cmd);
void			close_fd(t_command cmd);
char			**ft_shell_split(char const *s, char c);
char			**ft_pipe_split(char const *s, char c, char *cmd);

#endif
