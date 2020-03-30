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

int *back(int *C, int kol);

int back_length(int *C, int n1, int n2);

int NZER_N_B(int n1, int *A1);

int *ADD_1N_N(int n1, int *A1);

int *SUB_NN_N(int n1, int *A1, int n2, int *A2);

int main()
{
    int *A1, *A2, *C, *D;
    int n1, n2;
    int option, variant;
    int rez;
    int i,j;
    int k;
    int kol;
    char *s1=NULL;
    do
    {
        printf("What do you want to work with?\n");
        printf("0 - exit\n");
        printf("1 - Natural\n");
        printf("2 - Real\n");
        printf("Your choice:\n>");
        scanf("%d",&option);
        getchar();

        switch(option)
        {
            case 0:
                break;
            case 1:
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
                        rez=NZER_N_B(n1, A1);
                        if(rez==0) printf("This is 0\n");
                        else printf("This is not 0\n");
                        getchar();
                        break;
                    case 3:
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

                        k=n1;
                        C=(int*)malloc(k*sizeof(int));
                        C=ADD_1N_N(n1, A1);
                        printf("Result:\n");
                        for (i=0; i<k; i++)
                        {
                            printf("%d ", C[i]);
                        }
                        if(C[0]==0)
                        {
                            D=(int*)malloc(k*sizeof(int));
                            for(i=0,j=1;i<k;i++,j++)
                            {
                                D[i]=C[j];
                            }
                            printf("Result:\n");
                            for (i=0; i<k; i++)
                            {
                                printf("%d ", D[i]);
                            }
                        }
                        getchar();
                        break;
                    case 4:
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
                        k=max(n1,n2);
                        C=(int*)malloc((k+1)*sizeof(int));
                        C=ADD_NN_N(n1, A1, n2, A2);
                        printf("Sum of A1 and A2:\n");
                        for (i=0; i<k+1; i++)
                        {
                            printf("%d ", C[i]);
                        }
                        printf("\n");
                        kol=back_length(C,n1,n2);
                        printf("Kol in main = %d\n");
                        D=(int*)malloc(kol*sizeof(int));
                        D=back(C,kol);
                        printf("Sum of A1 and A2 without zeros:\n");
                        for (i=0; i<kol; i++)
                        {
                            printf("%d ", D[i]);
                        }
                        printf("\n");
                        getchar();
                        break;
                    case 5:
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
                        k=max(n1,n2);
                        C=(int*)malloc(k*sizeof(int));
                        C=SUB_NN_N(n1, A1, n2, A2);
                        printf("Raznost of A1 and A2:\n");
                        for (i=0; i<k; i++)
                        {
                            printf("%d ", C[i]);
                        }
                        printf("\n");
                        kol=back_length(C,n1,n2);
                        D=(int*)malloc((kol)*sizeof(int));
                        D=back(C,kol);
                        printf("Raznost of A1 and A2 without zeros:\n");
                        for (i=0; i<kol; i++)
                        {
                            printf("%d ", D[i]);
                        }
                        printf("\n");
                        getchar();
                        break;
                }
                CLS;
                }while(variant!=0);
                break;
            case 2:
                printf("Nothing so far...\n");
                getchar();
                break;
            default:
                printf("Wrong button!...\n");
                getchar();
                break;
        }
        CLS;
    } while(option!=0);
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
    int i, k;
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
    k=max(n1,n2);

    printf("Adjusted A1:\n");
    for (i=0; i<k; i++)
    {
        printf("%d ", B1[i]);
    }
    printf("\n");

    return B1;
}

int *adjustA2(int n1, int *A1, int n2, int *A2)
{
    int i, k;
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
    k=max(n1,n2);

    printf("Adjusted A2:\n");
    for (i=0; i<k; i++)
    {
        printf("%d ", B2[i]);
    }
    printf("\n");
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
    srav1=-1;
    srav2=-1;
    srav1=NZER_N_B(n1, A1);
    srav2=NZER_N_B(n2, A2);
    if (srav1==0)
    {
        C=(int*)malloc(n2*sizeof(int));
        C=A2;
    }
    else if (srav2==0)
    {
        C=(int*)malloc(n1*sizeof(int));
        C=A1;
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
        printf("k=%d\n",k);
        C[k]=(B1[k-1]+B2[k-1])%10;
        printf("C[%d]=%d\n",k, C[k]);
        z=(B1[k-1]+B2[k-1])/10;
        for (j=k-1,i=k-2;j>0;j--,i--)
        {
            C[j]=(B1[i]+B2[i]+z)%10;
            printf("C[%d]=%d\n",j, C[j]);
            z=(B1[i]+B2[i])/10;
        }
        C[0]=z;
        printf("C[%d]=%d\n",0, C[0]);
        printf ("The size of C in sum=%d", k+1);
    }
    return C;
}







int *back(int *C, int kol)
{
    int *D=NULL;
    int i,j;
    i=0;
    while(C[i]==0)
    {
        i=i+1;
    }
    printf("Kol in back =%d\n", kol);
    D=(int*)malloc(kol*sizeof(int));
    for(i=i, j=0; j<kol; i++, j++)
    {
        D[j]=C[i];
        printf("D[%d]=%d\n",j, D[j]);
    }
    return D;
}


int back_length(int *C, int n1, int n2)
{
    int i,kol,k;
    i=0;
    kol=0;
    k=max(n1,n2)+1;
    while(C[i]==0)
    {
        i=i+1;
    }
    kol=k-i;
    printf("N1 in back length=%d\n", n1);
    printf("Kol in back length=%d\n", kol);
    return kol;
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
    int k,j,z;
    int *C=NULL;
    k=n1;
    z=0;
    C=(int*)malloc((k+1)*sizeof(int));
    C[k-1]=(A1[n1-1]+1)%10;
    printf("C[%d]=%d\n",k-1, C[k-1]);
    z=(A1[n1-1]+1)/10;
    for (j=k-2;j>=0;j--)
    {
        C[j]=(A1[j]+z)%10;
        printf("C[%d]=%d\n",j, C[j]);
        z=(A1[j]+z)/10;
    }
    C[0]=C[0]+z;

    return C;
}


int *SUB_NN_N(int n1, int *A1, int n2, int *A2)
{
    int i, k,srav1,srav2,srav3;
    int *B1=NULL, *B2=NULL;
    int *C=NULL;

    srav1=-1;
    srav2=-1;
    srav3=-1;
    srav1=NZER_N_B(n1, A1);
    srav2=NZER_N_B(n2, A2);
    if (srav1==0)
    {
        C=(int*)malloc(n2*sizeof(int));
        C=A2;
    }
    else if (srav2==0)
    {
        C=(int*)malloc(n1*sizeof(int));
        C=A1;
    }
    else if ((srav1==1)&&(srav2==1))
    {
        srav3=COM_NN_D(n1, A1, n2, A2);
        if(srav3==0)
        {
            C=(int*)malloc(1*sizeof(int));
            C[0]=0;
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
                printf("C[%d]=%d\n",i, C[i]);

            }
        }

    }
    return C;
}
