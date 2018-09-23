#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
using namespace std;
struct isimlistesi {
       char isim[10];
       char soyisim[10];
       int yas;
        isimlistesi* next;
       };
 //      void (struct isimlistesi *head);
isimlistesi *listedoldur ( isimlistesi *head,char *isim1 ,char *soyisim1 , int yas);
void listeyazdir(isimlistesi *head);
FILE *dosya;
FILE *dosya2;
int main(){
//dosya =fopen("girdiler.txt","w");
char isim[10],soyisim[10];
char x,degisken=0;
int yas;
struct isimlistesi *head = NULL;
cout << " Islemi Sonlandirmak Ýcin 'Q'"<< endl;
do {
if(x=='Q' || x=='q')
break;
dosya = fopen ("girdiler.txt ", "a");     
cout << "Isim : ";
cin >> isim;
cout << "Soy Isim :" ;
cin >> soyisim;
cout << "Yas : ";
cin >> yas; 
fprintf(dosya,"%s\t%s\t%d\n",isim,soyisim,yas);
fclose(dosya);
//dosya = fopen ("girdiler.txt","r");
//
 cout << "Devam Etmek Istiyormusun ?" ;
      
      //cout << x << endl << endl << endl;
      cout << endl;
      x=getch();
}while (x!='Q' || x!='q');  
//fclose(dosya);
dosya = fopen("girdiler.txt","r");
while (!feof(dosya)){
fscanf(dosya,"%s\t%s\t%d\n",isim,soyisim,&yas);
head= listedoldur(head,isim,soyisim,yas);
}
listeyazdir(head);
struct isimlistesi *temp = head;
while (temp != NULL){
dosya2 =fopen("ciktilar.txt","a");
fprintf(dosya2,"Isim : %s \t Soyisim : %s \t Yas: %d \n",temp->isim,temp->soyisim,temp->yas);
temp = temp -> next;
fclose(dosya2);
}

system("pause");
return 0;
}
isimlistesi *listedoldur(isimlistesi *head,char *isim1 ,char *soyisim1,int yas){
   struct isimlistesi *temp = head;
    if (head == NULL){
    head = new isimlistesi();
    strcpy(head->isim,isim1);
    strcpy(head->soyisim,soyisim1);
    head -> yas = yas;
        head -> next = NULL;
        return head;}
    else if (temp -> yas < yas ){
        while (temp -> next  != NULL && temp->next->yas < yas)
            temp = temp -> next;
        struct isimlistesi *temp2 = new isimlistesi();
          strcpy(temp2->isim,isim1);
                                             strcpy(temp2->soyisim,soyisim1);
                                             temp2 -> yas = yas;
        if (temp -> next == NULL){
            
        temp -> next = temp2;
            temp2 -> next = NULL;}
        else{
            temp2 -> next = temp -> next;
            temp -> next = temp2;
            }
    return head;
    }
    else {
        struct isimlistesi *temp2 = new isimlistesi();
         strcpy(temp2->isim,isim1);
                                             strcpy(temp2->soyisim,soyisim1);
                                             temp2 -> yas = yas;
        temp2 -> next = head;
        return temp2;
    }
    //return 0;
}

       void listeyazdir(isimlistesi *head){
           
            while ( head  != NULL){
                  cout << head -> isim << "\t " << head -> soyisim << "\t " << head -> yas << endl;
                  head = head -> next;
                  }
            }
            
