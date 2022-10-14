#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void initializeBooks();
void printListBooks();
void printMenu();
void insertData(int idx);
void addBook();
void updateBook();
void deleteBook();
void sellBook();
void save();


struct Data{
	char title[55];
	int qty;
	int price;
}books[100];
int numBooks;

int main(){
	
	initializeBooks();
	
	int choice;
	do{
		system("cls");
		puts("Course- Net Book Store");
		puts("----------------------");
		printListBooks();	
		
		printMenu();
		do{
			printf("Choice: ");
			scanf("%d", &choice);
			fflush(stdin);
		} while(choice <1 || choice >5);
		
		switch(choice){
			case 1:
				system("cls");
				addBook();
				break;
			case 2:
				updateBook();
				break;
			case 3:
				deleteBook();
				break;
			case 4:
				sellBook();
				break;
			case 5:
				save();
				break;	
		}
		
	}while(choice != 5);
}

void initializeBooks(){
	FILE*file = fopen("C:/Users/Bryan Aurelius/OneDrive/Desktop/Algorith and ProgrammingC++/Exam II/Books.txt","r");
	
	while(!feof(file)){
		fscanf(file, "%[^#]#%d#%d\n", 
			books[numBooks].title, &books[numBooks].qty, &books[numBooks].price);
		numBooks++;
	}
	
	fclose(file);
}

void printListBooks(){
	if(numBooks ==0){
		puts("Book empty");
		return;
	}
	printf("%-3s %-55s %10s %10s\n", "No", "Title", "Quantity", "Price");
	for(int i=0; i<numBooks; i++){
		printf("%-3d %-55s %10d %10d\n", 
		i+1, books[i].title, books[i].qty, books[i].price);
	}
	puts("");
	
}

void printMenu(){
	puts("Menu");
	puts("1. Add Book");
	puts("2. Update Book");
	puts("3. Delete Book");
	puts("4. Sell Book");
	puts("5. Save and Exit");
	
}

void insertData(int idx){
	do{
		printf("Input book title[5..50] : ");
		scanf("%[^\n]", books[idx].title);
		fflush(stdin);	
		
		int len= strlen(books[idx].title);
		if( len >=5 && len <= 50) break;
	}while(true);
	
	do{
		printf("Input book quantity[1..10] : ");
		scanf("%d", &books[idx].qty);
		fflush(stdin);	
	}while(books[idx].qty<1 || books[idx].qty>10);
	
	do{
		printf("Input book price[100000..800000] : ");
		scanf("%d", &books[idx].price);
		fflush(stdin);	
	}while(books[idx].price<100000 || books[idx].price>800000);
}



void addBook(){
	system("cls");
	puts("Add Book");
	puts("==========");
	insertData(numBooks);
	
	printf("Book added!\n");
	puts("press enter to continue..");
	getchar();
	numBooks++;
	
}
void updateBook(){
	system("cls");
	puts("Update Book");
	puts("=============");
	printListBooks();
	
	if(numBooks==0){
		printf("Book empty");
		getchar();
		return;
	}
	
	int idx;
	do{
		printf("Update book[1..%d] : ", numBooks);
		scanf("%d", &idx);
		fflush(stdin);
	}while(idx<1 || idx> numBooks);
	
	insertData(idx-1);
	
	printf("Book updated!");
	getchar();
}

void deleteBook(){
	system("cls");
	puts("Delete Book");
	puts("============");
	printListBooks();
	
	int idx;
	do{
		printf("Delete book no[1..%d] : ", numBooks);
		scanf("%d", &idx);
		fflush(stdin);
	}while(idx <1 || idx >numBooks);
	idx--;
	
	for(int i=idx; i<numBooks; i++){
		books[i]= books[i+1];
	}
	numBooks--;
	printf("Book deleted!");
	getchar();
}
void sellBook(){
	system("cls");
	puts("Sell Book");
	puts("============");
	printListBooks();
	
	if(numBooks==0){
		printf("No books to sold");
		getchar();
		fflush(stdin);
		return;
	}
	
	float price=0;
	int idx;
	do{
		printf("Sell book no[1..%d]: ", numBooks);
		scanf("%d", &idx);
		fflush(stdin);
	}while(idx<1 || idx> numBooks);
	idx--;
	
	int qty;
	do{
		printf("Insert book quantity[1..%d] : ", books[idx].qty);
		scanf("%d", &qty);
		fflush(stdin);
	}while(qty<1 || qty>books[idx].qty);
	
	books[idx].qty -= qty;
	
	printf("Total Payment: %d", books[idx].qty*books[idx].price);
	
	getchar();
	fflush(stdin);
}

// untuk yang void sellBook(), referensinya dari punya luois waktu share sreen direcord 
void save(){
	FILE *file= fopen("C:/Users/Bryan Aurelius/OneDrive/Desktop/Algorith and ProgrammingC++/Exam II/Books.txt","w");	
	
	for(int i=0; i<numBooks; i++){
		fprintf(file, "%s#%d#%d\n", books[i].title, books[i].qty, books[i].price);
	}
	fclose(file);
}

// untuk semuanya referensinya dari review recordingnya ulang
