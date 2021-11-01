/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 13:09:12 by rvan-mee      #+#    #+#                 */
/*   Updated: 2021/11/01 16:19:28 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

char	*fill_backup(char *backupstr, char *returnstr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (returnstr[i] != '\n' && returnstr[i] != '\0')
		i++;
	if (returnstr[i] == '\n')
		i++;
	while (returnstr[i + j] != '\0')
	{
		backupstr[j] = returnstr[i + j];
		j++;
	}
	backupstr[j] = '\0';
	return (backupstr);
}

char	*ft_calloc(int len)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(len);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

int	check_4_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*get_return_line(int fd, char *str)
{
//	printf("TEST get_return_line buffersize: %d\n", BUFFER_SIZE);
	char	buffer[BUFFER_SIZE + 1];
	int		bytesread;
	int		i;

	i = 0;
	bytesread = -1;
//	printf("TEST get_return_line buffersize: %d\n", BUFFER_SIZE);
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
	while (bytesread != 0 && check_4_newline(str))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
			return (NULL);
		str = merge_str(str, buffer);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*returnstr;
	static char	backupstr[OPEN_MAX + 1][BUFFER_SIZE + 1];

//	printf("TEST\n");
	//static char test[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE];
//	printf("TEST buffersize: %d\n", BUFFER_SIZE);
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	returnstr = ft_calloc(BUFFER_SIZE + 1);
	if (!returnstr)
		return (NULL);
//	printf("TEST after calloc\n");
	returnstr = merge_str(returnstr, backupstr[fd]);
	if (!returnstr)
		return (NULL);
//	printf("TEST after merge_str\n");
	if (check_4_newline(backupstr[fd]))
	{
//		printf("TEST after if\n");
		returnstr = get_return_line(fd, returnstr);
		if (!returnstr)
			return (NULL);
//		printf("TEST after get_return_line\n");
	}
//	printf("TEST\n");
	fill_backup(backupstr[fd], returnstr);
	returnstr = remove_till_newline(returnstr);
	return (returnstr);
}
