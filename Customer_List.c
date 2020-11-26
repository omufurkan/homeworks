#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Cust {
  char *name;
  int amount;
  struct Cust *next;
}Cust;

struct Cust *CustList = NULL;
struct Cust *SortbyName = NULL;
struct Cust *SortbyAmount = NULL;


void AddCustomer(char *custname, int custamount) {

  if(CustList == NULL){//Eğer liste boşsa yeni müşteriyi direkt listeye ekliyorum.
    CustList = (struct Cust*) malloc(sizeof(struct Cust));
    CustList->name = custname;
    CustList->amount = custamount;
    CustList->next = NULL;
  }
  else{//Eğer listede başka müşteri varsa
    struct Cust *iter = CustList;
    struct Cust *temp = (struct Cust*) malloc(sizeof(struct Cust));
    temp->name = custname;
    temp->amount = custamount;    
    temp->next = NULL;
    while(iter->next != NULL){//Son elemandan bir önceki elemanı tespit ediyorum.
        iter = iter->next;
    }
    iter->next = temp;//Son elemanın sonrakine yeni veriyi ekliyorum.
  }
}

void addnameindex(char *custname, int custamount){
  struct Cust *iter = SortbyName;
  if(SortbyName == NULL){//Eğer liste boşsa müşteriyi direkt listeye ekliyorum.
    SortbyName = (struct Cust*) malloc(sizeof(struct Cust));
    SortbyName->name = custname;
    SortbyName->amount = custamount;
    SortbyName->next = NULL;
  }
  else if((strcmp(iter->name,custname))> 0){//Eğer liste boş değilse ve yeni eklenecek müşterinin adı, listenin başındaki müşterinin adından daha büyükse
    struct Cust *temp = (struct Cust*) malloc(sizeof(struct Cust));
    temp->name = custname;
    temp->amount = custamount;
    temp->next = SortbyName;
    SortbyName = temp;//Listenin başına yeni müşteriyi ekliyorum.
  }
  else{//Eğer liste boş değilse ve yeni eklenecek müşterinin adı, listedeki müşterinin adından daha küçükse
    struct Cust *temp = (struct Cust*) malloc(sizeof(struct Cust));
    temp->name = custname;
    temp->amount = custamount;
    if(iter->next == NULL){//Eğer listede tek müşteri varsa, isim kontrolünü daha önce yaptığımdan dolayı yeni müşteriyi, mevcut müşterinin hemen sonrasına ekliyorum.
      iter->next = temp;
      temp->next = NULL;
    }
    else{//Eğer listede tek müşteri yoksa
      while(iter->next != NULL){//Listedeki sondan bir önceki müşteriye kadar listeyi tarıyorum.
        if(((strcmp(iter->next->name,custname))< 0)){//Eğer o an seçtiğim müşteriden bir sonraki müşterinin adı, eklenecek müşterinin adından daha küçükse sonraki müşteriye geçiyorum.
          iter = iter->next;
        }
        else{//Değilse eklenecek yeri buldum. Bu durumda yeni müşteri ilk başta seçtiğim müşteri ile bir sonraki müşterinin arasına yerleşecek.
          temp->next = iter->next;
          iter->next = temp;
          break;//Yerleştirme işini yaptığım için while döngüsünü sonlandırıyorum.
        }
      }
      if(iter->next == NULL && temp->next == NULL){//Bu kısımda, eğer yeni müşteri herhangi iki müşterinin arasına yerleşmeyecekse ve listenin sonuna geldiysek en sona ekleme işlemi yapıyor.
        temp->next = iter->next;
        iter->next = temp;  
      }      
    }
  }
}

void addamountindex(char *custname, int custamount){  
  struct Cust *iter = SortbyAmount;
  if(SortbyAmount == NULL){//Eğer liste boşsa müşteriyi direkt listeye ekliyorum.
    SortbyAmount = (struct Cust*) malloc(sizeof(struct Cust));
    SortbyAmount->name = custname;
    SortbyAmount->amount = custamount;
    SortbyAmount->next = NULL;
  }
  else if((iter->amount) < custamount){//Eğer liste boş değilse ve yeni eklenecek müşterinin alışveriş tutarı, listenin başındaki müşterinin alışveriş tutarından daha büyükse
    struct Cust *temp = (struct Cust*) malloc(sizeof(struct Cust));
    temp->name = custname;
    temp->amount = custamount;
    temp->next = SortbyAmount;
    SortbyAmount = temp;//Listenin başına yeni müşteriyi ekliyorum.
  }
  else{//Eğer liste boş değilse ve yeni eklenecek müşterinin alışveriş tutarı, listedeki müşterinin alışveriş tutarından daha küçükse
    struct Cust *temp = (struct Cust*) malloc(sizeof(struct Cust));
    temp->name = custname;
    temp->amount = custamount;
    if(iter->next == NULL){//Eğer listede tek müşteri varsa, alışveriş tutarı kontrolünü daha önce yaptığımdan dolayı yeni müşteriyi, mevcut müşterinin hemen sonrasına ekliyorum.
      iter->next = temp;
      temp->next = NULL;
    }
    else{//Eğer listede tek müşteri yoksa
      while(iter->next != NULL){//Listedeki sondan bir önceki müşteriye kadar listeyi tarıyorum.
        if((iter->amount) > custamount){//Eğer yeni müşterinin alışveriş tutarı, o an seçtiğim müşterinin alışveriş tutarından daha küçükse
          if((iter->next->amount) < custamount){//ve sonraki müşterinin alışveriş tutarından daha büyükse aralarına ekliyorum.
            temp->next = iter->next;
            iter->next = temp;
            break;//ekleme işini yaptığım için while döngüsünü sonlandırıyorum.
          }
          iter = iter->next;//Daha büyük değilse bir sonraki elemana geçiyorum.
        }
        else{//Eğer yeni müşterinin alışveriş tutarı ile o an seçtiğim müşterinin alışveriş tutarı eşit ise hemen sonrasına ekleme yapıyor.
          temp->next = iter->next;
          iter->next = temp;
          break;
        }
      }
      if(iter->next == NULL && temp->next == NULL){//Eğer o an seçtiğim müşteri son müşteriyse ve henüz yeni müşteriyi yerleştiremediysem listenin en sonuna yerleştiriyorum.
        temp->next = iter->next;
        iter->next = temp;  
      }      
    }
  }
}

void printSortbyAmount(int listamount){
  printf("\nALISVERIS BEDELI %d'DEN BUYUK OLANLAR\n---------------------\n",listamount);
  struct Cust *listcust = SortbyAmount;
  while(listcust != NULL){
    if((listcust->amount) >= listamount){
      printf (" %s,%d \n", listcust->name, listcust->amount);
    }    
    listcust = listcust->next;
  }
}

void printSortbyName(char firsletter){
  printf("\nISMI %c ILE BASLAYANLAR\n---------------------\n",firsletter);
  struct Cust *listcust = SortbyName;
  while(listcust != NULL){
    char tempname = listcust->name[0];
    if(tempname == firsletter){
      printf (" %s,%d \n", listcust->name, listcust->amount);
    }    
    listcust = listcust->next;
  }
}
int main(void){
    AddCustomer("Ahmet", 100);
    AddCustomer("Bilal", 1000);
    AddCustomer("Cemal", 600);
    AddCustomer("Adem", 650);
    AddCustomer("Yasin", 350);
    AddCustomer("Esin", 270);
    AddCustomer("Emel", 410);
    AddCustomer("Mustafa", 750);
    AddCustomer("Ayten", 600);
    AddCustomer("Ceylan", 1000);
    AddCustomer("Nesrin", 900);
    AddCustomer("Bekir", 850);
    AddCustomer("Emin", 790);
    AddCustomer("Hakan", 610);
    AddCustomer("Hatice", 550);
    ///
    addnameindex("Ahmet", 100);
    addnameindex("Bilal", 1000);
    addnameindex("Cemal", 600);
    addnameindex("Adem", 650);
    addnameindex("Yasin", 350);
    addnameindex("Esin", 270);
    addnameindex("Emel", 410);
    addnameindex("Mustafa", 750);
    addnameindex("Ayten", 600);
    addnameindex("Ceylan", 1000);
    addnameindex("Nesrin", 900);
    addnameindex("Bekir", 850);
    addnameindex("Emin", 790);
    addnameindex("Hakan", 610);
    addnameindex("Hatice", 550);
    ///
    addamountindex("Ahmet", 100);
    addamountindex("Bilal", 1000);
    addamountindex("Cemal", 600);
    addamountindex("Adem", 650);
    addamountindex("Yasin", 350);
    addamountindex("Esin", 270);
    addamountindex("Emel", 410);
    addamountindex("Mustafa", 750);
    addamountindex("Ayten", 600);
    addamountindex("Ceylan", 1000);
    addamountindex("Nesrin", 900);
    addamountindex("Bekir", 850);
    addamountindex("Emin", 790);
    addamountindex("Hakan", 610);
    addamountindex("Hatice", 550);
    ///
    printSortbyAmount(900);
    printSortbyName('A');
    return 0;
}