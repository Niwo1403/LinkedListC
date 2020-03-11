#include <stdio.h>
#include <stdlib.h>

struct LIST {
	int number;
	struct LIST *next;
};

int search_elm(struct LIST *llIST, int num);
void add_elm(struct LIST *llIST, int num);
void print_list(struct LIST *llIST);
void rmv_elm(struct LIST *llIST, int num);
int get_elm(struct LIST *llist, int index);

int main(){
	struct LIST *llist = (struct LIST *) malloc(sizeof(struct LIST));
	llist->number = 1;
	llist->next = NULL;

	add_elm(llist, 2);
	add_elm(llist, 3);
	add_elm(llist, 4);
	printf("%d\n\nall:\n", get_elm(llist, 2));
	print_list(llist);
	

	getchar();
	free(llist);
	return (0);
}

void print_list(struct LIST *llist){
	while (llist->next != NULL){
		printf("%d ", llist->number);
		llist = llist->next;
	}
	printf("%d", llist->number);
}

void add_elm(struct LIST *llist, int num){
	while (llist->next != NULL)
		llist = llist->next;
	llist->next = (struct LIST *) malloc(sizeof(struct LIST));
	llist->next->number = num;
	llist->next->next = NULL;
}

void rmv_elm(struct LIST *llist, int num){
	struct LIST *temp;
	temp = (struct LIST *) malloc(sizeof(struct LIST));
	if (llist->number == num){
		temp = llist->next;
		free(llist);
		llist = temp;
	}else{
		while (llist->next->number != num)
			llist = llist->next;

		temp = llist->next->next;
		free(llist->next);
		llist->next = temp;
	}
}

int search_elm(struct LIST *llist, int num){//start at 0
	for (int i = 0; llist != NULL; i++) {
		if (llist->number == num)
			return i;
		llist = llist->next;
	}
	return (-1);
}

int get_elm(struct LIST *llist, int index) {
	while (index > 0) {
		if (llist->next != NULL) {
			llist = llist->next;
		 }
		index--;
	}
	return llist->number;
}