/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:47:11 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 01:36:36 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** @brief Affiche le caractère c sur la sortie standard.
**
** @param Le caractère à afficher.
** @return Rien.
**
** @author lmazeaud
*/
void				ft_putchar(char c);

/*
** @brief Affiche la chaine s sur la sortie standard.
**
** @param La chaine de caractères à afficher.
** @return Rien.
**
** @author lmazeaud
*/
void				ft_putstr(char const *s);

/*
** @brief Affiche la chaine s sur la sortie standard suivi d’un ’\n’.
**
** @param La chaine de caractères à afficher.
** @return Rien;
**
** @author lmazeaud
*/
void				ft_putendl(char const *s);

/*
** @brief Affiche l’entier n sur la sortie standard.
**
** @param L’entier à afficher
** @return Rien.
**
** @author lmazeaud
*/
void				ft_putnbr(int n);

/*
** @brief Ecrit le caractère c sur le descripteur de fichier fd.
**
** @param Le caractères à écrire
** @param Le descripteur de fichier
** @return Rien.
**
** @author lmazeaud
*/
void				ft_putchar_fd(char c, int fd);

/*
** @brief Ecrit l’entier n sur le descripteur de fichier fd.
**
** @param L’entier à écrire.
** @param Le descripteur de fichier.
** @return Rien.
**
** @author lmazeaud
*/
void				ft_putnbr_fd(int n, int fd);

/*
** @brief Ecrit la chaine s sur le descripteur de fichier fd.
**
** @param La chaine de caractères à écrire.
** @param Le descripteur de fichier.
** @return Rien
**
** @author lmazeaud
*/
void				ft_putstr_fd(char const *s, int fd);

/*
** @brief Ecrit la chaine s sur le descripteur de fichier fd suivi d’un ’\n’.
**
** @param La chaine de caractères à écrire.
** @param Le descripteur de fichier.
** @return Rien.
**
** @author lmazeaud
*/
void				ft_putendl_fd(char const *s, int fd);

/*
** @brief 	Alloue (avec malloc(3)) et retourne une zone de mémoire
**			“fraiche”. La mémoire allouée est initialisée à 0. Si l’allocation
**			échoue, la fonction renvoie NULL.
**
** @param La taille de la zone de mémoire à allouer. (via sizeof())
** @return La zone de mémoire allouée. (cast void*)
**
** @author lmazeaud
*/
void				*ft_memalloc(size_t size);

/*
** @brief  Calcule la longueur de la chaîne de caractères s,
**			sans compter l'octet nul « \0 » final.
**
** @param Chaine de caratères à calculé
** @return Renvoie le nombre de caractères dans la chaîne s
**
** @author lmazeaud
*/
size_t				ft_strlen(const char *str);

/*
** @brief renvoie un pointeur sur une nouvelle chaîne de caractères
**			qui est dupliquée depuis s
**
** @param chaîne de caractères à dupliquer
** @return chaine de caratères dupluquée
**
** @author lmazeaud
*/
char				*ft_strdup(const char *s);

/*
** @brief copie la chaîne pointée par src dans  la  chaîne  pointée
**			par  dest.
**
** @param chaine de destination
** @param chaine de source
** @return un pointeur sur la chaîne destination dest.
**
** @author lmazeaud
*/
char				*ft_strcpy(char *dest, const char *src);

/*
** @brief seuls les n premiers octets de src sont copiés
**
** @param chaine de destination
** @param chaine de source
** @param nombre de caractères à copier
** @return un pointeur sur la chaîne destination dest.
**
** @author lmazeaud
*/
char				*ft_strncpy(char *dest, const char *src, size_t n);

size_t				ft_strlcat(char *dest, const char *src, size_t size);

char				*ft_strchr(const char *str, int c);

char				*ft_strrchr(const char *str, int c);

char				*ft_strstr(const char *str, const char *to_find);

void				*ft_memset(void *str, int c, size_t n);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);

char				*ft_strncat(char *s1, const char *s2, size_t n);

char				*ft_strnstr(const char	*src, const char *to_find,
								size_t len);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t size);

char				*ft_strcat(char *dest, const char *src);

int					ft_atoi(const char *str);

int					ft_isupper(int c);

int					ft_islower(int c);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_tolower(int c);

int					ft_toupper(int c);

void				ft_putwchar(wchar_t wc);

void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t n);

void				*ft_memchr(const void *src, int c, size_t n);

int					ft_memcmp(const void *str1, const void *str2, size_t n);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

int					ft_isblanks(int c);

char				*ft_strtrim(char const *s);

int					ft_word_count(char *s, int c);

char				**ft_strsplit(const char *str, char c);

char				*ft_itoa(int n);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_printnum_lst(t_list **alst);

void				ft_printnum_arr(int **arr);

void				ft_printstr_arr(const char **arr);

void				ft_printstr_lst(t_list **alst);

int					ft_sqrt(int nb);

char				*ft_strndup(const char *s, size_t n);

char				*ft_strcut(char **src, int c);

char				*ft_strncut(char **src, size_t n);

int					ft_strhas(char *str, int c);

char				*ft_cutstr(char *src, int c);

int					ft_strhas_digit(const char *str);

int					ft_strhas_str(const char *str, const char *find);

int					ft_strhas_char(char *str, int c);

char				*ft_strtoupper(char *str);

char				*ft_itoa_base_intmax(intmax_t n, int base);

char				*ft_itoa_base_uintmax(uintmax_t n, int base);

int					ft_strhaszero(char *str, int c);

char				*ft_itoa_intmax(intmax_t nb);

char				*ft_strreplace(char *str, int letter, size_t index);

intmax_t			ft_abs_intmax(intmax_t value);

size_t				ft_strwlen(wchar_t *str);

size_t				ft_wcharlen(wchar_t c);

char				*ft_fillit(char c, size_t n);

void				ft_wbzero(wchar_t *str, size_t nb);

#endif
