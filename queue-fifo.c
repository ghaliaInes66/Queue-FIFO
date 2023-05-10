#include<stdio.h>
#include<stdlib.h>

typedef struct student {
  char fname[20];
  char lname[20];
  float gpa;
}student;


typedef struct node
{
  student data;
  struct node *next;
}node;


void addlast(node **head,student s){
       	node *p=(node*)malloc(sizeof(node));
		p->data=s;
		p->next=NULL;
		if(*head==NULL)
		{
			*head=p;}
		else{
			node *q=*head;
			while(q->next!=NULL){
				q=q->next;
			}
			q->next=p;
		}	
}

void deletebegin(node **head){
  node *p=*head;
      *head=p->next;
      free(p);
}
void display_list(node *head){
	if(head==NULL){
		printf("list is empty");
	}
	else{
		node *p=head;
		while(p!=NULL)
		{
		  puts(p->data.fname);
		  puts(p->data.lname);
		  printf("%f",p->data.gpa);
			p=p->next;
		}
		}
}

int main(){
  int N,i; node *head=NULL; student s;
  printf("enter the number of the students"); scanf("%i",&N);
   for(i=0;i<N;i++){
    printf("enter the first name ");
    scanf("%s",s.fname);
    printf("enter the last name ");
    scanf("%s",s.lname);
    printf("enter the gpa ");
    scanf("%f",&s.gpa);
    addlast(&head,s);
   }
   display_list(head);
   FILE *file;
  file=fopen("students.txt","a");
  node *p=head;
  for(i=0;i<N;i++){
    fputs(p->data.fname,file);fprintf(file,"     ");
    fputs(p->data.lname,file);fprintf(file,"     ");
    fprintf(file,"%f",p->data.gpa);fprintf(file,"\n");
    p=p->next;
    deletebegin(&head);
  }
  fclose(file);
  display_list(head);
}
