#include<stdio.h>
int main(void)
{
   FILE* file = fopen("C:\\Users\\jiangyiqing\\Desktop\\dict.dic","rb");
    char a,aa[5];
    short b,bb[5];
    int c,cc[5];
    long d,dd[5];
    long long e,ee[5];
    float g,gg[5];
    double h,hh[5];
    int where;
    long position = 0;
    fread(&a,sizeof(a),1,file);
    fread(&b,sizeof(b),1,file);
    fread(&c,sizeof(c),1,file);
    fread(&d,sizeof(d),1,file);
    fread(&e,sizeof(e),1,file);
    fread(&g,sizeof(g),1,file);
    fread(&h,sizeof(h),1,file);
    fread(aa,sizeof(a),5,file);
    fread(bb,sizeof(b),5,file);
    fread(cc,sizeof(c),5,file);
    fread(dd,sizeof(d),5,file);
    fread(ee,sizeof(e),5,file);
    fread(gg,sizeof(g),5,file);
    fread(hh,sizeof(h),5,file);
    position = ftell(file);
    scanf("%d",&where);
    fseek(file, (where - 1) * position,SEEK_SET);
        fread(&a,sizeof(a),1,file);
        fread(&b,sizeof(b),1,file);
        fread(&c,sizeof(c),1,file);
        fread(&d,sizeof(d),1,file);
        fread(&e,sizeof(e),1,file);
        fread(&g,sizeof(g),1,file);
        fread(&h,sizeof(h),1,file);
        fread(aa,sizeof(a),5,file);
        fread(bb,sizeof(b),5,file);
        fread(cc,sizeof(c),5,file);
        fread(dd,sizeof(d),5,file);
        fread(ee,sizeof(e),5,file);
        fread(gg,sizeof(g),5,file);
        fread(hh,sizeof(h),5,file);
        printf("%c\n",a);
        printf("%d\n",b);
        printf("%d\n",c);
        printf("%ld\n",d);
        printf("%lld\n",e);
        printf("%f\n",g);
        printf("%lf\n",h);
        printf("%s",aa);
        for(int i = 0 ; i < 5 ;i ++){
            printf("%d",bb[i]);
            if(i != 4)
            printf(" ");
            else
            printf("\n");
        }
        for(int l = 0 ; l < 5 ;l ++){
            printf("%d",cc[l]);
            if(l != 4)
            printf(" ");
            else
            printf("\n");
        }
        for(int m = 0 ; m < 5 ;m ++){
            printf("%ld",dd[m]);
            if(m != 4)
            printf(" ");
            else
            printf("\n");
        }
        for(int n = 0 ; n < 5 ;n ++){
            printf("%lld",ee[n]);
            if(n != 4)
            printf(" ");
            else
            printf("\n");
        }
        for(int p = 0 ; p < 5 ;p ++){
            printf("%f",gg[p]);
            if(p != 4)
            printf(" ");
            else
            printf("\n");
        }
        for(int k = 0 ; k < 5 ;k ++){
            printf("%lf",hh[k]);
            if(k != 4)
            printf(" ");
            else
            printf("\n");
        }
        return 0;
}