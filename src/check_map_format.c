//#include "cub3d"
#include <stdio.h>

#define WHITESPACES "\t\n\v\f\r "
/*
int	is_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && is_in_str(WHITESPACES, str[i]))
		i++;
	return (str && !str[i]);
}
*/
int	is_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (str && str[i] == c);
}

int	str_isonly(const char *str, (*f)(void *), void *data)
{
	int	i;

	i = 0;
	while (str && str[i] && f(data, str[i]))
		i++;
	return (str && !str[i]);
}
/*
int	check_map_format(char **strtab)
{
	// empty lines
	// 4 lines : format NO/SO/WE/EA ./path
	// empty lines
	// 2 lines : format F/C 255,255,255
	// empty lines
	// map
}
*/
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%d\n", str_isonly(argv[1], &is_in_str, WHITESPACES));
	}
	return (0);
}