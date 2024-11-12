/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:57:53 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/12 23:15:03 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

const char *ALL[] = {"all", "fight me", NULL};
const char *FT_ISALNUM[] = {"ft_isalnum", "isalnum", NULL};
const char *FT_ISALPHA[] = {"ft_isalpha", "isalpha", NULL};
const char *FT_ISASCII[] = {"ft_isascii", "isascii", NULL};
const char *FT_ISDIGIT[] = {"ft_isdigit", "isdigit", NULL};
const char *FT_ISPRINT[] = {"ft_isprint", "isprint", NULL};
const char *FT_STRLEN[] = {"ft_strlen", "strlen", NULL};
const char *FT_MEMSET[] = {"ft_memset", "memset", NULL};
const char *FT_BZERO[] = {"ft_bzero", "bzero", NULL};
const char *FT_MEMCPY[] = {"ft_memcpy", "memcpy", NULL};
const char *FT_MEMMOVE[] = {"ft_memmove", "memmove", NULL};
const char *FT_STRLCPY[] = {"ft_strlcpy", "strlcpy", NULL};
const char *FT_STRLCAT[] = {"ft_strlcat", "strlcat", NULL};
const char *FT_TOUPPER[] = {"ft_toupper", "toupper", NULL};
const char *FT_TOLOWER[] = {"ft_tolower", "tolower", NULL};
const char *FT_STRCHR[] = {"ft_strchr", "strchr", NULL};
const char *FT_STRRCHR[] = {"ft_strrchr", "strrchr", NULL};
const char *FT_STRNCMP[] = {"ft_strncmp", "strncmp", NULL};
const char *FT_MEMCHR[] = {"ft_memchr", "memchr", NULL};
const char *FT_MEMCMP[] = {"ft_memcmp", "memcmp", NULL};
const char *FT_STRNSTR[] = {"ft_strnstr", "strnstr", NULL};
const char *FT_ATOI[] = {"ft_atoi", "atoi", NULL};
const char *FT_CALLOC[] = {"ft_calloc", "calloc", NULL};
const char *FT_STRDUP[] = {"ft_strdup", "strdup", NULL};
const char *FT_SUBSTR[] = {"ft_substr", "substr", NULL};
const char *FT_STRJOIN[] = {"ft_strjoin", "strjoin", NULL};
const char *FT_STRTRIM[] = {"ft_strtrim", "strtrim", NULL};
const char *FT_SPLIT[] = {"ft_split", "split", NULL};
const char *FT_ITOA[] = {"ft_itoa", "itoa", NULL};
const char *FT_STRMAPI[] = {"ft_strmapi", "strmapi", NULL};
const char *FT_STRITERI[] = {"ft_striteri", "striteri", NULL};
const char *FT_PUTCHAR_FD[] = {"ft_putchar_fd", "putchar_fd", NULL};
const char *FT_PUTSTR_FD[] = {"ft_putstr_fd", "putstr_fd", NULL};
const char *FT_PUTENDL_FD[] = {"ft_putendl_fd", "putendl_fd", NULL};
const char *FT_PUTNBR_FD[] = {"ft_putnbr_fd", "putnbr_fd", NULL};
const char *FT_LSTNEW[] = {"ft_lstnew", "lstnew", NULL};
const char *FT_LSTADD_FRONT[] = {"ft_lstadd_front", "lstadd_front", NULL};
const char *FT_LSTSIZE[] = {"ft_lstsize", "lstsize", NULL};
const char *FT_LSTLAST[] = {"ft_lstlast", "lstlast", NULL};
const char *FT_LSTADD_BACK[] = {"ft_lstadd_back", "lstadd_back", NULL};
const char *FT_LSTDELONE[] = {"ft_lstdelone", "lstdelone", NULL};
const char *FT_LSTCLEAR[] = {"ft_lstclear", "lstclear", NULL};
const char *FT_LSTITER[] = {"ft_lstiter", "lstiter", NULL};
const char *FT_LSTMAP[] = {"ft_lstmap", "lstmap", NULL};

int	ft_str_search( char **dictionary, char *str);

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_str_search(str_tolower(argv[i]), FT_ISALNUM))
			
		i++;
	}
	return (0);
}

int	ft_str_search(char **dictionary, char *str)
{
	int	i;

	i = 0;
	if (!dictionary || !str)
		return (0);
	while (dictionary[i])
	{
		if (strcmp(dictionary[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*str_tolower(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
