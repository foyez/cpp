// #include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "argo.h"

int parser(json *dst, FILE *stream);
void free_items(pair *items, size_t size);

int ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

char *ft_strdup(char *src)
{
	int len = ft_strlen(src);
	char *s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return NULL;
	s[len] = '\0';
	while (len >= 0)
	{
		s[len] = src[len];
		len--;
	}
	return s;
}

int peek(FILE *stream)
{
	int c = getc(stream);
	if (c != EOF)
		ungetc(c, stream);
	return c;
}

void unexpected(FILE *stream)
{
	int c = peek(stream);
	if (c != EOF)
		printf("unexpected token '%c'\n", c);
	else
		printf("unexpected end of input\n");
}

int accept(FILE *stream, char c)
{
	if (peek(stream) == c)
	{
		(void)getc(stream);
		return 1;
	}
	return 0;
}

int expect(FILE *stream, char c)
{
	if (accept(stream, c))
		return 1;
	unexpected(stream);
	return 0;
}

int parse_int(json *dst, FILE *stream)
{
	int n;

	if (fscanf(stream, "%d", &n) == 1)
	{
		dst->type = INTEGER;
		dst->integer = n;
		return 1;
	}
	unexpected(stream);
	return -1;
}

int parse_str(json *dst, FILE *stream)
{
	char buf[4096];
	char c;
	int i = 0;
	if (!expect(stream, '"'))
		return -1;
	while (1)
	{
		c = getc(stream);
		if (c == EOF)
		{
			unexpected(stream);
			return -1;
		}
		if (c == '"') // closing quote
			break;
		if (c == '\\')
		{
			c = getc(stream);
			if (c == EOF)
			{
				unexpected(stream);
				return -1;
			}
			if (c != '\\' && c != '"')
			{
				unexpected(stream);
				return -1;
			}
		}
		buf[i++] = c;

		if (i >= sizeof(buf) - 1)
		{
			unexpected(stream);
			return -1;
		}
	}
	buf[i] = '\0';

	dst->type = STRING;
	dst->string = ft_strdup(buf);
	if (!dst->string)
		return -1;
	return 1;
}

void free_json(json data)
{
	if (data.type == MAP)
	{
		free_items(data.map.data, data.map.size);
	}
	else if (data.type == STRING)
		free(data.string);
}

void free_items(pair *items, size_t size)
{
	int i = -1;

	while (++i < size)
	{
		free(items[i].key);
		free_json(items[i].value);
	}
	free(items);
}

int parse_map(json *dst, FILE *stream)
{
	pair *items = NULL;
	size_t size = 0;
	json key_json;

	if (!expect(stream, '{'))
		return -1;
	// empty obj
	if (accept(stream, '}'))
	{
		dst->type = MAP;
		dst->map.data = NULL;
		dst->map.size = 0;
		return 1;
	}

	while (1)
	{
		items = realloc(items, sizeof(pair) * (size + 1));
		if (!items)
			return -1;
		// parse key
		if (parse_str(&key_json, stream) == -1)
		{
			free_items(items, size);
			return -1;
		}
		if (!expect(stream, ':'))
		{
			free(key_json.string);
			free_items(items, size);
			return -1;
		}
		if (parser(&items[size].value, stream) == -1)
		{
			free(key_json.string);
			free_items(items, size);
			return -1;
		}
		items[size].key = key_json.string;
		size++;

		// check for more elements
		if (accept(stream, ','))
			continue;
		else if (peek(stream) == '}')
			break;
		else
		{
			unexpected(stream);
			free_items(items, size);
			return -1;
		}
	}
	// consume closing brace
	if (!expect(stream, '}'))
	{
		free_items(items, size);
		return -1;
	}

	dst->type = MAP;
	dst->map.data = items;
	dst->map.size = size;

	return 1;
}

int parser(json *dst, FILE *stream)
{
	int c = peek(stream);
	if (c == '"')
		return parse_str(dst, stream);
	if (isdigit(c) || c == '-')
		return parse_int(dst, stream);
	if (c == '{')
		return parse_map(dst, stream);
	unexpected(stream);
	return -1;
}

int argo(json *dst, FILE *stream)
{
	if (!dst || !stream)
		return -1;

	if (parser(dst, stream) != 1) return -1;

    int c = getc(stream);
    if (c != EOF) {
        // free the parsed AST and report the extra token
        free_json(*dst);
        printf("unexpected token '%c'\n", (c == EOF ? '?' : (char)c));
        return -1;
    }
    return 1;
}

void to_json(json data)
{
	if (data.type == INTEGER)
		printf("%d", data.integer);
	else if (data.type == STRING)
	{
		printf("\"");
		int i = -1;
		while (data.string[++i])
		{
			if (data.string[i] == '\\' || data.string[i] == '"')
				printf("\\");
			printf("%c", data.string[i]);
		}
		printf("\"");
	}
	else if (data.type == MAP)
	{
		printf("{");
		int i = -1;
		while (++i < data.map.size)
		{
			if (i != 0)
				printf(",");
			json key_json;
			key_json.type = STRING;
			key_json.string = data.map.data[i].key;
			to_json(key_json);
			printf(":");
			to_json(data.map.data[i].value);
		}
		printf("}");
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char *filename = argv[1];
	FILE *stream = fopen(filename, "r");
	if (!stream)
		return 1;
	json data;
	if (argo(&data, stream) != 1)
	{
		free_json(data);
		fclose(stream);
		return 1;
	}
	to_json(data);
	printf("\n");
	fclose(stream);
	return 0;
}
