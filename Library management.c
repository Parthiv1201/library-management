#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

struct node{
char title[20];
char author[20];
char publisher[20];
int price;
int quantity;
struct node *left;
struct node *right;
};
struct node* root=NULL;
int user_payment=0;
struct node* get_node(char title[],char author[],char publisher[],int price,int quantity)         //Create new node and return its reference
{
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        strcpy(temp->author,author);
        strcpy(temp->publisher,publisher);
        strcpy(temp->title,title);

        temp->price=price;
        temp->quantity=quantity;
        temp->left = NULL;
        temp->right = NULL;

        return temp;

}

struct node* add_first_book(char title[],char author[],char publisher[],int price,int quantity)         //Add first book in library
{
        if(root==NULL)
            root=get_node(title,author,publisher,price,quantity);

        return root;
}

struct node* add_book(struct node* root,struct node* temp)                          //Add book
{
            if(root==NULL)
                return temp;
            if(strcmp(temp->title,root->title)>0)
            root->right=add_book(root->right,temp);
            else if (strcmp(temp->title,root->title)<=0)
                root->left=add_book(root->left,temp);

            return root;

}

void find_book(struct node* root,char title[20],int purchase_quantity)                  //Find any book from library
{
        while(root!=NULL)
        {
            if(strcmp(title,root->title)==0)
            {

                if(purchase_quantity==-1 && root->quantity!=0)                                  //If user want to check book availability
                {
                printf("----------------------------------\n");
                printf("\tTitle : ");
                puts(root->title);
                printf("\tAuthor name : ");
                puts(root->author);
                printf("\tPublisher name : ");
                puts(root->publisher);
                printf("\tPrice : %d\tQuantity : %d",root->price,root->quantity);
                printf("\n----------------------------------\n");
                return;
                }
                else if(purchase_quantity>root->quantity || root->quantity==0)
                {
                    if(root->quantity!=0)
                    printf("\nNo sufficient book ! ! \n");
                    else
                    printf("\nNo book available\n");
                    return;
                }
                else                                                                                                                //If user want to buy book
                {
                user_payment=user_payment+(purchase_quantity*root->price);
                printf("\nBook purchased successfully \n------------------------------------------\n");
                printf("\tTitle : ");
                puts(root->title);
                printf("\tAuthor name : ");
                puts(root->author);
                printf("\tPublisher name : ");
                puts(root->publisher);
                printf("\tPrice : %d\tQuantity : %d",root->price,purchase_quantity);

                printf("\n\n\tYou have to pay %d\n---------------------------------------\n",user_payment);
                root->quantity=root->quantity-purchase_quantity;

                printf("----------------------------------\n");
                return;
                }

            }
            else if(strcmp(title,root->title)<0)
                root=root->left;
            else
                root=root->right;
        }

        printf("\nNo book with the title ' %s ' exist\nCheck after some time\n",title);

}

void all_book(struct node* root)                                                //Print all book which is available in library
{
    if(root==NULL)
    return;
    all_book(root->left);
    if(root->quantity!=0)
    {
                printf("----------------------------------\n");
                printf("\tTitle : ");
                puts(root->title);
                printf("\tAuthor name : ");
                puts(root->author);
                printf("\tPublisher name : ");
                puts(root->publisher);
                printf("\tPrice : %d\tQuantity : %d",root->price,root->quantity);
                printf("\n----------------------------------\n");

    }
    all_book(root->right);
}


void book_delete(struct node* root,char title[])                                    //Delete book
{
    int quantity,choice;
    while(root!=NULL)
    {
        if(strcmp(title,root->title)==0)
        {
            if(root->quantity==0)
            {
                printf("Book not exist\n");
                return;
            }
            printf("1.Delete book\n2.Delete some quantity\n");fflush(stdin);
            scanf("%d",&choice);
            if(choice==1)                                                           //Delete book from library
            {
                printf("----------------------------------\n");
                printf("\tTitle : ");
                puts(root->title);
                printf("\tAuthor name : ");
                puts(root->author);
                printf("\tPublisher name : ");
                puts(root->publisher);
                printf("\tPrice : %d\tQuantity : %d",root->price,root->quantity);
                printf("\n----------------------------------\n");
                root->quantity=0;
                printf("Delete  successfully\n");
            }
            else if(choice==2)                                                  //Delete some quantity of book from library
            {
                printf("----------------------------------\n");
                printf("\tTitle : ");
                puts(root->title);
                printf("\tAuthor name : ");
                puts(root->author);
                printf("\tPublisher name : ");
                puts(root->publisher);
                printf("\tPrice : %d\tQuantity : %d",root->price,root->quantity);
                printf("\n----------------------------------\n");
                printf("Enter quantity you want to remove --- ");
                scanf("%d",&quantity);
                 while(quantity>root->quantity || quantity<0)               //Iterate until user enter suitable quantity
                 {
                printf("Error-----  ! !\n");
                if(quantity<0)
                {
                    printf("Enter positive number\n");
                }
                else if(quantity>root->quantity)
                {
                        printf("Not sufficient book \n");
                }
                printf("Again enter quantity you want to remove --- ");
                scanf("%d",&quantity);
                 }
                root->quantity=root->quantity-quantity;
                printf("Quantity remove successfully\n");
                 printf("----------------------------------\n");
                printf("\tTitle : ");
                puts(root->title);
                printf("\tAuthor name : ");
                puts(root->author);
                printf("\tPublisher name : ");
                puts(root->publisher);
                printf("\tPrice : %d\tQuantity : %d",root->price,root->quantity);
                printf("\n----------------------------------\n");
            }
            return;
        }
        else if(strcmp(title,root->title)<0)
            root=root->left;
        else
            root=root->right;
    }
    printf("\nNo book with the title ' %s ' exist\n",title);

}


void main()
{
    struct node *ptr;
    int choice,price,quantity,purchase_quantity,x,y,n=1,i=0,ask_user;
    char title[20],author[20],publisher[20],username[20],password[20],ch;
    printf("\t\t###########################################################################");
    printf("\n\t\t############                                                    ###########");
    printf("\n\t\t############\t\tLibrary management System\t\t###########");
    printf("\n\t\t############                                                    ###########");
    printf("\n\t\t###########################################################################");
    printf("\n--------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\tUSER : nirma_uni\n");
    printf("\t\t\tPASSWORD : password\n");
    do{                                                                          //Log in System run loop until user name and password match
    printf("\n\t\t\tUSER name : ");fflush(stdin);
    gets(username);
    printf("\t\t\tPassword : ");fflush(stdin);
    while(ch!=13)
    {
        ch=getch();

        if(ch!=13&&ch!=8)
        {
            putch('*');
            password[i]=ch;
            i++;
        }
    }
    ch='\0';
    password[i]='\0';
    x=strcmp(username,"nirma_uni");
    y=strcmp(password,"password");
    if(x==0 && y==0)
    {
        printf("\n\t\t\tSuccessfully logged in\n");
        break;
    }
    else
    {
        printf("\n\t\t\tWrong password ,try again\n");
        n++;
        i=0;
    }
    }while(1);

    //Menu driven function

    while(1){
    printf("\n----------------------------------------\n1.Add book\n2.Book you want to buy or check book availability\n3.Remove book quantity\n4.All available book detail\n5.Exit\n\n>>  ");
    scanf("%d",&choice);
    printf("\n");
    switch(choice)
    {
    case 1:
        printf("Enter title of book -- ");
        fflush(stdin);
        gets(title);
        fflush(stdin);
        printf("Enter author name -- ");
        gets(author);
        fflush(stdin);
        printf("Enter publisher name -- ");
        gets(publisher);
        fflush(stdin);
        printf("Enter price of the book -- ");
        scanf("%d",&price);
        fflush(stdin);
        printf("Enter quantity of book -- ");
        scanf("%d",&quantity);
        if(root==NULL)
            root=add_first_book(title,author,publisher,price,quantity);
        else
        {
            ptr=get_node(title,author,publisher,price,quantity);
            root=add_book(root,ptr);
        }
        break;

    case 2:

        printf("1.Purchase book\n2.Check book\n---> ");
        scanf("%d",&ask_user);
        if(ask_user==1){
           printf("Enter name of book (title) --- ");
        fflush(stdin);
        gets(title);
        fflush(stdin);
        printf("Enter quantity of book you want to purchase --- ");
        scanf("%d",&purchase_quantity);
        find_book(root,title,purchase_quantity);
        }
        else if(ask_user==2){
                 printf("Enter name of book (title) --- ");
        fflush(stdin);
        gets(title);
        fflush(stdin);
        find_book(root,title,-1);}
        else
            printf("Enter valid input\n");
        break;

    case 3:
          printf("Enter name of book (title) --- ");
        fflush(stdin);
        gets(title);
        fflush(stdin);
        book_delete(root,title);
        break;

    case 4:
        all_book(root);
        break;
    case 5:
        exit(0);
    default:
        printf("Enter valid input\n");

    }
    printf("\n");
    }

}
