/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:32:46 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/21 20:32:46 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *destination, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int d);
int		ft_isprint(int c);
void	*ft_memccpy(void *destination, const void *source, int c, size_t n);
void	*ft_memchr(const void *arr, int c, size_t n);
int		ft_memcmp(const void *arr1, const void *arr2, size_t n);
void	*ft_memcpy(void *destination, const void *source, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *destination, int c, size_t n);
char	*ft_strchr(const char *str, int symbol);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *str, int symbol);
int		ft_tolower(int character);
int		ft_toupper(int character);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t number, size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void	ft_putstr(char *str);
void	ft_putchar(char c);

#endif
