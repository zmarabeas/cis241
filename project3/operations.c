#include "operations.h"

void displayProduct(Product* item){
    if(item != NULL){
        printf("Product Name: %s\n", item->name);
        printf("Number of units: %.2f %s\n", item->quantity_value, item->quantity_unit);
        printf("Price: $%.2f %s\n\n", item->price_value, item->price_unit);
    }else{
        printf("Item not found\n");
    }
}

Product* createNode(){
    Product* tmp = (Product*)malloc(sizeof(Product));
    if(tmp == NULL){
        puts("error allocating memory in createNode\n");
        return NULL;
    }
    fflush(stdin);
    printf("Please input the product name: ");
    scanf("%s", tmp->name);
    fflush(stdin);
    printf("Please input the quantity value: ");
    scanf("%f", &(tmp->quantity_value));
    fflush(stdin);
    printf("Please input the quantity unit:         ");
    scanf("%s", (tmp->quantity_unit));
    fflush(stdin);
    printf("Please input the price value:         ");
    scanf("%f", &(tmp->price_value));
    fflush(stdin);
    printf("Please input the price unit:         ");
    scanf("%s", (tmp->price_unit));
    fflush(stdin);
    tmp->next = NULL;

    return tmp;
}

void insert(Product **l, Product *node){
    Product* tmp = *l;
    if (l == NULL) {
       *l = node;
    }else{
        Product* found = findItem(*l, node->name, false);
        if(found != NULL){
            found->quantity_value = node->quantity_value;
        }else{
            while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = node;
       }
    }
}

void rmItem(Product **l, char p[]){
    Product * current = *l;
    Product * previous = current;
    while(current != NULL) {
        if (strcmp(current->name, p)==0) {
            if(previous == current)
                *l = (current->next);
            else
                previous->next = current->next;

            free (current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void showList(Product * l){
    Product* current = l;
    while(current != NULL){
        displayProduct(current);
        current = current->next;
    }
}

Product* buildNode(char name[], float qv, char qu[], float pv, char pu[]){
    Product* p = (Product*)malloc(sizeof(Product));
    if(p==NULL){
        puts("error allocating memory in buildNode");
        return NULL;
    }
    strcpy(p->name, name);
    p->quantity_value = qv;
    strcpy(p->quantity_unit, qu);
    p->price_value = pv;
    strcpy(p->price_unit, pu);
    p->next = NULL;

    return p;
}

Product* loadData(char inf[], Product *l){
    char name[N], qu[N], pu[N];
    int rt;
    float qv, pv;
    Product* tmp = l;
    FILE * fin = fopen(inf, "r");
    if(fin == NULL) {
        printf("InLoad: File open failed (%s)\n", inf);
        return NULL;
    }

    while (1) {
        rt = fscanf(fin, "%s %f %s %f %s\n", name, &qv, qu, &pv, pu);
        if (rt < 5)
            break;
        if (tmp == NULL){
            tmp = buildNode(name, qv, qu, pv, pu);
        }else{
            insert(&tmp, buildNode(name, qv, qu, pv, pu));
        }
    }
    fclose(fin);
    return tmp;
}

int saveData(char outf[], Product *l){
    FILE * fout = fopen(outf, "w");
    if(fout == NULL) {
        printf("InSave: File open failed (%s)\n", outf);
        return 1;
    }
    Product* current = l;
    while (current != NULL){
        fprintf(fout, "%s %f %s %f %s\n",
                current->name, current->quantity_value, current->quantity_unit,
                current->price_value, current->price_unit);
        current = current->next;
    }
    fclose(fout);
    return 0;
}

float purchase(Product *l, char p[], float q){
    float cash = 0;
    Product* item = findItem(l, p, false);
    if(item == NULL){
        return cash;
    }else{
        if(item->quantity_value < q){
            cash = item->quantity_value*item->price_value;
            rmItem(&l, p);
        }else{
            cash = item->price_value*q;
            item->quantity_value -= q;
        }
    }
    return cash;
}

void check_price(Product *l, char p[]){
    Product* item = findItem(l, p, false);
    if(item != NULL){
        printf("Price of %s: %.02f\n", item->name, item->price_value);
    }
}

Product* findItem(Product *l, char p[], bool display){
    Product* current = l;
    while(current != NULL){
        if(strcmp(current->name, p) == 0){
            if(display)
                displayProduct(current);
            return current;
        }
        current = current->next;
    }
    if(display==true)    
        displayProduct(NULL);
    return NULL;
}

void displayMenu(){
    puts("\nHere is the menu for this list.");
    puts("============================================================");
    puts("1: Add a product			2: Purchase product");
    puts("3: Check price of a Product		4: Show all Products");
    puts("5: Remove a product		        6: Find a product");
    puts("7: Inventory		                8: Done for today\n");
}

int doIt(char data[]){
    system("clear");
    Product* head = NULL;
    bool done = false;
    int choice, quantityInput;
    char nameInput[N];
    float cash;
    head = loadData(data, head);
    displayMenu();
    while (!done) {        
        puts("What do you want to do?");
        fflush(stdin);
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice){
            case 1:
                insert(&head, createNode());
                break;
            case 2:
                fflush(stdin);
                printf("Enter the product you would like to purchase: ");
                scanf("%s", nameInput);
                fflush(stdin);
                printf("Enter how many you would like to purchase: ");
                scanf("%d", &quantityInput);
                fflush(stdin);
                cash += purchase(head, nameInput, quantityInput);
                break;
            case 3:
                fflush(stdin);
                printf("Enter the product you would like to purchase: ");
                scanf("%s", nameInput);
                fflush(stdin);
                check_price(head, nameInput);
                break;
            case 4:
                showList(head);
                break;
            case 5:
                fflush(stdin);
                printf("Enter the product to delete: ");
                fflush(stdin);
                scanf("%s", nameInput);
                fflush(stdin);
                rmItem(&head, nameInput);
                break;
            case 6:
                fflush(stdin);
                printf("Enter the product to find: ");
                fflush(stdin);
                scanf("%s", nameInput);
                findItem(head, nameInput, true);
                break;
            case 7:
                printf("Total cash earned today: $%.2f\n", cash);
                showList(head);
                break;
            case 8:
                saveData("data", head);
                done = true;
                printf("Total cash earned today: $%.2f\n", cash);
                showList(head);
                break;
            default:
                puts("Wrong code. Please try again.");
                break;
        }
    }
}