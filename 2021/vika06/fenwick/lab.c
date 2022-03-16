#include <stdio.h>
int main()
{
    int n,q;
    scanf("%d %d\n",&n,&q);
    char op;
    int left,right;
    printf("%d %d\n",n,q);
    for (int i = 0; i < q; i++)
    {
        scanf("%c",&op);
        printf("%c ",op);
        if (op == '?')
        {
            scanf("%d\n",&left);
            printf("%d\n",left);
        }
        else if (op == '+')
        {
            scanf("%d %d\n",&left,&right);
            printf("%d %d\n",left,right);
        }
    }
}
