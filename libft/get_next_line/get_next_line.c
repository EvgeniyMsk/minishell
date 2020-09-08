/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:08:26 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:08:49 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int		write_to_table(char **fd_tab, int fd, char *nl_ptr)
{
	size_t	len;
	char	*new;

	if (nl_ptr == NULL || *(nl_ptr + 1) == '\0')
	{
		free(fd_tab[fd]);
		fd_tab[fd] = NULL;
		return (0);
	}
	len = ft_strlen(nl_ptr + 1);
	if (!(new = (char *)malloc(len + 1)))
		return (-1);
	ft_memcpy(new, nl_ptr + 1, len + 1);
	free(fd_tab[fd]);
	fd_tab[fd] = new;
	return (0);
}

static int		get_tab_line_and_write_reminder(char **fd_tab, \
		int fd, char **line)
{
	char	*nl_ptr;
	size_t	len;

	if (fd_tab[fd] != NULL)
	{
		nl_ptr = ft_strchr(fd_tab[fd], '\n');
		if (nl_ptr == NULL)
			len = ft_strlen(fd_tab[fd]);
		else
			len = nl_ptr - fd_tab[fd];
		if (!(*line = (char *)malloc(len + 1)))
			return (-1);
		(*line)[len] = '\0';
		ft_memcpy(*line, fd_tab[fd], len);
		if (write_to_table(fd_tab, fd, nl_ptr))
			return (-1);
		return ((nl_ptr == NULL) ? 0 : 1);
	}
	if (!(*line = (char *)malloc(1)))
		return (-1);
	**line = '\0';
	return (0);
}

static int		write_reminder_from_table(char **fd_tab, int fd, \
		char **line, char *buffer)
{
	char	*nl_ptr;
	char	*new;

	nl_ptr = ft_strchr(buffer, '\n');
	if (nl_ptr == NULL)
	{
		if (!(new = ft_strjoin(*line, buffer)))
			return (-1);
		free(*line);
		*line = new;
		return (0);
	}
	*nl_ptr = '\0';
	if (!(new = ft_strjoin(*line, buffer)))
		return (-1);
	free(*line);
	*line = new;
	if (*(nl_ptr + 1) != '\0')
		if (!(fd_tab[fd] = ft_strdup(nl_ptr + 1)))
			return (-1);
	return (1);
}

static void		free_buffers(char **fd_tab, char **line)
{
	int		i;

	i = 0;
	while (i < 1024)
	{
		if (fd_tab[i] != NULL)
		{
			free(fd_tab[i]);
			fd_tab[i] = NULL;
		}
		++i;
	}
	if (*line != NULL)
	{
		free(*line);
		*line = NULL;
	}
}

int				get_next_line(int fd, char **line)
{
	static char		*fd_tab[1024] = {NULL};
	char			buffer[BUFFER_SIZE + 1];
	int				ret;

	if (fd < 0 || fd > 1023 || line == NULL)
		return (-1);
	ret = get_tab_line_and_write_reminder(fd_tab, fd, line);
	if (ret != 0)
	{
		if (ret == -1)
			free_buffers(fd_tab, line);
		return (ret);
	}
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		ret = write_reminder_from_table(fd_tab, fd, line, buffer);
		if (ret != 0)
			break ;
	}
	if (ret == -1)
		free_buffers(fd_tab, line);
	return (ret);
}
