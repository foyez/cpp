#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
	enum { ADD, MULTI, VAL } type;
	int val;
	struct node *l;
	struct node *r;
} node;

node *parse_add(char **s);
node *parse_multi(char **s);

node *new_node(node n) {
	node *p = calloc(1, sizeof(n));
	if (!p)
		return NULL;
	*p = n;
	return p;
}

void destroy_tree(node *n) {
	if (!n) return;
	if (n->type != VAL) {
		destroy_tree(n->l);
		destroy_tree(n->r);
	}
	free(n);
}

void unexpected(char c) {
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of file\n");
}

int accept(char **s, char c) {
	if (**s == c) {
		(*s)++;
		return 1;
	}
	return 0;
}

int expect(char **s, char c) {
	if (accept(s, c))
		return 1;
	unexpected(**s);
	return 0;
}

node *parse_digit_or_group(char **s) {
	node *body;
	node new;

	if (accept(s, '(')) {
		body = parse_add(s);
		if (!body || !expect(s, ')')) {
			destroy_tree(body);
			return NULL;
		}
		return body;
	}
	if (!**s || !isdigit((unsigned char)**s)) {
		unexpected(**s);
		return NULL;
	}

	new.type = VAL;
	new.val = **s - '0';
	new.l = NULL;
	new.r = NULL;

	body = new_node(new);
	if (!body)
		return NULL;
	(*s)++;
	return body;
}

node *parse_multi(char **s) {
	node *left;
	node *right;
	node *parent;
	node new;

	left = parse_digit_or_group(s);
	if (!left)
		return NULL;
	while (accept(s, '*')) {
		right = parse_digit_or_group(s);
		if (!right) {
			destroy_tree(left);
			return NULL;
		}

		new.type = MULTI;
		new.l = left;
		new.r = right;
		new.val = 0;

		parent = new_node(new);
		if (!parent) {
			destroy_tree(left);
			destroy_tree(right);
			return NULL;
		}
		left = parent;
	}
	return left;
}

node *parse_add(char **s) {
	node *left;
	node *right;
	node *parent;
	node new;

	left = parse_multi(s);
	if (!left)
		return NULL;
	while (accept(s, '+')) {
		right = parse_multi(s);
		if (!right) {
			destroy_tree(left);
			return NULL;
		}

		new.type = ADD;
		new.l = left;
		new.r = right;
		new.val = 0;

		parent = new_node(new);
		if (!parent) {
			destroy_tree(left);
			destroy_tree(right);
			return NULL;
		}
		left = parent;
	}
	return left;
}

node *parse_expr(char **s) {
	node *root = parse_add(s);
	if (!root)
		return NULL;
	if (**s) {
		destroy_tree(root);
		unexpected(**s);
		return NULL;
	}
	return root;
}

int eval_tree(node *tree) {
	switch(tree->type) {
		case ADD:
			return (eval_tree(tree->l) + eval_tree(tree->r));
		case MULTI:
			return (eval_tree(tree->l) * eval_tree(tree->r));
		case VAL:
			return tree->val;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	node *tree = parse_expr(&argv[1]);
	if (!tree)
		return 1;
	printf("%d\n", eval_tree(tree));
	destroy_tree(tree);

	return 0;
}
