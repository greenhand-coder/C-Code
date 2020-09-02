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
        color=BLACK; //默认结点颜色为黑
        p = NULL;
        left = NULL;
        right = NULL;
    }
}*RBTree;

RBTree Nul;//空的哨兵结点
RBTree  root; //根结点

//左旋
//x表示要被左旋的节点
//旋转以后x的右孩子y取代了x,而x成为y的左孩子,y的左孩子成为x的右孩子

void LeftRotate(RBTree x)
{
    RBTree y=x->right; //y表示x的右孩子
    //先处理y的左子---------------------------------
    x->right=y->left;
    if(y->left!=Nul) { y->left->p=x;}//y左子变为x右子
    //再处理y------------------------------------
    y->p=x->p;  //更改y的父结点为x的父结点
    if(x->p==Nul) root=y; //x原来是根结点,则设y为根结点
    else if(x==x->p->left) x->p->left=y;   //更改y为x父结点的左孩子
    else x->p->right=y; //更改y为x父结点的右孩子
    //最后处理x------------------------------------
    y->left=x; x->p=y; //将x设为y的左孩子
}

//右旋
//x表示要被右旋的节点
//旋转以后x被左孩子y替换,x成为y的右儿子,y的右孩子成为x的左孩子
void RightRotate(RBTree x)
{
    RBTree y=x->left; //y表示x的左孩子
    //先处理y右子-----------------------------------
    x->left=y->right;
    if(y->right!=Nul) {y->right->p=x;} //y的右子变为x左子
    //再处理y---------------------------------------
    y->p=x->p;                              //更改y的父结点为x的父结点
    if(x->p==Nul) root=y;                   //x原来为根结点,指定y为新根结点
    else if(x==x->p->left) x->p->left=y;    //更改x父结点的左孩子为y
    else x->p->right=y;                     //更改x父结点的右孩子为y
    //处理x-------------------------------------------
    y->right=x;x->p=y;                      //更改y的右结点为x
}

//红黑树插入调整函数
//插入的调整实质上就是根据性质4进行的调整
void RBInsertFixUp(RBTree z)
{
    //这里我们默认插入的节点是红色的
    while(z->p->color==RED) //性质4被违反
    {   //+++++++++++++++++++++情况2.4+++++++++++++++++++++++++//
        //下面的过程按x->p是其祖父结点的左孩子还是右儿子进行分类讨论
        if(z->p==z->p->p->left) //父结点是其祖父结点的左孩子
        {
            RBTree y=z->p->p->right;  //y表示z的叔父结点
            //下面按y的颜色进行分类讨论

            //+++++++++++++++++++情况2.4.1+++++++++++++++++++//

            if(y->color==RED)
            {//如果y是红色z的祖父结点一定是黑色的,
                z->p->color=BLACK;y->color=BLACK;     //1.将父节点，叔父节点设为黑
                z->p->p->color=RED;                   //2.将祖父节点变红
                z=z->p->p;                            //3.将祖父节点设为当前节点
            }

            //++++++++++++++++++情况2.4.2+++++++++++++++++++++//

            else   //叔结点为黑色
            {
                //+++++++++++++++++++++情况2.4.2.2+++++++++++++++++//
                if(z==z->p->right)   //插入节点是父节点右子
                {
                    z=z->p;           //1.将父节点设为当前节点
                    LeftRotate(z);    //左旋父节点，原插入节点成为新的父节点
                }

                z->p->color=BLACK;     //2.将新父节点（原插入节点）变为黑色
                z->p->p->color=RED;    //3.将祖父节点改为红色
                RightRotate(z->p->p);  //4.将祖父节点右旋
            }
        }

        else//父结点是祖父结点的右孩子
        {
            //+++++++++++++++++++++++++情况2.4.3++++++++++++++++//
            RBTree y=z->p->p->left;  //叔结点为祖父节点左子
            if(y->color==RED)
            {

                z->p->color=BLACK;
                y->color=BLACK;
                z->p->p->color=RED;
                z=z->p->p;
            }
            else
            {
                //+++++++++++++++++情况2.4.3.2++++++++++++++++++//
                if(z==z->p->left)
                {
                    z=z->p;
                    RightRotate(z);
                }
                z->p->color=BLACK;    //1.将父节点改为黑色
                z->p->p->color=RED;   //2.将祖父节点改为红色
                LeftRotate(z->p->p);  //3.左旋祖父节点
            }
        }
    }
    //将根节点染成黑色，防止以上情况让根节点变红

    root->color=BLACK;
}

//红黑树的插入,与二叉搜索树无异，只是最后要调整树

void RBInsert(int key)
{
    RBTree z=new node;
    z->color=RED;
    z->key=key;
    z->p=z->left=z->right=Nul;
    RBTree y=Nul;
    RBTree x=root;
    while(x!=Nul) //按照二叉搜索树的性质寻找z的插入点
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
    else y->right=z;  //插入节点
    RBInsertFixUp(z); //调整插入节点
}

//红黑树替换函数,为删除后的替换做准备
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

//查找后继节点，为红黑树的删除做准备
RBTree RBTreeMinMuM(RBTree x)
{
    if(x->left==Nul)
        return x;
    return RBTreeMinMuM(x->left);
}

//红黑树删除调整函数
void RBDeleteFixUp(RBTree x)  //x是替换节点
{
    while(x!=root&&x->color==BLACK)  //x是红色直接替换，不用调整
    {
        //++++++++++++++++++情况3.2++++++++++++++++++++++++++++//
        if(x==x->p->left)
        {
            RBTree w=x->p->right; //w是替换节点兄弟结点
            //+++++++++++++++++++++++++情况3.2.1++++++++++++++++++++++++++++++//
            if(w->color==RED)
            {
                w->color=BLACK;          //1.兄弟节点变为黑色
                x->p->color=RED;         //父节点变为红色
                LeftRotate(x->p);        //2.左旋父节点
                w=x->p->right;
            }
            //++++++++++++++++++++++++情况3.2.2.3++++++++++++++++++++++++++++//
            if(w->left->color==BLACK&&w->right->color==BLACK)
            {
                w->color=RED;            //1.将兄弟节点变红
                x=x->p;                  //2.将父节点变为新的替代节点（只是看做，不删除）
            }
            else
            {
                //++++++++++++++++++++++情况3.2.2.2+++++++++++++++++++++++++//
                if(w->right->color==BLACK)
                {
                    w->color=RED;                 //1.将兄弟节点颜色变成红
                    w->left->color=BLACK;         //2.将兄弟节点左孩子变成黑色
                    RightRotate(w);               //3.右旋兄弟节点，得到情况3.2.2.1
                    w=x->p->right;
                }
                //+++++++++++++++++++++++情况3.2.2.1++++++++++++++++++++++++//
                w->color=w->p->color;               //1.将兄弟节点变成父节点的颜色
                w->p->color=BLACK;                  //2.将父节点变黑
                w->right->color=BLACK;              //3.将兄弟节点的右子节点变黑
                LeftRotate(x->p);                   //4.左旋父节点
                break;
            }
        }
        else
        {
            //+++++++++++++++++++++++++情况3.3，为3.2情况镜像++++++++++++++++++++++++++++//
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

//红黑树删除函数类似于二叉搜索树删除函数,但删除后需要调整替代节点
void RBDelete(RBTree &z)
{ //y指向树中会被删除的结点或是会被替代的结点
  //x指向要替代z或y的结点

    RBTree x=Nul;
    RBTree y=z;
    int ycolor=y->color; //记录y原来的颜色
    if(z->left==Nul) //删除节点只有右子
    {
        x=z->right;
        RBTransplant(z, z->right);// z的右子替代z
    }
    else if(z->right==Nul) //删除节点只有左子
    {
        x=z->left;
        RBTransplant(z, z->left);  //z的左子替代z
    }
    else  //左右儿子都有
    {
        y=RBTreeMinMuM(z->right); //先找z的右子，再查找z的后继节点y
        ycolor=y->color;
        x=y->right;
        if(y->p==z) //y是z的孩子结点
        {
            x->p=y;//这种情况下,y为x的父结点

            RBTransplant(z,y); //y取代z
            y->left=z->left; //z的左孩子改变指向
            y->left->p=y;
            y->color=z->color; //更改y的颜色,这样的话从y以上红黑树的性质都不会违反
        }
        else //y不是z的孩子结点的情况
        {
            RBTransplant(z, y); //y取代z
            y->left=z->left; //z的左孩子改变指向
            y->left->p=y;
            y->color=z->color; //更改y的颜色,这样的话从y以上红黑树的性质都不会违反
            y->right=z->right;
            y->right->p=y;
            RBTransplant(y, y->right);
        }
    }
    //如果y原来的颜色是黑色,那么就意味着有一个黑色结点被覆盖了,红黑树性质被破坏
    if(ycolor==BLACK)
    {
        RBDeleteFixUp(x);
    }
}

//红黑树的中序遍历
void RBInoderSearch(RBTree x)
{
    if(x==Nul)
        return ;
    RBInoderSearch(x->left);
    printf("%d",x->key);
    if(x->color==0) printf("（黑） ");
    else printf("（红） ");
    RBInoderSearch(x->right);
}

//通过关键字搜索对应结点
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
        cout<<"插入 "<<a[i]<<"后的树：";
        RBInoderSearch(root);
        cout<<endl;
    }

    for(int i=0;i<10;i++)
    {
        RBTree x=searchByKey(root,a[i]);
        RBDelete(x);
        cout<<"删除 "<<a[i]<<"后的树: "<<endl;
        RBInoderSearch(root);
        cout<<endl;
    }
    return 0;
}
