#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void	del(void *content)
{
	free(content);
}

void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

void	add_x(unsigned int i, char *c)
{
	(void)i;
	*c = 'X';
}

char	test_upper(unsigned int i, char c)
{
	(void)i;
	return (ft_toupper(c));
}

void	*map_upper(void *content)
{
	char	*str;
	char	*new;
	int		i;

	str = (char *)content;
	new = malloc(strlen(str) + 1);
	if (!new)
		return (NULL);

	i = 0;
	while (str[i])
	{
		new[i] = ft_toupper(str[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	main(void)
{
	char	*str;
	char	*dup;
	char	**split;
	t_list	*head;
	t_list	*node;
	t_list	*mapped;

	printf("===== CHAR TEST =====\n");
	printf("isalpha A: %d\n", ft_isalpha('A'));
	printf("isdigit 5: %d\n", ft_isdigit('5'));
	printf("isalnum A: %d\n", ft_isalnum('A'));
	printf("isascii 127: %d\n", ft_isascii(127));
	printf("isprint A: %d\n", ft_isprint('A'));
	printf("toupper a: %c\n", ft_toupper('a'));
	printf("tolower A: %c\n", ft_tolower('A'));


	printf("\n===== STRING TEST =====\n");

	printf("strlen: %zu\n", ft_strlen("Hello"));

	printf("strchr: %s\n", ft_strchr("Hello", 'l'));
	printf("strrchr: %s\n", ft_strrchr("Hello", 'l'));

	printf("strncmp: %d\n",
		ft_strncmp("abc", "abd", 3));

	printf("strnstr: %s\n",
		ft_strnstr("Hello World", "World", 11));

	printf("atoi: %d\n",
		ft_atoi(" -1234"));

	str = ft_strdup("duplicate");
	printf("strdup: %s\n", str);
	free(str);


	printf("\n===== MEMORY TEST =====\n");

	char	mem1[10] = "abcdef";
	char	mem2[10] = "123456";

	ft_memset(mem1, 'X', 3);
	printf("memset: %s\n", mem1);

	ft_memcpy(mem2, "hello", 5);
	printf("memcpy: %s\n", mem2);

	ft_memmove(mem2 + 2, mem2, 5);
	printf("memmove: %s\n", mem2);

	printf("memcmp: %d\n",
		ft_memcmp("abc", "abd", 3));

	printf("memchr: %s\n",
		(char *)ft_memchr("hello", 'l', 5));


	printf("\n===== STRING CREATION =====\n");

	str = ft_substr("Hello World", 6, 5);
	printf("substr: %s\n", str);
	free(str);

	str = ft_strjoin("Hello ", "World");
	printf("join: %s\n", str);
	free(str);

	str = ft_strtrim("xxxHello xxx", "x");
	printf("trim: %s\n", str);
	free(str);

	split = ft_split("one,two,three", ',');
	printf("split:\n");
	for (int i = 0; split[i]; i++)
	{
		printf("%s\n", split[i]);
		free(split[i]);
	}
	free(split);

	str = ft_itoa(-12345);
	printf("itoa: %s\n", str);
	free(str);


	printf("\n===== STRMAPI / STRITERI =====\n");

	str = ft_strmapi("abc",test_upper);
	printf("strmapi: %s\n", str);
	free(str);


	str = ft_strdup("abc");
	ft_striteri(str, add_x);
	printf("striteri: %s\n", str);
	free(str);


	printf("\n===== FD TEST =====\n");

	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);

	ft_putstr_fd("Hello", 1);
	ft_putchar_fd('\n', 1);

	ft_putendl_fd("World", 1);

	ft_putnbr_fd(-123, 1);
	ft_putchar_fd('\n', 1);


	printf("\n===== LINKED LIST =====\n");

	head = NULL;

	node = ft_lstnew(ft_strdup("a"));
	ft_lstadd_back(&head, node);

	node = ft_lstnew(ft_strdup("b"));
	ft_lstadd_back(&head, node);

	node = ft_lstnew(ft_strdup("c"));
	ft_lstadd_back(&head, node);


	printf("List size: %d\n", ft_lstsize(head));

	printf("Last node: %s\n",
		(char *)ft_lstlast(head)->content);


	printf("Iter:\n");
	ft_lstiter(head, print_content);


	printf("After iter:\n");
	ft_lstiter(head, print_content);


	printf("Map:\n");

	mapped = ft_lstmap(head, map_upper, del);

	ft_lstiter(mapped, print_content);


	ft_lstclear(&head, del);
	ft_lstclear(&mapped, del);


	printf("\nALL TESTS DONE\n");

	return (0);
}
