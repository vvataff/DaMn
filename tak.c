#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define maxlen 200

#define OS_TYPE windows
#ifdef OS_TYPE
    #define CLS system("cls")
#else
    #define CLS system("clear")
#endif


void new_gets(char *s, int lim);

int *translation (char *s1, int n);

int max(int n1, int n2);

int min(int n1, int n2);

int *adjustA1(int n1, int *A1, int n2, int *A2);

int *adjustA2(int n1, int *A1, int n2, int *A2);

int COM_NN_D(int n1, int *A1, int n2, int *A2);

int *ADD_NN_N(int n1, int *A1, int n2, int *A2);

int NZER_N_B(int n1, int *A1);

int *ADD_1N_N(int n1, int *A1);

int *SUB_NN_N(int n1, int *A1, int n2, int *A2);

int main()
{
    int *A1=NULL, *A2=NULL, *C=NULL;
    int n1, n2;
    int variant;
    int rez;
    int i;
    int k;
    char *s1=NULL;
                do
                {
                printf("1 - comparing\n");
                printf("2 - is it 0?\n");
                printf("3 - + 1 to whatever you enter\n");
                printf("4 - sum\n");
                printf("5 - raznost\n");
                printf("0 - back to the menu\n");
                printf("Your choice:\n>");
                scanf("%d",&variant);
                getchar();
                switch (variant)
                {
                    case 1:
                        s1=(char*)malloc(maxlen*sizeof(char));
                        printf("Enter your first number: ");
                        new_gets(s1,maxlen);
                        n1=strlen(s1);
                        A1=(int*)malloc(n1*sizeof(int));
                        A1=translation(s1, n1);
                        for (i=0; i<n1; i++)
                        {
                            printf("%d ", A1[i]);
                        }
                        printf("\n");
                        printf("Enter your second number: ");
                        new_gets(s1,maxlen);
                        n2=strlen(s1);
                        A2=(int*)malloc(n2*sizeof(int));
                        A2=translation(s1, n2);
                        for (i=0; i<n2; i++)
                        {
                            printf("%d ", A2[i]);
                        }
                        printf("\n");
                        rez=COM_NN_D(n1, A1, n2, A2);
                        printf("The result of comparing A1 and A2 = %d\n", rez);
                        printf("Press enter to continue exploring...\n");
                        getchar();
                        break;
                    case 2:
                        s1=(char*)malloc(maxlen*sizeof(char));
                        printf("Enter your number: ");
                        new_gets(s1,maxlen);
                        n1=strlen(s1);
                        A1=(int*)malloc(n1*sizeof(int));
                        A1=translation(s1, n1);
                        rez=NZER_N_B(n1, A1);
                        if(rez==0) printf("This is 0\n");
                        else printf("This is not 0\n");
                        printf("Press enter to continue exploring...\n");
                        getchar();
                        break;
                    case 3:
                        s1=(char*)malloc(maxlen*sizeof(char));
                        printf("Enter your first number: ");
                        new_gets(s1,maxlen);
                        n1=strlen(s1);
                        A1=(int*)malloc(n1*sizeof(int));
                        A1=translation(s1, n1);
                        k=n1;
                        C=(int*)malloc(k*sizeof(int));
                        C=ADD_1N_N(n1, A1);
                        printf("Press enter to continue exploring...\n");
                        getchar();
                        break;
                    case 4:
                        s1=(char*)malloc(maxlen*sizeof(char));
                        printf("Enter your first number: ");
                        new_gets(s1,maxlen);
                        n1=strlen(s1);
                        A1=(int*)malloc(n1*sizeof(int));
                        A1=translation(s1, n1);
                        printf("Enter your second number: ");
                        new_gets(s1,maxlen);
                        n2=strlen(s1);
                        A2=(int*)malloc(n2*sizeof(int));
                        A2=translation(s1, n2);
                        k=max(n1,n2);
                        C=(int*)malloc((k+1)*sizeof(int));
                        C=ADD_NN_N(n1, A1, n2, A2);
                        printf("Press enter to continue exploring...\n");
                        getchar();
                        break;
                    case 5:
                        s1=(char*)malloc(maxlen*sizeof(char));
                        printf("Enter your first number: ");
                        new_gets(s1,maxlen);
                        n1=strlen(s1);
                        A1=(int*)malloc(n1*sizeof(int));
                        A1=translation(s1, n1);
                        printf("Enter your second number: ");
                        new_gets(s1,maxlen);
                        n2=strlen(s1);
                        A2=(int*)malloc(n2*sizeof(int));
                        A2=translation(s1, n2);
                        k=max(n1,n2);
                        C=(int*)malloc(k*sizeof(int));
                        C=SUB_NN_N(n1, A1, n2, A2);
                        printf("Press enter to continue exploring...\n");
                        getchar();
                        break;
                }
                CLS;
                }while(variant!=0);
    printf("Goodbye...\n");
    return 0;
}



void new_gets(char *s, int lim)
{
    char c;
    int i;
    i=0;
    while(((c=getchar())!='\n')&&(i<lim-1))
    {
        s[i]=c;
        i++;
    }
    s[i]='\0';
}

int *translation (char *s1, int n)
{
    int i;
    int *A;
    char *s0=NULL;
    A=(int*)malloc(n*sizeof(int));
    s0=(char*)malloc(2*sizeof(char));
    for (i=0;i<n;i++)
    {
        s0[0]=s1[i];
        s0[1]='\0';
        A[i]=atoi(s0);
    }
    free(s0);
    s0=NULL;
    return A;
}



int max(int n1, int n2)
{
    if(n1>n2) return n1;
    else if (n2>n1) return n2;
    else return n2;
}


int min(int n1, int n2)
{
    if(n1>n2) return n2;
    else if (n2>n1) return n1;
    else return n2;
}



int *adjustA1(int n1, int *A1, int n2, int *A2)
{
    int i;
    int *B1=NULL;
    if (n1>n2)
    {
        B1=(int*)malloc(n1*sizeof(int));
        for(i=0;i<n1;i++)
        {
            B1[i]=A1[i];
        }
    }
    else if (n2>n1)
    {
        B1=(int*)malloc(n2*sizeof(int));
        for(i=0;i<n2-n1;i++)
        {
            B1[i]=0;
        }
        for(i=0;i<n2;i++)
        {
            B1[(n2-n1)+i]=A1[i];
        }
    }
    else
    {
        B1=A1;
    }

    return B1;
}

int *adjustA2(int n1, int *A1, int n2, int *A2)
{
    int i;
    int *B2=NULL;
    if (n1>n2)
    {
        B2=(int*)malloc(n1*sizeof(int));
        for(i=0;i<n1-n2;i++)
        {
            B2[i]=0;
        }
        for(i=0;i<n1;i++)
        {
            B2[(n1-n2)+i]=A2[i];
        }
    }
    else if (n2>n1)
    {
        B2=(int*)malloc(n2*sizeof(int));
        for(i=0;i<n2;i++)
        {
            B2[i]=A2[i];
        }
    }
    else
    {
        B2=A2;
    }

    return B2;
}





int COM_NN_D(int n1, int *A1, int n2, int *A2)
{
    int i, k, m, stop, rez;
    int *B1=NULL, *B2=NULL;
    stop=0;
    rez=-1;

    k=max(n1,n2);
    m=min(n1,n2);

    B1=(int*)malloc(k*sizeof(int));
    B1=adjustA1(n1, A1, n2, A2);
    B2=(int*)malloc(k*sizeof(int));
    B2=adjustA2(n1, A1, n2, A2);

    i=0;
    while((stop==0)&&(i!=m))
    {
        if(B1[i]>B2[i])
        {
            rez=2;
            stop=1;
        }
        else if(B1[i]<B2[i])
        {
            rez=1;
            stop=1;
        }
        else i=i+1;
    }
    if (i==m) rez=0;
    return rez;
    free(B1);
    B1=NULL;
    free(B2);
    B2=NULL;
}



int *ADD_NN_N(int n1, int *A1, int n2, int *A2)
{
    int i, j, k, z, srav1, srav2;
    int *B1=NULL, *B2=NULL;
    int *C=NULL;
    int *D=NULL;
    int kol;
    srav1=-1;
    srav2=-1;
    srav1=NZER_N_B(n1, A1);
    srav2=NZER_N_B(n2, A2);
    if (srav1==0)
    {
        D=(int*)malloc(n2*sizeof(int));
        D=A2;
        kol=n2-1;
    }
    else if (srav2==0)
    {
        D=(int*)malloc(n1*sizeof(int));
        D=A1;
        kol=n1-1;
    }
    else if ((srav1==1)&&(srav2==1))
    {
        k=max(n1,n2);
        B1=(int*)malloc(k*sizeof(int));
        B1=adjustA1(n1, A1, n2, A2);
        B2=(int*)malloc(k*sizeof(int));
        B2=adjustA2(n1, A1, n2, A2);
        C=(int*)malloc((k+1)*sizeof(int));
        z=0;
        C[k]=(B1[k-1]+B2[k-1])%10;
        z=(B1[k-1]+B2[k-1])/10;
        for (j=k-1,i=k-2;j>0;j--,i--)
        {
            C[j]=(B1[i]+B2[i]+z)%10;
            z=(B1[i]+B2[i])/10;
        }
        C[0]=z;
        i=0;
        kol=0;
        k=max(n1,n2);
        while(C[i]==0)
        {
            i=i+1;
        }
        kol=k-i;
        D=(int*)malloc(kol*sizeof(int));
        for(i=i, j=0; j<=kol; i++, j++)
        {
            D[j]=C[i];
        }
    }

    printf("Sum of A1 and A2:\n");
    for (i=0; i<=kol; i++)
        {
            printf("%d ", D[i]);
        }
    printf("\n");
    return D;
}









int NZER_N_B(int n1, int *A1)
{
    int k,rez,i;
    k=1;
    rez=-1;
    for(i=0;i<n1;i++)
    {
        if(A1[i]!=0) k=0;
    }
    if (k==0) rez=1;
    else rez=0;
    return rez;
}


int *ADD_1N_N(int n1, int *A1)
{
    int k,j,z,i;
    int *C=NULL;
    int *D=NULL;
    int kol;
    k=n1;
    z=0;
    C=(int*)malloc((k+1)*sizeof(int));
    C[k-1]=(A1[n1-1]+1)%10;
    z=(A1[n1-1]+1)/10;
    for (j=k-2;j>=0;j--)
    {
        C[j]=(A1[j]+z)%10;
        z=(A1[j]+z)/10;
    }
    C[0]=C[0]+z;

    i=0;
    kol=0;
    k=n1+1;
    while(C[i]==0)
    {
        i=i+1;
    }
    kol=k-i;
    D=(int*)malloc(kol*sizeof(int));
    for(i=i, j=0; j<kol; i++, j++)
    {
        D[j]=C[i];
    }
    printf("Result:\n");
    for (i=0; i<kol; i++)
    {
        printf("%d ", D[i]);
    }
    printf("\n");
    return D;
}


int *SUB_NN_N(int n1, int *A1, int n2, int *A2)
{
    int i,j,k,srav1,srav2,srav3;
    int *B1=NULL, *B2=NULL;
    int *C=NULL;
    int *D=NULL;
    int kol;
    srav1=-1;
    srav2=-1;
    srav3=-1;
    srav1=NZER_N_B(n1, A1);
    srav2=NZER_N_B(n2, A2);
    if (srav1==0)
    {
        D=(int*)malloc(n2*sizeof(int));
        D=A2;
    }
    else if (srav2==0)
    {
        D=(int*)malloc(n1*sizeof(int));
        D=A1;
    }
    else if ((srav1==1)&&(srav2==1))
    {
        srav3=COM_NN_D(n1, A1, n2, A2);
        if(srav3==0)
        {
            D=(int*)malloc(1*sizeof(int));
            D[0]=0;
        }
        else
        {
            k=max(n1,n2);

            B1=(int*)malloc(k*sizeof(int));
            B1=adjustA1(n1, A1, n2, A2);
            B2=(int*)malloc(k*sizeof(int));
            B2=adjustA2(n1, A1, n2, A2);


            C=(int*)malloc(k*sizeof(int));

            for (i=k-1;i>=0;i--)
            {
                if(B1[i]>=B2[i]) C[i]=B1[i]-B2[i];
                else
                {
                    B1[i]=B1[i]+10;
                    B1[i-1]=B1[i-1]-1;
                    C[i]=B1[i]-B2[i];
                }

            }

            i=0;
            kol=0;
            k=max(n1,n2);
            while(C[i]==0)
            {
                i=i+1;
            }
            kol=k-i;
            D=(int*)malloc(kol*sizeof(int));
            for(i=i, j=0; j<kol; i++, j++)
            {
                D[j]=C[i];
                printf("D[%d]=%d\n",j, D[j]);
            }
        }

    }

    printf("Raznost of A1 and A2:\n");
    for (i=0; i<kol; i++)
        {
            printf("%d ", D[i]);
        }
    printf("\n");
    return D;
}
