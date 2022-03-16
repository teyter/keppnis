#include <stdio.h>
int main()
{
    int n,q;
    scanf("%d %d\n",&n,&q);
    char op;
    int left;
    int right;
    for (int i = 0; i < q; i++)
    {
        scanf("%c",&op);
        printf("%c ",op);
        if (op == 's')
        {
            scanf("%d\n",&left);
            printf("%d\n",left);
        }
        else if (op == 't')
        {
            scanf("%d %d\n",&left,&right);
            printf("%d %d\n",left,right);
        }
    }
}
