/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 23:02:57 by etasci            #+#    #+#             */
/*   Updated: 2026/03/13 00:01:32 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char	*ft_read_and_stash(int fd, char *stash)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	return (stash);
}
static char *extract_line(char *stash)
{
	int	iİ
	char	*line;

	if(!stash || stash[0] == '\0')
		return(NULL);
	i = 0;
	while(stash[i] && stash[0] == '\0')
}







