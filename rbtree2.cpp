#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define RED 1
#define BLACK 0
typedef struct node
{
    int key,color;
    node *p,*left,*right;
    node()
    {
        color=BLACK; //Ĭ�Ͻ����ɫΪ��
        p = NULL;
        left = NULL;
        right = NULL;
    }
}*RBTree;

RBTree Nul;//�յ��ڱ����
RBTree  root; //�����

//����
//x��ʾҪ�������Ľڵ�
//��ת�Ժ�x���Һ���yȡ����x,��x��Ϊy������,y�����ӳ�Ϊx���Һ���

void LeftRotate(RBTree x)
{
    RBTree y=x->right; //y��ʾx���Һ���
    //�ȴ���y������---------------------------------
    x->right=y->left;
    if(y->left!=Nul) { y->left->p=x;}//y���ӱ�Ϊx����
    //�ٴ���y------------------------------------
    y->p=x->p;  //����y�ĸ����Ϊx�ĸ����
    if(x->p==Nul) root=y; //xԭ���Ǹ����,����yΪ�����
    else if(x==x->p->left) x->p->left=y;   //����yΪx����������
    else x->p->right=y; //����yΪx�������Һ���
    //�����x------------------------------------
    y->left=x; x->p=y; //��x��Ϊy������
}

//����
//x��ʾҪ�������Ľڵ�
//��ת�Ժ�x������y�滻,x��Ϊy���Ҷ���,y���Һ��ӳ�Ϊx������
void RightRotate(RBTree x)
{
    RBTree y=x->left; //y��ʾx������
    //�ȴ���y����-----------------------------------
    x->left=y->right;
    if(y->right!=Nul) {y->right->p=x;} //y�����ӱ�Ϊx����
    //�ٴ���y---------------------------------------
    y->p=x->p;                              //����y�ĸ����Ϊx�ĸ����
    if(x->p==Nul) root=y;                   //xԭ��Ϊ�����,ָ��yΪ�¸����
    else if(x==x->p->left) x->p->left=y;    //����x����������Ϊy
    else x->p->right=y;                     //����x�������Һ���Ϊy
    //����x-------------------------------------------
    y->right=x;x->p=y;                      //����y���ҽ��Ϊx
}

//����������������
//����ĵ���ʵ���Ͼ��Ǹ�������4���еĵ���
void RBInsertFixUp(RBTree z)
{
    //��������Ĭ�ϲ���Ľڵ��Ǻ�ɫ��
    while(z->p->color==RED) //����4��Υ��
    {   //+++++++++++++++++++++���2.4+++++++++++++++++++++++++//
        //����Ĺ��̰�x->p�����游�������ӻ����Ҷ��ӽ��з�������
        if(z->p==z->p->p->left) //����������游��������
        {
            RBTree y=z->p->p->right;  //y��ʾz���常���
            //���水y����ɫ���з�������

            //+++++++++++++++++++���2.4.1+++++++++++++++++++//

            if(y->color==RED)
            {//���y�Ǻ�ɫz���游���һ���Ǻ�ɫ��,
                z->p->color=BLACK;y->color=BLACK;     //1.�����ڵ㣬�常�ڵ���Ϊ��
                z->p->p->color=RED;                   //2.���游�ڵ���
                z=z->p->p;                            //3.���游�ڵ���Ϊ��ǰ�ڵ�
            }

            //++++++++++++++++++���2.4.2+++++++++++++++++++++//

            else   //����Ϊ��ɫ
            {
                //+++++++++++++++++++++���2.4.2.2+++++++++++++++++//
                if(z==z->p->right)   //����ڵ��Ǹ��ڵ�����
                {
                    z=z->p;           //1.�����ڵ���Ϊ��ǰ�ڵ�
                    LeftRotate(z);    //�������ڵ㣬ԭ����ڵ��Ϊ�µĸ��ڵ�
                }

                z->p->color=BLACK;     //2.���¸��ڵ㣨ԭ����ڵ㣩��Ϊ��ɫ
                z->p->p->color=RED;    //3.���游�ڵ��Ϊ��ɫ
                RightRotate(z->p->p);  //4.���游�ڵ�����
            }
        }

        else//��������游�����Һ���
        {
            //+++++++++++++++++++++++++���2.4.3++++++++++++++++//
            RBTree y=z->p->p->left;  //����Ϊ�游�ڵ�����
            if(y->color==RED)
            {

                z->p->color=BLACK;
                y->color=BLACK;
                z->p->p->color=RED;
                z=z->p->p;
            }
            else
            {
                //+++++++++++++++++���2.4.3.2++++++++++++++++++//
                if(z==z->p->left)
                {
                    z=z->p;
                    RightRotate(z);
                }
                z->p->color=BLACK;    //1.�����ڵ��Ϊ��ɫ
                z->p->p->color=RED;   //2.���游�ڵ��Ϊ��ɫ
                LeftRotate(z->p->p);  //3.�����游�ڵ�
            }
        }
    }
    //�����ڵ�Ⱦ�ɺ�ɫ����ֹ��������ø��ڵ���

    root->color=BLACK;
}

//������Ĳ���,��������������죬ֻ�����Ҫ������

void RBInsert(int key)
{
    RBTree z=new node;
    z->color=RED;
    z->key=key;
    z->p=z->left=z->right=Nul;
    RBTree y=Nul;
    RBTree x=root;
    while(x!=Nul) //���ն���������������Ѱ��z�Ĳ����
    {
        y=x;
        if(z->key<x->key)
            x=x->left;
        else
            x=x->right;
    }
    z->p=y;
    if(y==Nul) root=z;
    else if(z->key<y->key) y->left=z;
    else y->right=z;  //����ڵ�
    RBInsertFixUp(z); //��������ڵ�
}

//������滻����,Ϊɾ������滻��׼��
void RBTransplant(RBTree u,RBTree v)
{
    if(u->p==Nul)
        root=v;
    else if(u==u->p->left)
        u->p->left=v;
    else
        u->p->right=v;
    v->p=u->p;
}

//���Һ�̽ڵ㣬Ϊ�������ɾ����׼��
RBTree RBTreeMinMuM(RBTree x)
{
    if(x->left==Nul)
        return x;
    return RBTreeMinMuM(x->left);
}

//�����ɾ����������
void RBDeleteFixUp(RBTree x)  //x���滻�ڵ�
{
    while(x!=root&&x->color==BLACK)  //x�Ǻ�ɫֱ���滻�����õ���
    {
        //++++++++++++++++++���3.2++++++++++++++++++++++++++++//
        if(x==x->p->left)
        {
            RBTree w=x->p->right; //w���滻�ڵ��ֵܽ��
            //+++++++++++++++++++++++++���3.2.1++++++++++++++++++++++++++++++//
            if(w->color==RED)
            {
                w->color=BLACK;          //1.�ֵܽڵ��Ϊ��ɫ
                x->p->color=RED;         //���ڵ��Ϊ��ɫ
                LeftRotate(x->p);        //2.�������ڵ�
                w=x->p->right;
            }
            //++++++++++++++++++++++++���3.2.2.3++++++++++++++++++++++++++++//
            if(w->left->color==BLACK&&w->right->color==BLACK)
            {
                w->color=RED;            //1.���ֵܽڵ���
                x=x->p;                  //2.�����ڵ��Ϊ�µ�����ڵ㣨ֻ�ǿ�������ɾ����
            }
            else
            {
                //++++++++++++++++++++++���3.2.2.2+++++++++++++++++++++++++//
                if(w->right->color==BLACK)
                {
                    w->color=RED;                 //1.���ֵܽڵ���ɫ��ɺ�
                    w->left->color=BLACK;         //2.���ֵܽڵ����ӱ�ɺ�ɫ
                    RightRotate(w);               //3.�����ֵܽڵ㣬�õ����3.2.2.1
                    w=x->p->right;
                }
                //+++++++++++++++++++++++���3.2.2.1++++++++++++++++++++++++//
                w->color=w->p->color;               //1.���ֵܽڵ��ɸ��ڵ����ɫ
                w->p->color=BLACK;                  //2.�����ڵ���
                w->right->color=BLACK;              //3.���ֵܽڵ�����ӽڵ���
                LeftRotate(x->p);                   //4.�������ڵ�
                break;
            }
        }
        else
        {
            //+++++++++++++++++++++++++���3.3��Ϊ3.2�������++++++++++++++++++++++++++++//
            RBTree w=x->p->left;
            if(w->color==RED)
            {
                w->p->color=RED;
                w->color=BLACK;
                RightRotate(x->p);
                w=x->p->left;
            }
            else if(w->left->color==BLACK&&w->right->color==BLACK)
            {
                w->color=RED;
                x=x->p;
            }
            else
            {
                if(w->left->color==BLACK)
                {
                    w->right->color=BLACK;
                    w->color=RED;
                    LeftRotate(w);
                    w=x->p->left;
                }
                w->color=x->p->color;
                x->p->color=BLACK;
                w->left->color=BLACK;
                RightRotate(x->p);
                break;
            }
        }
    }
    x->color=BLACK;
}

//�����ɾ�����������ڶ���������ɾ������,��ɾ������Ҫ��������ڵ�
void RBDelete(RBTree &z)
{ //yָ�����лᱻɾ���Ľ����ǻᱻ����Ľ��
  //xָ��Ҫ���z��y�Ľ��

    RBTree x=Nul;
    RBTree y=z;
    int ycolor=y->color; //��¼yԭ������ɫ
    if(z->left==Nul) //ɾ���ڵ�ֻ������
    {
        x=z->right;
        RBTransplant(z, z->right);// z���������z
    }
    else if(z->right==Nul) //ɾ���ڵ�ֻ������
    {
        x=z->left;
        RBTransplant(z, z->left);  //z���������z
    }
    else  //���Ҷ��Ӷ���
    {
        y=RBTreeMinMuM(z->right); //����z�����ӣ��ٲ���z�ĺ�̽ڵ�y
        ycolor=y->color;
        x=y->right;
        if(y->p==z) //y��z�ĺ��ӽ��
        {
            x->p=y;//���������,yΪx�ĸ����

            RBTransplant(z,y); //yȡ��z
            y->left=z->left; //z�����Ӹı�ָ��
            y->left->p=y;
            y->color=z->color; //����y����ɫ,�����Ļ���y���Ϻ���������ʶ�����Υ��
        }
        else //y����z�ĺ��ӽ������
        {
            RBTransplant(z, y); //yȡ��z
            y->left=z->left; //z�����Ӹı�ָ��
            y->left->p=y;
            y->color=z->color; //����y����ɫ,�����Ļ���y���Ϻ���������ʶ�����Υ��
            y->right=z->right;
            y->right->p=y;
            RBTransplant(y, y->right);
        }
    }
    //���yԭ������ɫ�Ǻ�ɫ,��ô����ζ����һ����ɫ��㱻������,��������ʱ��ƻ�
    if(ycolor==BLACK)
    {
        RBDeleteFixUp(x);
    }
}

//��������������
void RBInoderSearch(RBTree x)
{
    if(x==Nul)
        return ;
    RBInoderSearch(x->left);
    printf("%d",x->key);
    if(x->color==0) printf("���ڣ� ");
    else printf("���죩 ");
    RBInoderSearch(x->right);
}

//ͨ���ؼ���������Ӧ���
RBTree searchByKey(RBTree x,int k)
{
    if(x->key==k)
        return  x;
    if(k<x->key)
        return searchByKey(x->left,k);
    else
        return searchByKey(x->right,k);
    return NULL;
}

int main()
{
    int a[10];
    for(int i=0;i<10;i++) scanf("%d",&a[i]);
    Nul=new node;
    root=Nul;
    for(int i=0;i<10;i++)
    {
        RBInsert(a[i]);
        cout<<"���� "<<a[i]<<"�������";
        RBInoderSearch(root);
        cout<<endl;
    }

    for(int i=0;i<10;i++)
    {
        RBTree x=searchByKey(root,a[i]);
        RBDelete(x);
        cout<<"ɾ�� "<<a[i]<<"�����: "<<endl;
        RBInoderSearch(root);
        cout<<endl;
    }
    return 0;
}
