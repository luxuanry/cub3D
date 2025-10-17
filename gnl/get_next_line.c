/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:08:19 by rxue              #+#    #+#             */
/*   Updated: 2024/12/17 18:55:40 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_stash(int fd, char *stash)
{
	char	*buf;
	char	*temp;
	int		read_bytes;

	read_bytes = 1;
	while (!found_newline(stash) && read_bytes != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		read_bytes = (int)read(fd, buf, BUFFER_SIZE);
		if ((!stash && read_bytes == 0) || read_bytes == -1)
			return (free(buf), free(stash), stash = NULL, NULL);
		buf[read_bytes] = '\0';
		temp = ft_strjoin1(stash, buf);
		free(stash);
		stash = temp;
		free(buf);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (stash[i] == 0)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (stash[++i] && stash[i] != '\n')
		line[i] = stash[i];
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash [i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), stash = NULL, NULL);
	new_stash = (char *)malloc(sizeof(char) * (ft_strlen1(stash) - i + 1));
	if (!new_stash)
		return (free(stash), stash = NULL, NULL);
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	return (free(stash), stash = NULL, new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}
