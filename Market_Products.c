#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Meat {
  char productName[20];
  int price;
  char category;
  char type;
  char packingDate[11];
  char expirationDate[11];
  struct Meat *next;
}Meat;

typedef struct Agricultural {
  char productName[20];
  int price;
  char category;
  char type;
  char addDate[11];
  struct Agricultural *next;
}Agricultural;

typedef struct Milk {
  char productName[20];
  int price;
  char category;
  char expirationDate[11];
  struct Milk *next;
}Milk;

typedef struct Canned {
  char productName[20];
  int price;
  char category;
  char expirationDate[8];//Sadece ay ve yıl
  int aisleNumber;
  char aisleSide;
  struct Canned *next;
}Canned;

typedef struct NonFood {
  char productName[20];
  int price;
  char category;
  char type;
  int aisleNumber;
  char aisleSide;
  struct NonFood *next;
}NonFood;

Meat *MeatProducts;
Agricultural *AgriculturalProducts;
Milk *MilkProducts;
Canned *CannedProducts;
NonFood *NonFoodProducts;

void showProduct(char category){
  switch(category){
    case 'E':
      printf("\nEt ürünleri(E) kategorisi için kayıt altına alınacak bilgiler\n----------------------------------------------");
      printf("\n-> Et türünü gösteren karakter('R': Kırmızı Et, 'B': Balık, 'P': Tavuk)");
      printf("\n-> Paketleme tarihi(#-#-#)");
      printf("\n-> Son kullanma tarihi(#-#-#)\n\n");
      break;
    case 'T':
      printf("\nTarım ürünleri(T) kategorisi için kayıt altına alınacak bilgiler\n----------------------------------------------");
      printf("\n-> Tarım ürünü türünü gösteren karakter('M': Meyve, 'S': Sebze)");
      printf("\n-> Alınma tarihi(#-#-#)\n\n");
      break;
    case 'S':
      printf("\nSüt ürünleri(S) kategorisi için kayıt altına alınacak bilgiler\n----------------------------------------------");      
      printf("\n-> Son kullanma tarihi(#-#-#)\n\n");
      break;
    case 'K':
      printf("\nKonserve ürünleri(K) kategorisi için kayıt altına alınacak bilgiler\n----------------------------------------------");
      printf("\n-> Son kullanma tarihi(#-# -> Sadece ay ve yıl)");
      printf("\n-> Reyon numarası");
      printf("\n-> Reyon tarafı('A' ya da 'B')\n\n");
      break;
    case 'G':
      printf("\nGıda dışı ürünleri(G) kategorisi için kayıt altına alınacak bilgiler\n----------------------------------------------");
      printf("\n-> Türünü gösteren karakter('C': Temizlik ürünleri, 'P': Eczane), 'D': Diğer ürünler");
      printf("\n-> Reyon numarası");
      printf("\n-> Reyon tarafı('A' ya da 'B')\n\n");
      break;
    default:
      printf("Girdiğiniz kategori bulunamadı. Lütfen kayıtlı bir kategori sorgulayınız.\nKayıtlı kategoriler:('E': Et ürünleri, 'T': Tarım ürünleri, 'S': Süt ürünleri, 'K': Konserve ürünleri, 'G': Gıda dışı ürünleri)\n");
  }
}

void saveProduct(char inCategory, char inProductName[20], int inPrice){
  switch(inCategory){
    case 'E':
      printf("Et türünü giriniz(R,B,P): ");
      char inType = toupper(getchar());
      while ((getchar()) != '\n');//Input Buffer. Tampon bölgede kalan \n 'in klavyeden veri okumasına olanak vermemesi sorununu gidermek için klavyeden her veri girişi yapıldığında, bu bloğu ekledim.
      printf("Paketleme tarihini giriniz(#-#-#): ");
      char inPackingDate[11];
      scanf("%s",inPackingDate);
      while ((getchar()) != '\n');
      printf("Son kullanma tarihini giriniz(#-#-#): ");
      char inExpirationDate[11];
      scanf("%s",inExpirationDate);
      while ((getchar()) != '\n');
      if(MeatProducts == NULL){
        MeatProducts = (struct Meat*)malloc(sizeof(struct Meat));
        MeatProducts->category = inCategory;
        strcpy(MeatProducts->productName,inProductName);
        MeatProducts->price = inPrice;        
        MeatProducts->type = inType;
        strcpy(MeatProducts->packingDate,inPackingDate);
        strcpy(MeatProducts->expirationDate,inExpirationDate);
      }
      else{
        struct Meat *iter = MeatProducts;
        struct Meat *Products = (struct Meat*)malloc(sizeof(struct Meat));
        Products->category = inCategory;
        strcpy(Products->productName,inProductName);
        Products->price = inPrice;
        Products->type = inType;
        strcpy(Products->packingDate,inPackingDate);
        strcpy(Products->expirationDate,inExpirationDate);
        while(iter->next != NULL){
          iter = iter->next;
        }
        iter->next = Products;
      }
      break;
    case 'T':
      printf("Tarım ürünü türünü giriniz(M,S): ");
      char inType2 = toupper(getchar());
      while ((getchar()) != '\n'); 
      printf("Alınma tarihini giriniz(#-#-#): ");
      char inAddDate[11];
      scanf("%s",inAddDate);
      while ((getchar()) != '\n'); 
      if(AgriculturalProducts == NULL){
        AgriculturalProducts = (struct Agricultural*)malloc(sizeof(struct Agricultural));
        AgriculturalProducts->category = inCategory;
        strcpy(AgriculturalProducts->productName,inProductName);
        AgriculturalProducts->price = inPrice;        
        AgriculturalProducts->type = inType2;
        strcpy(AgriculturalProducts->addDate,inAddDate);
      }
      else{
        struct Agricultural *iter = AgriculturalProducts;
        struct Agricultural *Products = (struct Agricultural*)malloc(sizeof(struct Agricultural));
        Products->category = inCategory;
        strcpy(Products->productName,inProductName);
        Products->price = inPrice;
        Products->type = inType2;
        strcpy(Products->addDate,inAddDate);
        while(iter->next != NULL){
          iter = iter->next;
        }
        iter->next = Products;
      }
      break;
    case 'S':
      printf("Son kullanma tarihini giriniz(#-#-#): ");
      char inExpirationDate3[11];
      scanf("%s",inExpirationDate3);
      while ((getchar()) != '\n');
      if(MilkProducts == NULL){
        MilkProducts = (struct Milk*)malloc(sizeof(struct Milk));
        MilkProducts->category = inCategory;
        strcpy(MilkProducts->productName,inProductName);
        MilkProducts->price = inPrice;        
        strcpy(MilkProducts->expirationDate,inExpirationDate3);
      }
      else{
        struct Milk *iter = MilkProducts;
        struct Milk *Products = (struct Milk*)malloc(sizeof(struct Milk));
        Products->category = inCategory;
        strcpy(Products->productName,inProductName);
        Products->price = inPrice;
        strcpy(Products->expirationDate,inExpirationDate3);
        while(iter->next != NULL){
          iter = iter->next;
        }
        iter->next = Products;
      }
      break;
    case 'K':
      printf("Son kullanma tarihini giriniz(#-# -> ay-yıl): ");
      char inExpirationDate4[11];
      scanf("%s",inExpirationDate4);
      while ((getchar()) != '\n'); 
      printf("Reyon numarasını giriniz: ");
      int inAisleNum;
      scanf("%d",&inAisleNum);      
      while ((getchar()) != '\n'); 
      printf("Reyon tarafını giriniz(A,B): ");
      char inAisleSide = toupper(getchar());
      while ((getchar()) != '\n'); 
      if(CannedProducts == NULL){
        CannedProducts = (struct Canned*)malloc(sizeof(struct Canned));
        CannedProducts->category = inCategory;
        strcpy(CannedProducts->productName,inProductName);
        CannedProducts->price = inPrice;        
        strcpy(CannedProducts->expirationDate,inExpirationDate4);        
        CannedProducts->aisleNumber = inAisleNum;        
        CannedProducts->aisleSide = inAisleSide;
      }
      else{
        struct Canned *iter = CannedProducts;
        struct Canned *Products = (struct Canned*)malloc(sizeof(struct Canned));
        Products->category = inCategory;
        strcpy(Products->productName,inProductName);
        Products->price = inPrice;
        strcpy(Products->expirationDate,inExpirationDate4);
        Products->aisleNumber = inAisleNum;
        Products->aisleSide = inAisleSide;
        while(iter->next != NULL){
          iter = iter->next;
        }
        iter->next = Products;
      }
      break;
    case 'G':      
      printf("Gıda dışı ürünü türünü giriniz(C,P,D): ");
      char inType3 = toupper(getchar());
      while ((getchar()) != '\n'); 
      printf("Reyon numarasını giriniz: ");
      int inAisleNum2;
      scanf("%d",&inAisleNum2);
      while ((getchar()) != '\n');
      printf("Reyon tarafını giriniz(A,B): ");
      char inAisleSide2 = toupper(getchar());
      while ((getchar()) != '\n'); 
      if(NonFoodProducts == NULL){
        NonFoodProducts = (struct NonFood*)malloc(sizeof(struct NonFood));
        NonFoodProducts->category = inCategory;
        strcpy(NonFoodProducts->productName,inProductName);
        NonFoodProducts->price = inPrice;        
        NonFoodProducts->type = inType3; 
        NonFoodProducts->aisleNumber = inAisleNum2;        
        NonFoodProducts->aisleSide = inAisleSide2;
      }
      else{
        struct NonFood *iter = NonFoodProducts;
        struct NonFood *Products = (struct NonFood*)malloc(sizeof(struct NonFood));
        Products->category = inCategory;
        strcpy(Products->productName,inProductName);
        Products->price = inPrice;
        Products->type = inType3;
        Products->aisleNumber = inAisleNum2;
        Products->aisleSide = inAisleSide2;
        while(iter->next != NULL){
          iter = iter->next;
        }
        iter->next = Products;
      }
      break;    
  }
}

void listProduct(){
  struct Meat *Meatiter = MeatProducts;
  struct Agricultural *Agriiter = AgriculturalProducts;
  struct Milk *Milkiter = MilkProducts;
  struct Canned *Cannediter = CannedProducts;
  struct NonFood *NonFooditer = NonFoodProducts;
  int num = 1;
  printf("\n\n------######------KAYITLI ÜRÜNLER------######------\n---------------------------------------------------\n");
  while(Meatiter != NULL){
    printf("%d. ürün : %c | %s | %d | %c | %s | %s\n",num,Meatiter->category,Meatiter->productName,Meatiter->price,Meatiter->type,Meatiter->packingDate,Meatiter->expirationDate);
    num +=1;
    Meatiter = Meatiter->next;
  }
  while(Agriiter != NULL){
    printf("%d. ürün : %c | %s | %d | %c | %s\n",num,Agriiter->category,Agriiter->productName,Agriiter->price,Agriiter->type,Agriiter->addDate);
    num +=1;
    Agriiter = Agriiter->next;
  }
  while(Milkiter != NULL){
    printf("%d. ürün : %c | %s | %d | %s \n",num,Milkiter->category,Milkiter->productName,Milkiter->price,Milkiter->expirationDate);
    num +=1;
    Milkiter = Milkiter->next;
  }
  while(Cannediter != NULL){
    printf("%d. ürün : %c | %s | %d | %s | %d | %c\n",num,Cannediter->category,Cannediter->productName,Cannediter->price,Cannediter->expirationDate,Cannediter->aisleNumber,Cannediter->aisleSide);
    num +=1;
    Cannediter = Cannediter->next;
  }
  while(NonFooditer != NULL){
    printf("%d. ürün : %c | %s | %d | %c | %d | %c\n",num,NonFooditer->category,NonFooditer->productName,NonFooditer->price,NonFooditer->type,NonFooditer->aisleNumber,NonFooditer->aisleSide);
    num +=1;
    NonFooditer = NonFooditer->next;
  }
}

int main(void){
  showProduct('E');
  showProduct('T');
  showProduct('S');
  showProduct('K');
  showProduct('G');
  printf("--> Kaç adet ürün girmek istiyorsunuz: ");
  int x;
  scanf("%d",&x);
  while ((getchar()) != '\n');
  for(int i = 0; i < x; i++){
    printf("\n----------/ %d. Ürün Girişi /----------\n",i+1);
    printf("Ürün kategorisini seçiniz(E,T,S,K,G): ");
    char prodCategory = toupper(getchar());
    while ((getchar()) != '\n'); 
    printf("Ürün adını giriniz: ");
    char prodName[20];
    scanf("%s",prodName);
    while ((getchar()) != '\n'); 
    printf("Ürünün TL cinsinden birim maliyetini giriniz: ");
    int prodPrice;
    scanf("%d",&prodPrice);
    while ((getchar()) != '\n');
    saveProduct(prodCategory,prodName,prodPrice);
  }
  listProduct();
}