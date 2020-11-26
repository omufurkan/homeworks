#include <stdio.h>
#include <ctype.h> 

void metinyazdir(char array[]){
    printf("\n");
    int a = 0;
    while(array[a] != '\0'){
        printf("%c",array[a]);
        a += 1;
    }
}
void maxseslisayisi(char array[]){
    char sesliler[] = {'A','E','I','O','U',};
    char maxsesli = 'A';
    int maxseslisayisi = 0;
    int i = 0;
    int b = 0;
    while(b < 6){//Burada kısaca yaptığım şey; Tüm sesli harfler için metni birer kez taramak. Bir sesli harften metinde kaç tane bulunduğunu tespit edip en çok kullanılan sesli harfi ve sayısını bulmak.
        int temp = 0;
        while(array[i] != '\0'){
            if(array[i] == sesliler[b] || array[i] == tolower(sesliler[b])){//Dizideki o an okunan eleman sesli harf ise (büyük veya küçük harf olabilir)
                temp += 1;//Seçilen sesli harften bulunma sayısını bir arttır.
            }
            i += 1;
        }
        if(temp > maxseslisayisi){//Eğer ki seçilen sesli harften bulunma sayısı, tespit edilen, metinde en çok bulunan sesli harf sayısından daha fazla ise
            maxsesli = sesliler[b];//Metinde en çok bulunan sesli harf şuanda seçilen harftir
            maxseslisayisi = temp;//Metindeki sayısı da şuanda bulunan sayıdır.
        }
        b += 1;
        i = 0;
    }
    printf ("\n\nMetinde en cok %c sesli harfi bulunmaktadir.(%d adet).\n",maxsesli,maxseslisayisi);
}
void maxsessizsayisi(char array[]){//Sessiz harf sayısı tespiti için de sesli harf tespiti için yapılanların aynısı geçerli. Yalnızca metinde taranan harfler farklı.
    char sessizler[] = {'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};
    char maxsessizharf = 'B';
    int maxsessizsayisi = 0;
    int i = 0;
    int b = 0;
    while(b < 22){
        int temp = 0;
        while(array[i] != '\0'){
            if(array[i] == sessizler[b] || array[i] == tolower(sessizler[b])){
                temp += 1;
            }
            i += 1;
        }
        if(temp > maxsessizsayisi){
            maxsessizharf = sessizler[b];
            maxsessizsayisi = temp;
        }
        b += 1;
        i = 0;
    }
    printf ("Metinde en cok %c sessiz harfi bulunmaktadir.(%d adet).\n",maxsessizharf,maxsessizsayisi);
}
void kactanevar(char array[],char inchar){//Burada ise yalnızca kullanıcının verdiği harfi metinde tarayıp sayısını buluyoruz.    
    int total = 0;
    int i = 0;    
    while(array[i] != '\0'){
        if(array[i] == inchar || array[i] == tolower(inchar) || array[i] == toupper(inchar)){
            total += 1;
        }
        i += 1;
    }
    printf("Girdiginiz harf(%c) metinde %d kere kullanilmis.\n",inchar,total);
}

int main(){
    char charArray [] = "A computer is a machine that can be instructed to carry out sequences of arithmetic or logical operations automatically via computer programming.Modern computers have the ability to follow generalized sets of operations, called programs.These programs enable computers to perform an extremely wide range of tasks.A complete computer including the hardware, the operating system (main software), and peripheral equipment required and used for full operation can be referred to as a computer system.This term may as well be used for a group of computers that are connected and work together, in particular a computer network or computer cluster. Computers are used as control systems for a wide variety of industrial and consumer devices.This includes simple special purpose devices like microwave ovens and remote controls, factory devices such as industrial robots and computer-aided design, and also general purpose devices like personal computers and mobile devices such as smartphones.The Internet is run on computers and it connects hundreds of millions of other computers and their users.Early computers were only conceived as calculating devices.Since ancient times, simple manual devices like the abacus aided people in doing calculations.Early in the Industrial Revolution, some mechanical devices were built to automate long tedious tasks, such as guiding patterns for looms.More sophisticated electrical machines did specialized analog calculations in the early 20th century.";
    int karaktersayisi = 0, bosluksayisi = 0;
    int i = 0;
    while(charArray[i] != ('\0')){
        if(charArray[i] == ' '){
            bosluksayisi += 1;
        }
        else{
            karaktersayisi += 1;
        }
        i += 1;
    }
    metinyazdir(charArray);
    printf("\n\nMetinde %d tane bosluk, %d tane diger karakter kullanilmistir. Toplam karakter sayisi %d'dir.\n",bosluksayisi,karaktersayisi,bosluksayisi+karaktersayisi);
    maxseslisayisi(charArray);
    maxsessizsayisi(charArray);
    char girilenharf;
    printf("\nBir harf girin: ");
    scanf("%c",&girilenharf);
    kactanevar(charArray,girilenharf);
}