#include "libft.h"
#include <stdio.h>

int main(void)
{
	printf("\n=== isalpha ===\n");
	printf("ft_isalpha('A'): %d\n", ft_isalpha('A'));
	printf("ft_isalpha('1'): %d\n", ft_isalpha('1'));
	printf("%d\n", __LINE__);

	int result = ft_isalpha('a');
	if (result == false)
		printf("ft_isalpha is wrong @ line:%d\n", __LINE__);

	printf("\n=== isdigit ===\n");
	printf("ft_isdigit('5'): %d\n", ft_isdigit('5'));
	printf("ft_isdigit('a'): %d\n", ft_isdigit('a'));
	printf("%d\n", __LINE__);

	printf("\n=== isalnum ===\n");
	printf("ft_isalnum('A'): %d\n", ft_isalnum('A'));
	printf("ft_isalnum('@'): %d\n", ft_isalnum('@'));
	printf("%d\n", __LINE__);

	printf("\n=== isascii ===\n");
	printf("ft_isascii(127): %d\n", ft_isascii(127));
	printf("ft_isascii(200): %d\n", ft_isascii(200));
	printf("%d\n", __LINE__);

	printf("\n=== isprint ===\n");
	printf("ft_isprint('A'): %d\n", ft_isprint('A'));
	printf("ft_isprint('\\n'): %d\n", ft_isprint('\n'));
	printf("%d\n", __LINE__);


	printf("\n=== strlen ===\n");
	printf("%zu\n", ft_strlen("Hello"));
	printf("%d\n", __LINE__);



	printf("\n=== memset ===\n");
	char a[10];
	ft_memset(a, 'A', 5);
	a[5] = '\0';
	printf("%s\n", a);
	printf("%d\n", __LINE__);


	printf("\n=== bzero ===\n");
	char b[10] = "Hello";
	ft_bzero(b, 5);
	printf("After bzero: %s\n", b);
	printf("%d\n", __LINE__);



	printf("\n=== memcpy ===\n");
	char src[] = "Hello";
	char dst[10];

	ft_memcpy(dst, src, 6);
	printf("%s\n", dst);

	printf("%d\n", __LINE__);


	printf("\n=== memmove ===\n");
	char move[] = "Hello World   ";

	ft_memmove(move, move + 6, 7);
	printf("%s\n", move);

	printf("%d\n", __LINE__);


	printf("\n=== strlcpy ===\n");
	char copy[10];

	printf("Length: %zu\n",
		ft_strlcpy(copy, "Hello", sizeof(copy)));

	printf("%s\n", copy);
	printf("%d\n", __LINE__);



	printf("\n=== strlcat ===\n");
	char cat[20] = "Hello ";

	printf("Length: %zu\n",
		ft_strlcat(cat, "World", sizeof(cat)));

	printf("%s\n", cat);
	printf("%d\n", __LINE__);



	printf("\n=== toupper ===\n");
	printf("%c\n", ft_toupper('a'));
	printf("%d\n", __LINE__);

	printf("\n=== tolower ===\n");
	printf("%c\n", ft_tolower('A'));
	printf("%d\n", __LINE__);



	printf("\n=== strchr ===\n");
	printf("%s\n", ft_strchr("Hello", 'l'));
	printf("%d\n", __LINE__);

	printf("\n=== strrchr ===\n");
	printf("%s\n", ft_strrchr("Hello", 'l'));
	printf("%d\n", __LINE__);



	printf("\n=== strncmp ===\n");
	printf("%d\n", ft_strncmp("abc", "abd", 3));
	printf("%d\n", __LINE__);



	printf("\n=== memchr ===\n");
	printf("%s\n",
		(char *)ft_memchr("Hello", 'l', 5));
	printf("%d\n", __LINE__);



	printf("\n=== memcmp ===\n");
	printf("%d\n",
		ft_memcmp("abc", "abd", 3));
	printf("%d\n", __LINE__);



	printf("\n=== strnstr ===\n");
	printf("%s\n",
		ft_strnstr("Hello World", "World", 11));
	printf("%d\n", __LINE__);



	printf("\n=== atoi ===\n");
	{
		int result = ft_atoi("  -123");
		if (result != -123)
			printf("wrong atoi: %d\n", __LINE__);
	}
	{
		int result = ft_atoi("  123");
		if (result != 123)
			printf("wrong atoi: %d\n", __LINE__);
	}


	printf("\n=== calloc ===\n");
	{
		char *calloc_test;

		calloc_test = ft_calloc(5, sizeof(char));
		int j = -1;
		while (++j < 5)
		{
			if (calloc_test[j] != 0)
				printf("calloc fail: %d\n",__LINE__); 
		}

		free(calloc_test);
		printf("%d\n", __LINE__);
	}


	printf("\n=== strdup ===\n");
	char *dup;

	dup = ft_strdup("Hello");

	printf("%s\n", dup);

	free(dup);
	printf("%d\n", __LINE__);



	printf("\n=== substr ===\n");
	char *sub;

	sub = ft_substr("Hello World", 6, 5);

	printf("%s\n", sub);

	free(sub);
	printf("%d\n", __LINE__);



	printf("\n=== strjoin ===\n");
	char *join;

	join = ft_strjoin("Hello ", "World");

	printf("%s\n", join);

	free(join);
	printf("%d\n", __LINE__);



	printf("\n=== strtrim ===\n");
	char *trim;

	trim = ft_strtrim("xxxHello xxx", "x");

	printf("%s\n", trim);

	free(trim);
	printf("%d\n", __LINE__);



	printf("\n=== split ===\n");
	char **split;

	split = ft_split("Hello byebye Test", ' ');

	if (ft_memcmp(split[0] , "Hello", 6) != 0)
		printf("wrong split: %d\n", __LINE__);

	if (ft_memcmp(split[1] , "World", 6) != 0)
		printf("wrong split: %d\n", __LINE__);

	if (ft_memcmp(split[2] , "Test", 7) != 0)
		printf("wrong split: %d\n", __LINE__);

	if (split[3] != 0)
		printf("wrong split: %d\n", __LINE__);
	
	int i = 0;
	
	while (split[i])
	{
		free(split[i]);
		i++;
	}

	free(split);
	printf("%d\n", __LINE__);



	printf("\n=== itoa ===\n");
	char *num;

	num = ft_itoa(-12345);

	printf("%c\n", num[0]);
	printf("%c\n", num[1]);
	printf("%c\n", num[2]);
	printf("%c\n", num[3]);
	printf("%c\n", num[4]);
	printf("%c\n", num[5]);
	printf("%c\n", num[6]);
	printf("%s\n", num);

	free(num);
	printf("%d\n", __LINE__);



	return (0);
}
