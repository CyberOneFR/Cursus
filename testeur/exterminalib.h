/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exterminalib.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:39:50 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 06:26:03 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERMINALIB_H
# define EXTERMINALIB_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <ctype.h>
# include <sys/ioctl.h>
# include <signal.h>

//colors
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

//dictionnary for inputs
extern const char	*ALL[];
extern const char	*FT_ISALNUM[];
extern const char	*FT_ISALPHA[];
extern const char	*FT_ISASCII[];
extern const char	*FT_ISDIGIT[];
extern const char	*FT_ISPRINT[];
extern const char	*FT_STRLEN[];
extern const char	*FT_MEMSET[];
extern const char	*FT_BZERO[];
extern const char	*FT_MEMCPY[];
extern const char	*FT_MEMMOVE[];
extern const char	*FT_STRLCPY[];
extern const char	*FT_STRLCAT[];
extern const char	*FT_TOUPPER[];
extern const char	*FT_TOLOWER[];
extern const char	*FT_STRCHR[];
extern const char	*FT_STRRCHR[];
extern const char	*FT_STRNCMP[];
extern const char	*FT_MEMCHR[];
extern const char	*FT_MEMCMP[];
extern const char	*FT_STRNSTR[];
extern const char	*FT_ATOI[];
extern const char	*FT_CALLOC[];
extern const char	*FT_STRDUP[];
extern const char	*FT_SUBSTR[];
extern const char	*FT_STRJOIN[];
extern const char	*FT_STRTRIM[];
extern const char	*FT_SPLIT[];
extern const char	*FT_ITOA[];
extern const char	*FT_STRMAPI[];
extern const char	*FT_STRITERI[];
extern const char	*FT_PUTCHAR_FD[];
extern const char	*FT_PUTSTR_FD[];
extern const char	*FT_PUTENDL_FD[];
extern const char	*FT_PUTNBR_FD[];
extern const char	*FT_LSTNEW[];
extern const char	*FT_LSTADD_FRONT[];
extern const char	*FT_LSTSIZE[];
extern const char	*FT_LSTLAST[];
extern const char	*FT_LSTADD_BACK[];
extern const char	*FT_LSTDELONE[];
extern const char	*FT_LSTCLEAR[];
extern const char	*FT_LSTITER[];
extern const char	*FT_LSTMAP[];
extern const char	*COLORS[];

//screen struct
extern	struct winsize	w;

extern	char		*screen_buffer;
typedef struct s_object
{
	void			(*del)(void *content);
	void			(*f)(void *content);
	void			*content;
	struct s_object	*next;
}	t_object;
extern	t_object	*object_stack;
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;
typedef struct s_area
{
	t_point	p1;
	t_point	p2;
	char	c;
}	t_area;
typedef struct s_text
{
	t_point	p;
	char	*str;
}	t_text;

//important functions
void		garbage_collector(int err);
void		handle_input(void);

//screen functions
void		print_screen(void);
void		free_screen(void);
void		resize_screen(int sig);

//objects functions
t_object	*new_part(void (*del)(void *), void (*f)(void *), void *content);
t_area		*new_area(t_point p1, t_point p2, char c);
t_text		*new_text(int x, int y, char *str);
void		add_part(t_object *part);
void		del_part(t_object *part);
void		free_text(void *text);
void		free_area(void *area);
t_object	*last_part(void);

//print functions
void		print_center(void *text);
void		print_right(void *text);
void		print_left(void *text);
void		fill(void *area);
void		blank(void);

//utils functions
char		*ft_strdup(const char *s);
int			printable_len(char *str);

#endif