#include "cub3d.h"

t_str	*t_str_new(char *str)
{
	t_str	*new_t_str;

	new_t_str = malloc(sizeof(*new_t_str)); // calloc
	if (new_t_str)
	{
		new_t_str->str = str;
		new_t_str->next = NULL;
	}
	else
		// error handling
	return (new_t_str);
}

void	t_str_addback(t_str **list, t_str *node)
{
	if (list)
	{
		if (*list)
			t_str_addback((*list)->next, node);
		else
			(*list)->next = node;
	}
}

size_t	t_str_listsize(t_str *list)
{
	return (list != NULL + t_str_listsize(list->next));
}

char	**strlist_to_tab(t_str *list)
{
	char	**tab;
	t_str	*head;
	size_t	list_size;
	size_t	i;

	head = list;
	list_size = t_str_listsize(list);
	tab = malloc((list_size + 1) * sizeof(char *)); // calloc
	if (tab)
	{
		i = 0;
		while (i < list_size && list)
		{
			tab[i] = list->str;
			list = list->next;
			i++;
		}
	}
	else
		// error handling
	list = head;
	return (tab);
}

void	strlist_free(t_str *list)
{
	t_str	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}