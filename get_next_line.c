/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrullah <emrullah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 23:02:57 by etasci            #+#    #+#             */
/*   Updated: 2026/03/13 17:34:25 by emrullah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char	*ft_read_and_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes;
	char	*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
	}
	free(buffer);
	return (stash);
}
static char *extract_line(char *stash)
{
	int	i;
	char	*line;

	if(!stash || stash[0] == '\0')
		return(NULL);
	i = 0;
	while(stash[i] && stash[i] != '\n')
		i++;
	 if (stash[i] == '\n')  // Eğer '\n' var, satırı da dahil etmek için +1
	 	i++;
	line = malloc(i + 1);
	if(!line)
		return(NULL);
	i = 0;
	while(stash[i] && stash[i] != '\n')
		line[i] = stash[i];
		i++;
	if (stash[i] == '\n')
        line[i++] = '\n';

    line[i] = '\0';
    return (line);
}


#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	if (fd < 0)
	{
		printf("Dosya açılamadı!\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return 0;
}




