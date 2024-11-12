/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:57:53 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/12 22:33:49 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <csignal>


int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	clear_console();
	while (i < argc)
	{
		if (!strcmp(argv[i], "isalnum"))
			launch_test("ft_isalnum");
		else if (!strcmp(argv[i], "isalpha"))
			launch_test("ft_isalpha");
		else if (!strcmp(argv[i], "isascii"))
			launch_test("ft_isascii");
		else if (!strcmp(argv[i], "isdigit"))
			launch_test("ft_isdigit");
		else if (!strcmp(argv[i], "isprint"))
			launch_test("ft_isprint");
		else if (!strcmp(argv[i], "strlen"))
			launch_test("ft_strlen");
		else if (!strcmp(argv[i], "memset"))
			launch_test("ft_memset");
		else if (!strcmp(argv[i], "bzero"))
			launch_test("ft_bzero");
		else if (!strcmp(argv[i], "memcpy"))
			launch_test("ft_memcpy");
		else if (!strcmp(argv[i], "memmove"))
			launch_test("ft_memmove");
		else if (!strcmp(argv[i], "strlcpy"))
			launch_test("ft_strlcpy");
		else if (!strcmp(argv[i], "strlcat"))
			launch_test("ft_strlcat");
		else if (!strcmp(argv[i], "toupper"))
			launch_test("ft_toupper");
		else if (!strcmp(argv[i], "tolower"))
			launch_test("ft_tolower");
		else if (!strcmp(argv[i], "strchr"))
			launch_test("ft_strchr");
		else if (!strcmp(argv[i], "strrchr"))
			launch_test("ft_strrchr");
		else if (!strcmp(argv[i], "strncmp"))
			launch_test("ft_strncmp");
		else if (!strcmp(argv[i], "memchr"))
			launch_test("ft_memchr");
		else if (!strcmp(argv[i], "memcmp"))
			launch_test("ft_memcmp");
		else if (!strcmp(argv[i], "strnstr"))
			launch_test("ft_strnstr");
		else if (!strcmp(argv[i], "atoi"))
			launch_test("ft_atoi");
		else if (!strcmp(argv[i], "calloc"))
			launch_test("ft_calloc");
		else if (!strcmp(argv[i], "strdup"))
			launch_test("ft_strdup");
		else if (!strcmp(argv[i], "substr"))
			launch_test("ft_substr");
		else if (!strcmp(argv[i], "strjoin"))
			launch_test("ft_strjoin");
		else if (!strcmp(argv[i], "strtrim"))
			launch_test("ft_strtrim");
		else if (!strcmp(argv[i], "split"))
			launch_test("ft_split");
		else if (!strcmp(argv[i], "itoa"))
			launch_test("ft_itoa");
		else if (!strcmp(argv[i], "strmapi"))
			launch_test("ft_strmapi");
		else if (!strcmp(argv[i], "striteri"))
			launch_test("ft_striteri");
		else if (!strcmp(argv[i], "putchar_fd"))
			launch_test("ft_putchar_fd");
		else if (!strcmp(argv[i], "putstr_fd"))
			launch_test("ft_putstr_fd");
		else if (!strcmp(argv[i], "putendl_fd"))
			launch_test("ft_putendl_fd");
		else if (!strcmp(argv[i], "putnbr_fd"))
			launch_test("ft_putnbr_fd");
		else if (!strcmp(argv[i], "lstnew"))
			launch_test("ft_lstnew");
		else if (!strcmp(argv[i], "lstadd_front"))
			launch_test("ft_lstadd_front");
		else if (!strcmp(argv[i], "lstsize"))
			launch_test("ft_lstsize");
		else if (!strcmp(argv[i], "lstlast"))
			launch_test("ft_lstlast");
		else if (!strcmp(argv[i], "lstadd_back"))
			launch_test("ft_lstadd_back");
		else if (!strcmp(argv[i], "lstdelone"))
			launch_test("ft_lstdelone");
		else if (!strcmp(argv[i], "lstclear"))
			launch_test("ft_lstclear");
		else if (!strcmp(argv[i], "lstiter"))
			launch_test("ft_lstiter");
		else if (!strcmp(argv[i], "lstmap"))
			launch_test("ft_lstmap");
		else if (!strcmp(argv[i], "all") || argc <= 1)
		{
			launch_test("ft_isalnum");
			launch_test("ft_isalpha");
			launch_test("ft_isascii");
			launch_test("ft_isdigit");
			launch_test("ft_isprint");
			launch_test("ft_strlen");
			launch_test("ft_memset");
			launch_test("ft_bzero");
			launch_test("ft_memcpy");
			launch_test("ft_memmove");
			launch_test("ft_strlcpy");
			launch_test("ft_strlcat");
			launch_test("ft_toupper");
			launch_test("ft_tolower");
			launch_test("ft_strchr");
			launch_test("ft_strrchr");
			launch_test("ft_strncmp");
			launch_test("ft_memchr");
			launch_test("ft_memcmp");
			launch_test("ft_strnstr");
			launch_test("ft_atoi");
			launch_test("ft_calloc");
			launch_test("ft_strdup");
			launch_test("ft_substr");
			launch_test("ft_strjoin");
			launch_test("ft_strtrim");
			launch_test("ft_split");
			launch_test("ft_itoa");
			launch_test("ft_strmapi");
			launch_test("ft_striteri");
			launch_test("ft_putchar_fd");
			launch_test("ft_putstr_fd");
			launch_test("ft_putendl_fd");
			launch_test("ft_putnbr_fd");
			launch_test("ft_lstnew");
			launch_test("ft_lstadd_front");
			launch_test("ft_lstsize");
			launch_test("ft_lstlast");
			launch_test("ft_lstadd_back");
			launch_test("ft_lstdelone");
			launch_test("ft_lstclear");
			launch_test("ft_lstiter");
			launch_test("ft_lstmap");
		}
		else
			printf("Error: \"%s\" is not a function ", argv[i]);
		i++;
	}
}

void	launch_test(char *filename)
{
	int		pipefd[2];
	int		pid;
	char	buffer[1024];
	int		status;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		dup2(pipefd[1], STDERR_FILENO);
		close(pipefd[1]);

		execl(filename, filename, NULL);
		perror("execl");
		exit(EXIT_FAILURE);
	}
	else
	{
		close(pipefd[1]);
		waitpid(pid, &status, 0);

		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		{
			printf("Segmentation fault detected for %s\n", filename);
			return (1);
		}

		read(pipefd[0], buffer, sizeof(buffer));
		close(pipefd[0]);

		printf("Output of %s:\n%s\n", filename, buffer);
		return (0);
	}
}
