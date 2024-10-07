//#include "cub3d"
#include <stdio.h>

#define WHITESPACES "\t\n\v\f\r "

int	is_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (str && str[i] == c);
}

int	str_isonly(const char *str, char *set)
{
	int	i;

	i = 0;
	while (str && str[i] && is_in_str(set, str[i]))
		i++;
	return (str && !str[i]);
}

void	strtab_free(char **strtab)
{
	int	i;

	i = 0;
	while (strtab && strtab[i])
	{
		free(strtab[i]);
		i++;
	}
	if (strtab)
		free(strtab);
}

char	**strtab_init(size_t size, ...)
{
	va_list	p;
	char	**strtab;
	size_t	i;

	strtab = ft_calloc(size, sizeof(char *));
	if (strtab)
	{
		va_start(p, size);
		i = 0;
		while (i < size)
		{
			strtab[i] = ft_strdup(va_arg(p, char *));
			if (!strtab[i])
			{
				strtab_free(strtab);
				break ;
			}
		}
		va_end(p);
	}
	return (strtab);
}

int	nswe_line_format(char *line, char *nswe)
{
	int	i;

	if (!strcmp(line, nswe))
	{
		i = 2;
		while (is_in_str(WHITESPACES, line[i]))
			i++;
		while (ft_isascii(line[i]))
			i++;
		while (is_in_str(WHITESPACES, line[i]))
			i++;
		return (!line[i]);
	}
	return (0);
}

int	nswe_format(char **strtab)	// error handling pour chaque étape ?
{
	char	**nswe;
	int		i;
	int		j;

	nswe = strtab_init(4, "NO", "SO", "WE", "EA");
	if (nswe)
	{
		i = 0;
		while (i < 4 && strtab && strtab[i] && nswe_line_format(strtab[i], nswe[i]))
			i++;
		strtab_free(nswe);
	}
	else
		// error handling malloc
	return (i == 4);
}

int	color_format(char **strtab)
{
	int	i;
	int	j;

	if (strtab && *strtab && strtab[0][0] == 'F'
		&& *(strtab + 1) && strtab[1][0] == 'C')
	{
		i = 0;
		while (i < 2)
		{
			j = 1;
			while (is_in_str(WHITESPACES, strtab[i][j]))
				j++;
			if (ft_strlen_while(&strtab[i][j], ft_isdigit) != 3) //
				break ;
			while (is_in_str(WHITESPACES, strtab[i][j]))
				j++;
			if (strtab[i][j] != ',')
				break ;
		}
	}
}

int	check_map_format(char **strtab)
{
	int	i;

	// empty lines
	i = 0;
	while (strtab && strtab[i] && str_isonly(strtab[i], WHITESPACES))
		i++;
	// 4 lines : format NO/SO/WE/EA ./path
	if (!nswe_format(&strtab[i]))
		// error handling
	i += 4;
	// empty lines
	while (str_isonly(strtab[i], WHITESPACES))
		i++;
	// 2 lines : format F/C 255,255,255
	if (!color_format(&strtab[i]))
		// error handling
	i += 2;
	// empty lines
	// map
}

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc == 2)
	{
	//	printf("%d\n", str_isonly(argv[1], is_in_str, WHITESPACES));
	//	printf("%d\n", str_isonly("\t\n\v\f\r", is_in_str, WHITESPACES));
	}
	return (0);
}