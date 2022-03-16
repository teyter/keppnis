#include<algorithm>
int m(int*a,int*b,int n){
 std::sort(a,a+n);
 std::sort(b,b+n);
 int r=0;
 while(--n>=0)
  r+=a[n]*(*b++);
return r;
}

int main(){
    int* a = {1,3,-5};
    int* b = {-2,4,1};
}
