class Hastane_Ilac
    @@toplamIlacTuru = 0
    @@toplamStokSayisi = 0
    attr_reader :barkodNo, :ilacAdi, :ilacTürü, :ilacUreticiFirma, :ilacStokSayisi, :ilacBirimi

    def initialize(barkodNo, ilacAdi, ilacTürü, ilacUreticiFirma, ilacStokSayisi, ilacBirimi)
        @@toplamIlacTuru += 1
        @@toplamStokSayisi += ilacStokSayisi
        @barkodNo = barkodNo
        @ilacAdi = ilacAdi
        @ilacTürü = ilacTürü
        @ilacUreticiFirma = ilacUreticiFirma
        @ilacStokSayisi = ilacStokSayisi
        @ilacBirimi = ilacBirimi
    end

    def self.toplamIlacTuru
        @@toplamIlacTuru
    end

    def self.toplamStokSayisi
        @@toplamStokSayisi
    end
end

def main
    depo = []
    puts 'Ondokuz Mayıs Üniversitesi Tıp Fakültesi Hastane Bilgi Sistemine Hoş Geldiniz'
    loop do
        print "\nLütfen bir komut giriniz(EKLE, LISTELE, CIKIS): "
        komut = gets.chomp.upcase
        puts "\n"
        if komut == 'EKLE'             
            print 'Ilac barkod numarasi: '
            i_barkod = gets.chomp
            print 'Ilac adi: '
            i_ilacAdi = gets.chomp
            print 'Ilac türü: '
            i_ilacTürü = gets.chomp
            print 'Ilac üretici firmasi: '
            i_ilacUreticiFirma = gets.chomp
            print 'Ilac stok sayisi: '
            i_ilacStokSayisi = gets.chomp.to_i
            print 'Ilac birimi: '
            i_ilacBirimi = gets.chomp
            depo << i_ilacAdi            
            depo[-1] = Hastane_Ilac.new(i_barkod,i_ilacAdi,i_ilacTürü,i_ilacUreticiFirma,i_ilacStokSayisi,i_ilacBirimi)
        elsif komut == 'LISTELE'
            x = 1
            depo.each do |ilac|
                puts "Ilac #{x}: ###  Barkod no: #{ilac.barkodNo}  ###  Ilac adi: #{ilac.ilacAdi}  ###  Ilac türü: #{ilac.ilacTürü}  ###  Ilac üretici firmasi: #{ilac.ilacUreticiFirma}  ###  Ilac stok sayisi #{ilac.ilacStokSayisi}  ###  Ilac birimi: #{ilac.ilacBirimi}"
                x += 1
            end
            puts "\nDepoda toplam #{Hastane_Ilac.toplamIlacTuru} ilac türü bulunmaktadir. Ayrıca toplam ilac stok sayısı #{Hastane_Ilac.toplamStokSayisi} adettir."
        elsif komut == 'CIKIS'
            puts 'Güle Güle'
            exit
        else
            puts 'Hatalı bir komut girdiniz'
        end
    end
end

main