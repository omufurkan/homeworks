class Shape
    attr_reader :x, :y
    def initialize(x, y)
        @x, @y = x, y
        puts "#{"*"*50}\n[INFO] #{self.class} şekli oluşturuldu\n#{"*"*50}"
    end

    def showScreen     
        raise NotImplementedError
    end

    def getInfo
        raise NotImplementedError
    end

    def area
        raise NotImplementedError  
    end

    def volume
        raise NotImplementedError
    end
end

class Shape2D < Shape
    def initialize(*coords)
        super *coords
    end

    def volume
        0
    end
end

class Shape3D < Shape2D
    attr_reader :z

    def initialize(*coords, z)
        super *coords
        @z = z
    end
end

class Square < Shape2D
    attr_reader :sideLength

    def initialize(*coords, sideLength)
        super *coords
        @sideLength = sideLength
    end

    def showScreen
        puts "Şekil merkez koordinatları: (#{self.x},#{self.y})",
            "Kenar uzunluğu: #{@sideLength}",
            "Alanı: #{area}",
            "Hacmi: #{volume}"
    end

    class << self
        def getInfo
            puts "KARE şekli için gerekli bilgileri giriniz: "
            coordsX = promptInt "X koordinatını giriniz: "
            coordsY = promptInt "Y koordinatını giriniz: "
            sideLength = promptInt "Kenar uzunluğunu giriniz(varsayılan 0): "
            x = Square.new coordsX,coordsY,sideLength
        end
    end

    def area
        @sideLength**2
    end
end

class Circle < Shape2D
    attr_reader :r

    def initialize(*coords, r)
        super *coords
        @r = r
    end

    def showScreen
        puts "Şekil merkez koordinatları: (#{self.x},#{self.y})",
            "Yarıçapı: #{@r}",
            "Alanı: #{area}",
            "Hacmi: #{volume}"
    end

    class << self
        def getInfo
            puts "ÇEMBER şekli için gerekli bilgileri giriniz: "
            coordsX = promptInt "X koordinatını giriniz: "
            coordsY = promptInt "Y koordinatını giriniz: "
            r = promptInt "Yarıçapı giriniz(varsayılan 0): "
            x = Circle.new coordsX,coordsY,r
        end
    end

    def area
        Math::PI * @r**2
    end
end

class Cube < Shape3D
    attr_reader :sideLength, :volumeBoost
    
    def initialize(*coords, sideLength, volumeBoost)
        super *coords
        @sideLength, @volumeBoost = sideLength, volumeBoost
    end

    def showScreen
        puts "Şekil merkez koordinatları: (#{self.x},#{self.y},#{self.z})",
            "Kenar uzunluğu: #{@sideLength}",
            "Alanı: #{area}",
            "Hacmi: #{volume}",
            "Yeni hacmi: #{volumeBst}"
    end

    class << self
        def getInfo
            puts "KÜP şekli için gerekli bilgileri giriniz: "
            coordsX = promptInt "X koordinatını giriniz: "
            coordsY = promptInt "Y koordinatını giriniz: "
            coordsZ = promptInt "Z koordinatını giriniz: "
            sideLength = promptInt "Kenar uzunluğunu giriniz(varsayılan 0): "
            volumeBoostValue = promptInt "Hacim artış değerini giriniz(Değer girmezseniz artış olmaz): "
            x = Cube.new coordsX,coordsY,coordsZ,sideLength,volumeBoostValue
        end
    end

    def area
        @sideLength**2 * 6
    end

    def volume
        @sideLength**3
    end

    def volumeBst
        volume * @volumeBoost
    end
end

class Sphere < Shape3D
    attr_reader :r, :volumeBoost

    def initialize(*coords, r, volumeBoost)
        super *coords
        @r, @volumeBoost = r, volumeBoost
    end

    def showScreen
        puts "Şekil merkez koordinatları: (#{self.x},#{self.y},#{self.z})",
            "Yarıçapı: #{@r}",
            "Alanı: #{area}",
            "Hacmi: #{volume}",
            "Yeni hacmi: #{volumeBst}"
    end

    class << self
        def getInfo
            puts "KÜRE şekli için gerekli bilgileri giriniz: "
            coordsX = promptInt "X koordinatını giriniz: " 
            coordsY = promptInt "Y koordinatını giriniz: "
            coordsZ = promptInt "Z koordinatını giriniz: "
            r = promptInt "Yarıçapı giriniz(varsayılan 0): "
            volumeBoostValue = promptInt "Hacim artış değerini giriniz(Değer girmezseniz artış olmaz): "
            x = Sphere.new coordsX,coordsY,coordsZ,r,volumeBoostValue
        end
    end

    def area
        4 * Math::PI * @r**2
    end

    def volume
        4 * Math::PI * @r**3 / 3
    end

    def volumeBst
        volume * @volumeBoost
    end
end

def prompt(*args)   #Tek satırda input almak için bu fonksiyonları kullanıyorum.
    print(*args)
    gets.chomp
end

def promptInt(*args)
    print(*args)
    gets.chomp.to_i
end

def xxxx
    puts "Kare --> KARE/kare",
        "Çember --> CEMBER/cember",
        "Küp --> KUP/kup",
        "Küre --> KURE/kure",
        "Çıkış --> CIKIS/cikis"

    case (prompt "\nŞEKLİ GİRİNİZ: ").downcase
    when "kare"        then x = Square.getInfo
    when "cember"      then y = Circle.getInfo
    when "kup"         then z = Cube.getInfo
    when "kure"        then t = Sphere.getInfo
    when "cikis"       then exit
    else
        abort "Tanımlanmayan şekil girildi."
    end
end

def main
    x, y, z, t = Square.getInfo, Circle.getInfo, Cube.getInfo, Sphere.getInfo
    [x, y, z, t].each do |shape|
        puts "\n#{shape.class} şekline ait bilgiler:\n#{"-"*50}"
        puts shape.showScreen
    end
end

main