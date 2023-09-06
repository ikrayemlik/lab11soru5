

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*

Bir ba�l� do�rusal listelerde listenin sonundaki d���m� keserek listenin ba��na ekleyen ve
olu�an listenin son halini geri d�nd�ren prototipi a�a��da verilmi� fonksiyonu yaz�n�z.

*/

//struct node* cutlastaddhead(struct node* head);


struct node {
int number;
struct node* next;
};

typedef struct node node;

node* bastankesme(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    node* p=head;
    while(p->next!=NULL)
    {

        p=p->next;
    }

    p->next=head;
    head=head->next;
    p->next->next=NULL;
    return head;

}

void bastir(node* head)
{

    node* p=head;

    while(p!=NULL)
    {
        printf("%d ",p->number);
        p=p->next;
    }
    printf(" ");

}


int main()
{
    int n,sayi;

    printf("kac dugum olsun:  ");
    scanf("%d",&n);
    int i;

    node* head=NULL;

    for(i=0;i<n;i++)
    {
        printf("%d. sayi giriniz:  ",i+1);
        scanf("%d",&sayi);
        node* newnode=(node*)malloc(sizeof(node));
        newnode->number=sayi;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            node *p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=newnode;
        }

    }
    printf("orijinal list:  ");
    bastir(head);

    head=bastankesme(head);
    printf("guncellenmis list:  ");
    bastir(head);


    return 0;
}
