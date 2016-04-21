/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:23:01 by sksourou          #+#    #+#             */
/*   Updated: 2015/11/24 18:16:56 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 42
# define A			0
# define INDICE		1
# define RET		2

typedef struct s_room t_room;

typedef struct s_list
{
	t_room			*data;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;


void				stock_line(char *buf, char *line, int *i, int *var);
int					get_next_line(int const fd, char **line);
char				*ft_strncat(char *s1, char const *s2, size_t n);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
char				*ft_strcat(char *s1, char const *s2);
size_t				ft_strlen(char const *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
int					ft_isalpha(int c);
char				ft_isdigit(char c);
int					ft_isalnum(int c);
int					ft_isascii(char c);
int					ft_isprint(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isspace(int c);
int					ft_iswhite(int c);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dest, char const *src, size_t n);
char				*ft_strcpy(char *dest, char const *src);
int					ft_atoi(char *s);
char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);
void				*ft_memset(void *s, int c, size_t len);
void				*ft_memccpy(void *dst, void const *src, int c, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				*ft_memmove(void *dst, void const *src, size_t n);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_bzero(void *s, size_t n);
char				*ft_strrev(char *str);
char				*ft_strstr(char const *s1, char const *s2);
char				*ft_strnstr(char const *s1, char const *s2, size_t n);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					get_next_line(int const fd, char **line);
size_t				list_size(t_list *list);
t_list				*link_init(void *data);
t_list				*list_end(t_list *list);
t_list				*list_second(t_list *list);
void				list_swap_data(t_list *l1, t_list *l2);
void				list_add_next(t_list **list, t_list *link);
void				print_list(t_list *list);

#endif
