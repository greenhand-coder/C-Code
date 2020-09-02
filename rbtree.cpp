#include<stdio.h>
#include<stdlib.h>
typedef int type;
typedef enum Color   //�������������ɫ��ɫ����
{
	red = 0,
	black = 1
}Color;
typedef struct rbtree     //���������Ľṹ
{
	Color color;
	type key;
	struct rbtree *left;
	struct rbtree *right;
	struct rbtree *parent;

}node, *tree;

node *nil = NULL;                        //����һ���ڱ���㡣����Ҫ���ڱ�ȥ�ÿյ�Ҷ�ӽ�����ɫ��black�ģ����պ�����Ķ���

node* create(type key, node *left, node *right, node *parent)                       //�������
{
	node *p;
	p = (node*)malloc(sizeof(node));
	p->color = black;                                                        //Ĭ����ɫΪblack
	p->left = left;
	p->right = right;
	p->parent = parent;
	p->key = key;
	/*	printf("���������");*/
	return p;

}

void left_rotate(tree &t, node *x)                                 //�����������ͼ�������������
{
	node *y = x->right;
	x->right = y->left;
	if (y->left != nil)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == nil)
		t = y;
	else
	{
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->left = x;
	x->parent = y;

}

void right_rotate(tree &t, node *x)                   //����
{
	node *y = x->left;
	x->left = y->right;
	if (y->right != nil)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == nil)
		t = y;                             //
	else
	{
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->right = x;
	x->parent = y;
}


node* search(tree &t, type key)                        //����Ԫ��
{
	node *x = t;
	if (x == nil || x->key == key)
	{

		return t;
	}

	if (key < x->key)
	{

		return search(x->left, key);
	}
	else

	{

		return search(x->right, key);

	}


}                                                                  //�ݹ����

void rb_insert_fixup(tree &t, node* z)
{
	node *y;
	while ((z->parent != nil) && (z->parent->color == red))                                //only when z's parent is red there will probably obey the red node has two black nodes
	{
		if (z->parent == z->parent->parent->left)                //z'parent is the left node
		{

			y = z->parent->parent->right;                         //let y be z's uncle node
			if (y->color == red)                                  //parent and uncle and itself are all red
			{
				z->parent->color = black;
				y->color = black;
				z->parent->parent->color = red;
				z = z->parent->parent;                              //let z up to its grandpa
			}
			else
			{
				if (z == z->parent->right)                         // z is a right node
				{
					z = z->parent;
					left_rotate(t, z);

				}
				z->parent->color = black;
				z->parent->parent->color = red;
				right_rotate(t, z->parent->parent);
			}

		}
		else                                                     //z's parent is the right node
		{
			y = z->parent->parent->left;
			if (y->color == red)
			{

				z->parent->color = black;
				y->color = black;
				z->parent->parent->color = red;
				z = z->parent->parent;
			}

			else
			{
	            if (z == z->parent->left)                         // z is a left node
				{
					z = z->parent;
					right_rotate(t, z);
				}
				z->parent->color = black;
				z->parent->parent->color = red;
				left_rotate(t, z->parent->parent);
			}
		}

	}

	t->color = black;                                   //ʼ�ձ��ָ��ڵ��Ǻ�ɫ
}


node* rb_insert(tree &t, node *z)                        //�������
{
	if (t == NULL)                                                  //t�ǿյ���
	{
		t = (tree)malloc(sizeof(node));
		nil = (node*)malloc(sizeof(node));                       //��ʼ���ڱ����
		nil->color = black;
		t->left = nil;
		t->right = nil;
		t->parent = nil;
		t->key = z->key;
		t->color = black;
	}

	else
	{
		node *y = nil;
		node *x = t;                             //


		while (x != nil)
		{
			y = x;
			if (z->key < x->key)
				x = x->left;
			else
				x = x->right;

		}
		z->parent = y;
		if (y == nil)
			t = z;
		else
		{
			if (z->key < y->key)
				y->left = z;
			else
				y->right = z;
		}
		z->left = nil;
		z->right = nil;
		z->color = red;                                     //ʼ�ձ��ֲ���Ľ���Ǻ�ɫ�������Ͼ�������������fixup����
		rb_insert_fixup(t, z);
	}
	return t;
}
node* rb_insert_(tree &t, type k)
{
	node *z;
	z = create(k, NULL, NULL, NULL);
	return  rb_insert(t, z);
}


node* min(tree &m)                     //��Сֵ
{

	node *n = m;

	if (n == nil)
		return nil;

	while (n->left != nil)
	{
		n = n->left;
	}
	return n;
}

node* successor(node *s)           //���
{
	node *p;
	if (s->right != nil)             //����������ǿ�
	{
		return  min(s->right);
	}
	else
	{
		 p = s->parent;                //��������ӣ���̾������ĸ��ڵ�
		while (p != nil && p->right == s)
		{                                       //������Һ��ӣ����ϲ��ң�ֱ������һ�������ӵĸ��ڵ㣬�Ǿ��Ǻ��
			{
				s = p;
				p = p->parent;
			}
		}
		return p;
	}

}



void rb_delete_fixup(tree &t, node *x)
{
	node *w;
	while (x != t && x->color == black)                      //
	{
		if (x == x->parent->left)
		{
			w = x->parent->right;
			if (w->color == red)
			{
				w->color = black;
				x->parent->color = red;
				left_rotate(t, x->parent);
				w = x->parent->right;
			}
			if (w->left->color == black && w->right->color == black)
			{
				w->color = red;
				x = x->parent;
			}
			else if (w->right->color == black)
			{
				w->left->color = black;
				w->color = red;
				right_rotate(t, w);
				w = x->parent->right;
			}
			w->color = x->parent->color;
			x->parent->color = black;
			w->right->color = black;
			left_rotate(t, x->parent);
			x = t;                                        //

		}
		else
		{
			w = x->parent->left;
			if (w->color = red)
			{
				w->color = black;
				x->parent->color = red;
				right_rotate(t, x->parent);
				w = x->parent->left;
			}
			if (w->left->color == black && w->right->color == black)
			{
				w->color = red;
				x = x->parent;
			}
			else if (w->left->color == black)
			{
				w->right->color = black;
				w->color = red;
				left_rotate(t, w);
				w = x->parent->right;
			}
			w->color = x->parent->color;
			x->parent->color = black;
			w->left->color= black;
			right_rotate(t, x->parent);
			x = t;                                            //

		}
	}
	x->color = black;
}

node* rb_delete(tree &t, node *z)
{
node *y, *x;
    node *m=nil;
	node* n = z;
	if (z->left == nil || z->right == nil)
		y = z;
	else
		y = successor(n);                                  //��һ��ʹz���Һ��ӷ����仯
	if (y->left != nil)
		x = y->left;
	else
		x = y->right;
	x->parent = y->parent;
	if (y->parent == nil)
		t = x;                            //
	else
	{
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	}
	if (y != z)
	{
		z->key = (y->key);

	}
	if (y->color == black)
		rb_delete_fixup(t, x);
	return t;
}

node* rb_delete_(tree &t, type k)
{
	node *z;
	z = search(t, k);

	if (z != nil)
	{
		t = rb_delete(t, z);
	}
	else
		printf("�޴�Ԫ��");
	return t;
}


void print_tree(tree &t)                        //���������ӡ
{
	if (t != nil && t != NULL)
	{
		print_tree(t->left);
		printf("%7d ,   %5d\n ", t->key, t->color);
		print_tree(t->right);
	}
}

int main()
{
	int i;
	tree zz = NULL, mm = NULL, nn = NULL, xx = NULL, yy = NULL;
	type k;
	int a[12] = {3,12,15,17,19,55,20,18,36,48,31,29 };
	printf("\nԭ���������ǣ�----------------------------------------\n");
	for (i = 0; i<12; i++)
	{
		printf("%d  ", a[i]);
		zz = rb_insert_(zz, a[i]);
	}

	printf("\n��������ǣ�-------------------------------------------\n");
	printf("�涨��red=0,black=1\n");
	print_tree(zz);
	printf("\nҪɾ����ֵ�ǣ�---------------------------------------");
	scanf("%d", &k);
	yy = rb_delete_(zz, k);
	print_tree(yy);
	printf("\nҪ�����ֵ�ǣ�--------------------------------------");
	scanf("%d", &k);
	rb_insert_(zz, k);
	print_tree(zz);
}
