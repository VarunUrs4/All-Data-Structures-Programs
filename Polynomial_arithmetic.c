#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
    int exp;
    int coeff;
    struct node *next;
};

typedef struct node* NODE;

NODE start1 = NULL;
NODE start2 = NULL;
NODE start3 = NULL;
NODE start4 = NULL;
NODE last3 = NULL;

NODE create(int c,int p) {
    NODE new_node;
    new_node = (NODE)malloc(sizeof(struct node));
    new_node->exp = p;
    new_node->coeff = c;
    new_node->next = NULL;

    return new_node;

}
NODE create_poly(NODE start) {
    NODE new_node,ptr;
    int p,c;
    printf("\n Enter the co-efficient of X : ");
    scanf("%d",&c);
    printf("\n Enter its power : ");
    scanf("%d",&p);

    while(c != -1) {
        if(start == NULL) {
            new_node = create(c,p);
            start = new_node;
        }
        else {
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            new_node = create(c,p);
            ptr->next = new_node;
        }
        printf("\n Enter the co-efficient of X : ");
        scanf("%d",&c);
        if(c == -1) break;
        printf("\n Enter its power : ");
        scanf("%d",&p);
    }
    return start;
}

NODE display_poly(NODE start) {
    NODE ptr;
    ptr = start;
    while(ptr != NULL) {
        printf(" %d X %d ",ptr->coeff,ptr->exp);
        ptr = ptr->next;
    }
    return start;
}

NODE add_node(NODE start,int c,int p) {
    NODE ptr,new_node;
    if(start == NULL) {
        new_node = create(c,p);
        start = new_node;
    }
    else {
        ptr = start;
        while(ptr->next != NULL)
            ptr = ptr->next;
        new_node = create(c,p);
        ptr->next = new_node;
    }
    return start;
}

NODE add_poly(NODE start1,NODE start2,NODE start3)
{
    NODE ptr1,ptr2;
    int sum,c;
    ptr1 = start1,ptr2 = start2;
    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1->exp == ptr2->exp) {
            sum = ptr1->coeff + ptr2->coeff;
            start3 = add_node(start3,sum,ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->exp > ptr2->exp) {
            start3 = add_node(start3,ptr1->coeff,ptr1->exp);
            ptr1 = ptr1->next;
        }
        else if(ptr1->exp < ptr2->exp) {
            start3 = add_node(start3,ptr2->coeff,ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    if(ptr1 == NULL) {
        while(ptr2 != NULL) {
            start3 = add_node(start3,ptr2->coeff,ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    if(ptr2 == NULL) {
        while(ptr1 != NULL) {
            start3 = add_node(start3,ptr1->coeff,ptr1->exp);
            ptr1 = ptr1->next;
        }
    }
    return start3;
}

NODE sub_poly(NODE start1,NODE start2,NODE start4)
{
    NODE ptr1,ptr2;
    int sub,c;
    ptr1 = start1,ptr2 = start2;
    do {
        if(ptr1->exp == ptr2->exp) {
            sub = ptr1->coeff - ptr2->coeff;
            start4 = add_node(start4,sub,ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->exp > ptr2->exp) {
            start4 = add_node(start4,ptr1->coeff,ptr1->exp);
            ptr1 = ptr1->next;
        }
        else if(ptr1->exp < ptr2->exp) {
            start4 = add_node(start4,ptr2->coeff,ptr2->exp);
            ptr2 = ptr2->next;
        }
    } while(ptr1 != NULL || ptr2 != NULL);
    if(ptr1 == NULL) {
        while(ptr2 != NULL) {
            start4 = add_node(start4,ptr2->coeff,ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    if(ptr2 == NULL) {
        while(ptr1 != NULL) {
            start4 = add_node(start4,ptr1->coeff,ptr1->exp);
            ptr1 = ptr1->next;
        }
    }
    return start4;
}

int main()
{
    int option;

    do
    {
        printf("\n******* MAIN MENU *******");
        printf("\n 1. Enter the first polynomial");
        printf("\n 2. Display the first polynomial");
        printf("\n 3. Enter the second polynomial");
        printf("\n 4. Display the second polynomial");
        printf("\n 5. Add the polynomials");
        printf("\n 6. Display the result");
        printf("\n 7. Subtract the polynomials");
        printf("\n 8. Display the result");
        printf("\n 9. EXIT");
        printf("\n\n Enter your option ");
        scanf("%d", &option);

        switch(option) {
        case 1 :
            start1 = create_poly(start1);
            break;
        case 2 :
            start1 = display_poly(start1);
            break;
        case 3 :
            start2 = create_poly(start2);
            break;
        case 4 :
            start2 = display_poly(start2);
            break;
        case 5 :
            start3 = add_poly(start1,start2,start3);
            break;
        case 6 :
            start3 = display_poly(start3);
            break;
        case 7 :
            start4 = sub_poly(start1,start2,start4);
            break;
        case 8 :
            start4 = display_poly(start4);
            break;
        }
    } while(option != 9);

    return 0;
}
