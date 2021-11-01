/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 13:09:12 by rvan-mee      #+#    #+#                 */
/*   Updated: 2021/11/01 09:48:34 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

char	*fill_backup(char *backupstr, char *returnstr)
{
//	printf("------------------ fill_backup ----------------\n");
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
	//printf(" ----------------- ft_calloc -----------------\n");
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
	//printf(" ----------------- check_4_newline ----------- \n");
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
//	printf("------------------ get_return_line ------------\n");
	char	buffer[BUFFER_SIZE + 1];
	int		bytesread;
	int		i;

	i = 0;
	bytesread = -1;
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
	//printf("------------------ get_next_line --------------\n");
	char		*returnstr;
	static char	backupstr[OPEN_MAX + 1][BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || !fd)
		return (NULL);
	returnstr = ft_calloc(BUFFER_SIZE + 1);
	if (!returnstr)
		return (NULL);
	returnstr = merge_str(returnstr, backupstr[fd]);
	if (!returnstr)
		return (NULL);
	if (check_4_newline(backupstr[fd]))
	{
		returnstr = get_return_line(fd, returnstr);
		if (!returnstr)
			return (NULL);
	}
	fill_backup(backupstr[fd], returnstr);
	returnstr = remove_till_newline(returnstr);
	return (returnstr);
}






// gcc -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c