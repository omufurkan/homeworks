#include <stdio.h>
#include <stdlib.h>

typedef struct Tower {
  int num;
  struct Tower *head;
  struct Tower *next;
}Tower;

Tower Tower1,Tower2,Tower3;//Boş kuleleri oluşturdum.
int N;//Başlangıç disk sayısı.
int numberofmoves = 0;//Hamle sayısını saymak için atadığım değişken.

void pushdisk(Tower *TowerNameA, int x){//Bu fonksiyon, fonksiyona argüman olarak gönderilen kuleye yine fonksiyona argüman olarak gönderilen numaralı diski ekliyor.
  if(TowerNameA == NULL){//Eğer kule boşsa direkt ekliyor
    TowerNameA = (struct Tower*)malloc(sizeof(struct Tower));
    TowerNameA->num = x;
    TowerNameA->next = NULL;
    TowerNameA->head = TowerNameA;//Kulenin tepesi eklenen disk oluyor
  }
  else{//Eğer kule boş değilse kulenin en tepesinden ekliyor.
    struct Tower *iter = TowerNameA;
    struct Tower *disk = (struct Tower*)malloc(sizeof(struct Tower));
    disk->num = x;
    disk->next = iter->head;//Kulenin bir altındaki disk, eski tepe diski oluyor.
    iter->head = disk;//ve kulenin yeni tepesi eklenen disk oluyor.
  }
}

int deletelastdisk(Tower *TowerName){//Bu fonksiyon, fonksiyona argüman olarak gönderilen kulenin tepesindeki diski siliyor.
  int k = TowerName->head->num;
  TowerName->head = TowerName->head->next;//Kulenin tepesindeki diski, kulenin tepesindeki diskin bir altındaki disk olarak tanımlıyorum.
  return k;//Bu değeri geri döndürmemin sebebi, diskleri bir kuleden başka bir kuleye taşırken taşınan diski tespit etmek. Bu değeri movedisk fonksiyonunda kullanıyorum.
}

void printTowers(){//Bu fonksiyon, tüm kuleleri ve üzerindeki diskleri ekrana yazdırıyor.
    if(numberofmoves != 0){
        printf("\n\n\n Hamle:%d\n",numberofmoves);
    }
    numberofmoves += 1;
    printf(" A   |   B   |   C\n-------------------\n");
    struct Tower *iter1 = &Tower1;
    struct Tower *iter2 = &Tower2;
    struct Tower *iter3 = &Tower3;
    int k = 0, l = 0, m = 0; //k: Tower1'deki disk sayısı, l: Tower2'deki disk sayısı, m: Tower3'deki disk sayısı
    if(iter1 != NULL){
        iter1 = iter1->head;
        struct Tower *itertemp = &Tower1;
        itertemp = itertemp->head;
        k = 0;
        while(itertemp != NULL){//Bu kod bloğu her A kulesindeki disk sayısını tespit ediyor ve k değişkenine aktarıyor.
            k += 1;
            itertemp = itertemp->next;
        }
    }
    if(iter2 != NULL){
        iter2 = iter2->head;
        struct Tower *itertemp = &Tower2;
        itertemp = itertemp->head;
        l = 0;
        while(itertemp != NULL){//Bu kod bloğu her B kulesindeki disk sayısını tespit ediyor ve l değişkenine aktarıyor.
            l += 1;
          itertemp = itertemp->next;
        }
    }
    if(iter3 != NULL){
        iter3 = iter3->head;
        struct Tower *itertemp = &Tower3;
        itertemp = itertemp->head;
        m = 0;
        while(itertemp != NULL){//Bu kod bloğu her C kulesindeki disk sayısını tespit ediyor ve m değişkenine aktarıyor.
            m += 1;
            itertemp = itertemp->next;
        }
    }
    for(int a = N; a > 0; a--){
        char disk1[5] = " ",disk2[5] = " ",disk3[5] = " ";
        if(iter1 != NULL && a <= k){//Bu if komutu, eğer A kulesinde bir veya birden çok disk varsa o diskleri alttan başlayarak, yukarıya doğru yazdırmayı sağlıyor.
            sprintf(disk1, "%d", iter1->num); 
            iter1 = iter1->next;
        }
        if(iter2 != NULL && a <= l){//Bu if komutu, eğer B kulesinde bir veya birden çok disk varsa o diskleri alttan başlayarak, yukarıya doğru yazdırmayı sağlıyor.
            sprintf(disk2, "%d", iter2->num);
            iter2 = iter2->next;
        }
        if(iter3 != NULL && a <= m){//Bu if komutu, eğer C kulesinde bir veya birden çok disk varsa o diskleri alttan başlayarak, yukarıya doğru yazdırmayı sağlıyor.
            sprintf(disk3, "%d", iter3->num);
            iter3 = iter3->next;
        }
        printf(" %s   |   %s   |   %s\n",disk1,disk2,disk3);//Kulerin her bir kademesini ekrana basıyorum.
    }
}

void movedisk(int num, Tower *A, Tower *B, Tower *C){//Hanoi kulesi sıralama fonksiyonu. Öz yinelemeli bir fonksiyon. Bu fonksiyon kaynak kuleden hedef kuleye, yardımcı kuleyi de kullanarak disk taşıma işlemi yapıyor. FONKSİYON ARGÜMAN FORMATI--> (disk sayısı, KAYNAK KULE, YARDIMCI KULE, HEDEF KULE)
    if(num > 0){
      movedisk(num - 1, A,C,B);//N tane diski kaynak kuleden hedef kuleye taşımak için öncelikle N. diskin üzerindeki n-1 tane diski yardımcı kuleye taşımalıyız. Burada n-1 tane diski kaynak kuleden yardımcı kuleye taşıyoruz. Bu taşıma işleminde geçiçi yardımcı kule olarak hedef kulesini kullanıyoruz.
      int d = deletelastdisk(A);
      pushdisk(C,d);//Bu kısımda N. diski kaynak kuleden hedef kuleye taşıyoruz.
      printTowers();//n-1 tane diski tekrar N. diskin üzerine taşıma işlemlerini de üstteki movedisk komutu yapacağı için bu adımları da ekranda göstermek için yazdırma fonksiyonunu burada çağırıyorum.
      movedisk(num - 1, B,A,C);//Burada ise yardımcı kuledeki n-1 tane diski, hedef kulesindeki N. diskin üzerine taşıyoruz. Bu taşıma işleminde geçici yardımcı kule olarak kaynak kulesini kullanıyoruz.
    }
}

int main(void) {  
  int startdisknum;
  printf("\nBaslangic icin kuleye eklenecek disk sayisini giriniz: ");
  scanf("%d",&startdisknum);  
  N = startdisknum;
  for(int x = N; x > 0; x--){//Bu for döngüsü A kulesine, başlangıçta girilen değer kadar disk ekliyor.
    pushdisk(&Tower1,x);
  }  
  printTowers();//Hamleler yapılmadan önce kulelerin durumları ekrana basılıyor.
  movedisk(N,&Tower1,&Tower2,&Tower3);//Taşıma işlemi yapılıyor.
  printf("\n--> %d disk toplam %d hamlede A kulesinden C kulesine tasindi.\n",N,numberofmoves - 1);//Taşıma işlemi bittiğinde ekrana disklerin kaç hamlede taşındığı yazılıyor.
  return 0;
}