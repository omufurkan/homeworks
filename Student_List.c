#include <stdio.h>

int students[15][2] = {{18060311,40},{20060045,50},{19061091,75},{20060134,90},{20060678,40},{18061086,75},{20060032,50},{20060067,60},{19060456,60},{18060245,75},{20060110,40},{20060234,90},{20060141,60},{20060011,50},{20060012,60}};

int myindex[15];
int numberofstudents = 0; //Öğrenci ekleme ve silme işlemlerinde, students dizisiyle işleme girmek için öğrenci sayısı verisini tutuyorum.

void sortindexlist(int studentslist[15][2]){ 
    //Burada i değişkeni ile bir öğrenci seçiyorum.
    for (int i = 0; i < numberofstudents; i++){
        //Burada j değişkeni ile, i değişkeniyle seçtiğim her bir öğrenci için diğer bütün öğrencileri kontrol ediyorum.
        for (int j = 0; j < numberofstudents; j++){
            if (students[myindex[i]][1] > students[myindex[j]][1]){
                int tempindex = myindex[i];
                myindex[i] = myindex[j];
                myindex[j] = tempindex;
            }
            else if(students[myindex[i]][1] == students[myindex[j]][1]){
                if (students[myindex[i]][0] < students[myindex[j]][0]){
                    int tempindex = myindex[i];
                    myindex[i] = myindex[j];
                    myindex[j] = tempindex;
                }
                else{
                    continue;
                }
            }            
        }
    }
}

void addstudents(int studentslist[15][2]){
    for(int i = 0; i < 15; i++){//Burada öncelikle bir öğrenci seçiyorum
        int tempque = 0;//Burada ilk değer atamasını bazı derleyicilerde karşılaştığım segmentation fault hatasından dolayı yapıyorum.
        for(int j = 0; j < numberofstudents; j++){//Seçtiğim öğrenci için, index dizisine eklenmiş tüm öğrencileri tarıyorum.
            if(studentslist[i][1] > studentslist[myindex[j]][1]){
                tempque = j;
                break;
            }
            else if(studentslist[i][1] == studentslist[myindex[j]][1]){
                if(studentslist[i][0] < studentslist[myindex[j]][0]){
                    tempque = j;
                    break;
                }
                else if(studentslist[i][0] > studentslist[myindex[j]][0] && j == numberofstudents - 1){//Buradaki kontrol seçtiğim öğrencinin puanı, index dizisindeki son öğrencinin puanına eşit olup numarasının büyük olması durumunda en sona ekleme işlemi yapıyor.
                    tempque = j + 1;
                }
            }
        }
        for(int x = numberofstudents; x > tempque; x--){//Bu kısımda index dizisini, yeni öğrenciyi ekleyeceğim yerden itibaren bir sıra ileri kaydırıyor.
            myindex[x] = myindex[x - 1];
        } 
        myindex[tempque] = i;
        numberofstudents += 1; 
    }   
}

void deletestudent(int studentslist[15][2], int studentnumber){
    //Burada öncelikle öğrenci numarası verilen öğrenciyi listede arıyorum. Eğer bu öğrenci listede varsa, myindex dizisinde bu öğrencinin indexinden sonraki indexleri bir sıra geriye kaydırıyorum.    
    for(int i = 0; i < numberofstudents; i++){
        if(studentnumber == studentslist[myindex[i]][0]){
            for(int x = i; x < numberofstudents; x++ ){
                myindex[x] = myindex[x + 1];
            }
            numberofstudents -= 1;
        }
    }

}

void updatestudent(int studentslist[15][2], int studentnumber, int newscore){
    for(int i = 0; i < numberofstudents; i++){
        if(studentnumber == studentslist[myindex[i]][0]){
            studentslist[myindex[i]][1] = newscore;
            sortindexlist(students);//Burada öğrencinin verisini güncelleyip index dizisini yeniden sıralatıyorum.
        }
    }
}

void liststudent(int studentslist[15][2],int soughtscore){
    printf("\nINDEX - OKUL NUMARASI - PUAN\n-------------------------------\n");
    for(int i = 0; i < numberofstudents;i++){
        if(studentslist[myindex[i]][1] > soughtscore){ //Yalnızca aranan puandan yüksek olan öğrencileri listele
            if(myindex[i] > 9){//Buradaki if komutu, yalnızca çıktının komut isteminde daha düzgün görünmesi içindir. Tek haneli indis numarasına sahip satırların başına bir boşluk karakteri ekliyor.
                printf(" %d       %d       %d\n",myindex[i],students[myindex[i]][0],students[myindex[i]][1]);
            }
            else{
                printf("  %d       %d       %d\n",myindex[i],students[myindex[i]][0],students[myindex[i]][1]);//İlk %d ifadesinin başında bir boşluk karakteri var.
            }
        }
    }
}


int main(void){
    addstudents(students);
    //deletestudent(students,19060456);    
    //updatestudent(students,20060067,95);
    //liststudent(students,60);
    liststudent(students,0);
    return 0; 
}
