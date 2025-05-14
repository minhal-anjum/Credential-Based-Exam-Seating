#include<stdio.h>
struct Student{
	char id[10];
	char name[50];
};
int main(){
	struct Student students[25] ={
		{"ID001", "Ali"}, {"ID002", "Anus"},{"ID003", "Manahil khan"},
		{"ID004", "Minhal"},{"ID005","Tooba "},{"ID006","Hadia"},{"ID007", "Taskeen"},
		{"ID008", "Dua"}, {"ID009", "Tazeem"},{"ID010", "Kaneez"},{"ID011", "Fatima"},
		{"ID012", "Usman"},{"ID013","Yusra"},{"ID014", "Ayesha"},{"ID015", "Hamza"},
		{"ID015", "Alina"},{"ID016", "kaifee"},{"ID017","Ibrahim"},{"ID018","Aniya"},
		{"ID019", "Eman"},{"ID020", "Azbiya"},{"ID021", "Abbas"},{"ID022", "Tayaba"},
		{"ID023", "Hamza"},{"ID024", "Komal"};
		};
		int i;
		for(int i=0; i<=25; i++)
			printf("Student %d - ID: %S Name:%s\n", i+1, students[i].id,students[i].name);
		}


		
		
		
		
		
		
	
		
	


