#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "argo.h"

int parser(json *out, FILE *s);
void free_json(json *j);

int peek(FILE *stream)
{
	int c = getc(stream);
	if (c != EOF) ungetc(c, stream);
	return c;
}

void unexpected_token(char c)
{
	printf("unexpected token '%c'\n", c);
}

void unexpected_end(void)
{
	printf("unexpected end of input\n");
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
	if (accept(stream, c)) return 1;
	unexpected(stream);
	return 0;
}

int grow_cap(char **buf, size_t *cap, size_t need)
{
	if (need <= *cap) return 1;
	size_t ncap = (*cap ? *cap : 16);
	while (ncap < need)
		ncap *= 2;
	char *nbuf = (char *)realloc(*buf, ncap);
	if (!nbuf) return 0;
	*buf = nbuf;
	*cap = ncap;
	return 1;
}

void free_pairs(pair *items, size_t n)
{
	if (!items) return ;
	int i = -1;
	while (++i < n)
	{
		if (items[i].key) free(items[i].key);
		free_json(&items[i].value);
	}
	free(items);
}

void free_json(json *j)
{
	if (!j) return ;
	if (j->type == STRING) free(j->string);
	else if (j->type == MAP) free_pairs(j->map.data, j->map.size);
}

int parse_str(char **out, FILE *s)
{
	char *buf = NULL;
	size_t len = 0;
	size_t cap = 0;
	int c;

	if (!expect(s, '"')) return -1;
	while (1)
	{
		c = getc(s);
		if (c == EOF)
		{
			free(buf);
			unexpected_end();
			return -1;
		}
		if (c == '"') break; // closing quote
		if (c == '\\')
		{
			c = getc(s);
			if (c == EOF)
			{
				free(buf);
				unexpected_end();
				return -1;
			}
			if (c != '\\' && c != '"')
			{
				free(buf);
				unexpected_token((char)c);
				return -1;
			}
		}
		if (!grow_cap(&buf, &cap, len + 1))
		{
			free(buf);
			return -1;
		}
		buf[len++] = (char)c;
	}

	if (!grow_cap(&buf, &cap, len + 1))
	{
		free(buf);
		return -1;
	}
	buf[len] = '\0';

	*out = buf;
	return 1;
}

int parse_int(json *out, FILE *s)
{
	int n;

	if (fscanf(s, "%d", &n) == 1)
	{
		out->type = INTEGER;
		out->integer = n;
		return 1;
	}
	unexpected(s);
	return -1;
}

int parse_map(json *out, FILE *s)
{
	pair *items = NULL;
	size_t size = 0;

	if (!expect(s, '{')) return -1;

	// empty map
	if (accept(s, '}'))
	{
		out->type = MAP;
		out->map.data = NULL;
		out->map.size = 0;
		return 1;
	}

	while (1)
	{
		items = (pair *)realloc(items, sizeof(pair) * (size + 1));
		if (!items)
			return -1;
		char *key = NULL;
		if (parse_str(&key, s) < 0)
		{
			free_pairs(items, size);
			return -1;
		}

		if (!expect(s, ':'))
		{
			free(key);
			free_pairs(items, size);
			return -1;
		}

		json val;
		if (parser(&val, s) < 0)
		{
			free(key);
			free_pairs(items, size);
			return -1;
		}
		items[size].key = key;
		items[size].value = val;
		size++;

		// separator
		if (accept(s, ','))
			continue;
		else if (accept(s, '}'))
		{
			out->type = MAP;
			out->map.data = items;
			out->map.size = size;
			return 1;
		}
		else
		{
			unexpected(s);
			free_pairs(items, size);
			return -1;
		}
	}
}

int parser(json *out, FILE *s)
{
	int c = peek(s);
	if (c == '"')
	{
		char *str = NULL;
		if (parse_str(&str, s) < 0) return -1;
		out->type = STRING;
		out->string = str;
		return 1;
	}
	if (c == '-' || isdigit((unsigned char)c))
		return parse_int(out, s);
	if (c == '{')
		return parse_map(out, s);
	unexpected(s);
	return -1;
}

int argo(json *dst, FILE *stream)
{
	if (!dst || !stream) return -1;

	if (parser(dst, stream) != 1) return -1;

	int c = getc(stream);
	if (c != EOF)
	{
		free_json(dst);
		unexpected_token((char)c);
		return -1;
	}
	return 1;
}
