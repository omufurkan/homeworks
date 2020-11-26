#include <stdio.h>

int kelimebul(char array[],int kelimeuzunlugu){
    int bulunankelimesayisi = 0, temp = 0, i = 0;
    while(array[i] != '\0'){
        if(array[i] != ' ' && array[i] != ',' && array[i] != '.' && array[i] != '(' && array[i] != ')' && array[i] != '-' && array[i] != '_'){//Eğer dizinin seçilen elemanı boşluk virgül nokta vs. değil ise (Bunun sebebi örneğin "merhaba," kelimesini virgül karakterinden dolayı 7 harf yerine 8 harf gibi görmesini engellemek)
            temp += 1;//Geçici kelime uzunluğunu bir arttır
        }
        else{
            if(temp == kelimeuzunlugu){//Eğer ki o eleman boşluk virgül nokta vs. ise kelime bitmiştir. Yani temp bizim kelime sayımızdır. Kelime sayısı bizim aradığımız kelime sayısına eşit ise aradığımız kelimeden bir tane bulduk.
                bulunankelimesayisi += 1;
            }
            temp = 0;//Geçici kelime sayısını sıfırlayıp taramaya devam ediyoruz.
        }
        i += 1;
    }
    return bulunankelimesayisi;
}

int main(){
    char charArray [] = "A computer is a machine that can be instructed to carry out sequences of arithmetic or logical operations automatically via computer programming.Modern computers have the ability to follow generalized sets of operations, called programs.These programs enable computers to perform an extremely wide range of tasks.A complete computer including the hardware, the operating system (main software), and peripheral equipment required and used for full operation can be referred to as a computer system.This term may as well be used for a group of computers that are connected and work together, in particular a computer network or computer cluster. Computers are used as control systems for a wide variety of industrial and consumer devices.This includes simple special purpose devices like microwave ovens and remote controls, factory devices such as industrial robots and computer-aided design, and also general purpose devices like personal computers and mobile devices such as smartphones.The Internet is run on computers and it connects hundreds of millions of other computers and their users.Early computers were only conceived as calculating devices.Since ancient times, simple manual devices like the abacus aided people in doing calculations.Early in the Industrial Revolution, some mechanical devices were built to automate long tedious tasks, such as guiding patterns for looms.More sophisticated electrical machines did specialized analog calculations in the early 20th century.";
    printf("\n");
    int i = 0;
    while(charArray[i] != '\0'){
        printf("%c",charArray[i]);
        i += 1;
    }
    int istenenkelimeuzunlugu;
    printf("\n\nBir kelime uzunlugu giriniz: ");
    scanf("%d",&istenenkelimeuzunlugu);
    if(istenenkelimeuzunlugu != 0 && istenenkelimeuzunlugu > 0 && istenenkelimeuzunlugu < 30){
        printf("\nMetinde %d uzunlugunda %d adet kelime bulundu.\n",istenenkelimeuzunlugu,kelimebul(charArray,istenenkelimeuzunlugu));
    }
    else{
        printf("Lutfen 1 ile 100 arasinda bir kelime uzunlugu giriniz");
    }    
}