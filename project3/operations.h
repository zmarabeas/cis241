#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20
typedef struct Product{
    char name[N];
	float quantity_value;
	char quantity_unit[N];
	float price_value;
	char price_unit[N];
    struct Product* next;
}Product;

typedef enum {
  false,
  true
} bool;

void displayProduct(Product* item);
Product* buildNode(char name[], float qv, char qu[], float pv, char pu[]);
Product* createNode();
void insert(Product **l, Product *node);
void rmItem(Product **l, char p[]);
void showList(Product * l);
Product* loadData(char inf[], Product *l);
int saveData(char outf[], Product *l);
float purchase(Product *l, char p[], float q);
void check_price(Product *l, char p[]);
Product* findItem(Product *l, char p[], bool printingList);
int doIt(char data[]);
void displayMenu();



#endif
