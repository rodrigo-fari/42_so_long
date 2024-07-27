/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:41:20 by rde-fari          #+#    #+#             */
/*   Updated: 2024/07/27 16:38:30 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//---------Libft Library----------//
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>

//---------Printf_Library----------//
# include <stdarg.h>

//---------Get_Next_Line_Library----------//
# include <fcntl.h>

//---------Libft Functions---------//
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *nptr);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned	int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);

void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

//---------Libft Bonus Functions---------//
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));

//---------ft_printf Functions---------//

int		ft_int_len(int num);
int		ft_printf(const char *format, ...);

void	ft_putnbr_fd(int n, int fd);
void	ft_putncount(char a, int *total);
void	ft_strncount(char *string, int *total);
void	ft_unsint(unsigned int num, int *total);
void	ft_intncount(va_list ap, char format, int *total);
void	ft_ptrhex(char format, unsigned long num, int *total);
void	ft_hexapplier(char format, unsigned long num, int *total);
void	ft_check_char(const char *format, va_list ap, int *total);

//---------Get Next Line Functions---------//

char	*remaining(char *ptr);
char	*get_next_line(int fd);
char	*get_esp_line(char	*ptr);
char	*file_reader(char *ptr, int fd);
char	*ft_char_strjoin(char *str1, char *str2);
char	*ft_strcpy(char *src, char *dest, int param);

int		nline_scan(char *str, int c);

size_t	ft_char_strlen(char *str);

void	*ft_calloc(size_t nmemb, size_t size);

//---------End If---------//
#endif
