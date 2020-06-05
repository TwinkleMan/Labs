#include "list.h"
#include "dataRead.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

node *create_node(FILE *source,int *length)
{
    int i;
    char **data = NULL;

    data = getData(source);

    node *temp;
    temp = (node*) malloc (sizeof(node));
    temp->guitar = (guitar*)malloc(sizeof(guitar));
    temp->guitar->name = (char*)malloc(sizeof(char) * strlen(data[0]));
    strcpy(temp->guitar->name,data[0]);
    temp->guitar->info = (char*)malloc(sizeof(char) * strlen(data[1]));
    strcpy((temp->guitar->info),data[1]);
    temp->guitar->numOfPickups = atoi(data[2]);
    temp->guitar->numOfFrets = atoi(data[3]);
    temp->guitar->numOfString = atoi(data[4]);
    temp->guitar->menzureLength = atof(data[5]);
    temp->guitar->neckRadius = atof(data[6]);
    temp->guitar->stringsWidth = (int*)malloc(sizeof(int) * temp->guitar->numOfString);
    for (i = 0;i < (temp->guitar->numOfString);i++) {
        temp->guitar->stringsWidth[i] = atoi(data[7 + i]);
    }
    temp -> next = NULL;
    temp->previous = NULL;
    clearStrArray(data,(i + 7));
    (*length)++;
    return temp;
}

void print_from_head(node **head)
{
    node *p;
    int i;

    p = *head;
    system("cls");
    if (p == NULL) {
        puts("There's nothing to print");
    }
    while (p != NULL) {
        printf("Name: %s\n", p->guitar->name);
        printf("Description/info: %s\n",p->guitar->info);
        printf("Number of Pickups: %d\n", p->guitar->numOfPickups);
        printf("Number of frets: %d\n",p->guitar->numOfFrets);
        printf("Number of strings: %d\n",p->guitar->numOfString);
        printf("Menzure length: %.2f\n",p->guitar->menzureLength);
        printf("Neck radius: %.2f\n",p->guitar->neckRadius);
        printf("Strings width: ");
        for (i = 0;i < (p->guitar->numOfString);i++) {
            printf("%d ",p->guitar->stringsWidth[i]);
        }
        p = p->next;
        printf("\n\n");
    }
}

void print_from_tail(node **tail)
{
    node *p;
    int i;

    p = *tail;
    system("cls");
    if (p == NULL) puts("There's nothing to print!");
    do {
        printf("Name: %s\n", p->guitar->name);
        printf("Description/info: %s\n",p->guitar->info);
        printf("Number of Pickups: %d\n", p->guitar->numOfPickups);
        printf("Number of frets: %d\n",p->guitar->numOfFrets);
        printf("Number of strings: %d\n",p->guitar->numOfString);
        printf("Menzure length: %.2f\n",p->guitar->menzureLength);
        printf("Neck radius: %.2f\n",p->guitar->neckRadius);
        printf("Strings width: ");
        for (i = 0;i < (p->guitar->numOfString);i++) {
            printf("%d ",p->guitar->stringsWidth[i]);
        }
        p = p->previous;
        printf("\n\n");
    } while (p != (*tail));
}

void add_first(node **head,FILE *source,int *length)
{
    node *temp;

    temp = create_node(source,length);
    temp->next = *head;
    temp->previous = NULL;
    if (*length != 1) {
        (*head)->previous = temp;
    }
    *head = temp;
}

void add_last(node **tail,FILE *source,int *length)
{
    node *temp;

    temp = create_node(source,length);
    (*tail)->next = temp;
    temp->previous = *tail;
    *tail = temp;
}

void pop(node **head,int *length)
{
    node *temp = NULL;

    if (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        (*head)->previous = NULL;
        (*length)--;
        delete(&temp);
        puts("Success!");
    } else puts("There's nothing to delete!");
}

void removeNode(node **head,int i,int *length) //удаляет элемент перед элементом с указанным номером
{
    node *temp = NULL;
    node *mem = NULL;
    int j = 0;

    if (i != 1) {
        temp = *head;
        if (j == i - 2) {
            pop(head,length);
        } else {
            do {
                mem = temp;
                temp = temp->next;
                j++;
            } while (j != (i - 2) && temp != NULL);
            if (temp == NULL) {
                puts("No such node!");
            } else {
                temp->previous->next = temp->next;
                //mem->next = temp->next;
                temp->next->previous = temp->previous;
                delete(&temp);
                (*length)--;
                puts("Deleted successfully!");
            }
        }
    } else {
        puts("You cannot delete the node before head! (node does not exist!)");
    }
    if (temp != NULL) {
        temp = NULL;
    }
}

void delete(node **unit)
{
    (*unit)->guitar->name = NULL;
    (*unit)->guitar->info = NULL;
    (*unit)->guitar->stringsWidth = NULL;
    free((*unit)->guitar);
    (*unit)->guitar = NULL;
    free((*unit));
    unit = NULL;
}

void invert_list(node **head)
{
    node *current = NULL, *next = NULL, *previous = NULL;

    if (*head != NULL) {
        current = *head;
        while (current) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        *head = previous;
    } else {
        puts("You can't invert this list!");
        return;
    }
}

void insert(node **head, int index,FILE *source,int *length)
{
    node *p,*temp;
    int i;

    if (index == 0) {
        add_first(head,source,length);
    } else {
        p = *head;
        i = 0;
        while (i < index - 1 && p != NULL) {
            p = p->next;
            i++;
        }
        if (p == NULL) {
            puts("No such node!");
        } else {
            temp = create_node(source,length);
            temp->next = p;
            temp->previous = p->previous;
            p->previous = temp;
        }
    }
}

void clearList(node **head,int length)
{
    int i;
    node *temp = NULL;

    temp = *head;
    for(i = 0;i < length;i++) {
        if (temp->guitar->stringsWidth != NULL) {
            free(temp->guitar->stringsWidth);
            temp->guitar->stringsWidth = NULL;
        }
        free(temp->guitar);
        temp->guitar = NULL;
        temp->previous = NULL;
        temp = temp->next;
    }
}
