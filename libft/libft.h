/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:15:17 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/14 16:26:08 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 128

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *restrict s1, const char *restrict s2,
				size_t n);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
void			ft_putendl(char const *s);
void			ft_strdel(char **as);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_issign(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_dec_to_base(long nbr, const char *base);
long			ft_base_to_dec(char *base_str, char *base);
char			*ft_strrev(char *str);
long			ft_ipower(long nbr, long pwr);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
unsigned char	*ft_to_utf8(int nbr);
size_t			ft_lstlen(t_list **alst);
t_list			*ft_lstget(t_list **alst, size_t n);
t_list			*ft_strsplitlst(char const *s, char c);
size_t			ft_strlenc(const char *str, char c);
void			ft_lstrem(t_list **prev, t_list **to_del);
size_t			ft_lstsrchi(t_list **lst, char *s);
size_t			ft_striterc(char *s, int (*f)(int));
size_t			ft_strsplitcnt(char const *s, char c);
char			*ft_strncatf(char *s1, char*s2);
int				ft_fchar(char c, char *str);
int				get_next_line(const int fd, char **line);
int				*ft_strsplitint(char *str, int c);
void			ft_lstaddend(t_list **alst, t_list *new);

#endif
