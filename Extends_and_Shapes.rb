class Shape
    NAME = 'SHAPE'
    attr_reader :x, :y

    def initialize(x, y)
        @x, @y = x, y
        puts "#{"*"*50}\n[INFO] #{self.class.superclass.name}, #{self.class.name} shape created.\n#{"*"*50}\n"   #Polymorphism
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

    class << self
        def name
            NAME
        end
    end
end

class Shape2D < Shape
    NAME = 'TWO-DIMENSIONAL'

    def initialize(*coords)
        super(*coords)
    end

    def volume
        0
    end

    class << self
        def name
            NAME
        end
    end
end

class Shape3D < Shape2D
    NAME = 'THREE-DIMENSIONAL'
    attr_reader :z

    def initialize(*coords, z)
        super(*coords)
        @z = z
    end

    class << self
        def name
            NAME
        end
    end
end

class Square < Shape2D
    NAME = 'SQUARE'
    attr_reader :sideLength

    def initialize(*coords, sideLength)
        super(*coords)
        @sideLength = sideLength
    end

    def showScreen
        puts "Shape center coordinates: (#{self.x},#{self.y})",
            "Side length: #{@sideLength}",
            "Area: #{area}",
            "Volume: #{volume}"
    end

    class << self
        def getInfo
            puts "Enter the required information for the #{self.name} shape: "
            coordsX = promptInt "Enter the X coordinate: "
            coordsY = promptInt "Enter the Y coordinate: "
            sideLength = promptInt "Enter the side length (Default: 0): "
            [coordsX,coordsY,sideLength]    #I have returned the information I got from the user in the form of an array to use in the createObject method and elsewhere.
        end

        def createObject(args)  #I created and returned a Square object with the values given as arguments.
            Square.new(*args) if args.length == 3   #The initialize method of the Square class must take 3 arguments. #FIXME-> Number 3 be updated every time the initialize method is updated?
        end

        def name
            NAME
        end
    end

    def area
        @sideLength**2
    end
end

class Circle < Shape2D
    NAME = 'CIRCLE'
    attr_reader :r

    def initialize(*coords, r)
        super(*coords)
        @r = r
    end

    def showScreen
        puts "Shape center coordinates: (#{self.x},#{self.y})",
            "Radius: #{@r}",
            "Area: #{area}",
            "Volume: #{volume}"
    end

    class << self
        def getInfo
            puts "Enter the required information for the #{self.name} shape: "
            coordsX = promptInt "Enter the X coordinate: "
            coordsY = promptInt "Enter the Y coordinate: "
            r = promptInt "Enter the radius(Default: 0): "
            [coordsX,coordsY,r]
        end

        def createObject(args)
            Circle.new(*args) if args.length == 3
        end

        def name
            NAME
        end
    end

    def area
        Math::PI * @r**2
    end
end

class Cube < Shape3D
    NAME = 'CUBE'
    attr_reader :sideLength, :volumeBoost
    
    def initialize(*coords, sideLength, volumeBoost)
        super(*coords)
        @sideLength, @volumeBoost = sideLength, volumeBoost
    end

    def showScreen
        puts "Shape center coordinates: (#{self.x},#{self.y},#{self.z})",
            "Side length: #{@sideLength}",
            "Area: #{area}",
            "Volume: #{volume}",
            "New volume: #{volumeBst}"
    end

    class << self
        def getInfo
            puts "Enter the required information for the #{self.name} shape: "
            coordsX = promptInt "Enter the X coordinate: "
            coordsY = promptInt "Enter the Y coordinate: "
            coordsZ = promptInt "Enter the Z coordinate: "
            sideLength = promptInt "Enter the side length (Default: 0): "
            volumeBoostValue = promptInt "Enter the volume increment value (If you do not enter a value, there will be no increase): "
            [coordsX,coordsY,coordsZ,sideLength,volumeBoostValue]
        end

        def createObject(args)
            Cube.new(*args) if args.length == 5
        end

        def name
            NAME
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
    NAME = 'SPHERE'
    attr_reader :r, :volumeBoost

    def initialize(*coords, r, volumeBoost)
        super(*coords)
        @r, @volumeBoost = r, volumeBoost
    end

    def showScreen
        puts "Shape center coordinates: (#{self.x},#{self.y},#{self.z})",
            "Radius: #{@r}",
            "Area: #{area}",
            "Volume: #{volume}",
            "New volume: #{volumeBst}"
    end

    class << self
        def getInfo
            puts "Enter the required information for the #{self.name} shape: "
            coordsX = promptInt "Enter the X coordinate: " 
            coordsY = promptInt "Enter the Y coordinate: "
            coordsZ = promptInt "Enter the Z coordinate: "
            r = promptInt "Enter the radius(Default: 0): "
            volumeBoostValue = promptInt "Enter the volume increment value (If you do not enter a value, there will be no increase): "
            [coordsX,coordsY,coordsZ,r,volumeBoostValue]
        end

        def createObject(args)
            Sphere.new(*args) if args.length == 5
        end

        def name
            NAME
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

def prompt(*args)   #I am using these functions to get input in one line.
    print(*args)
    gets.chomp
end

def promptInt(*args)
    print(*args)
    gets.chomp.to_i
end

def createAShape
    puts "Square --> SQUARE/square",
        "Circle --> CIRCLE/circle",
        "Cube --> CUBE/cube",
        "Sphere --> SPHERE/sphere",
        "Exit --> EXIT/exit"
    
    case (prompt "\nŞEKLİ GİRİNİZ: ").downcase  #This method object returns --> x = createAShape
    when "square"     then Square.createObject(Square.getInfo)
    when "circle"   then Circle.createObject(Circle.getInfo)
    when "cube"      then Cube.createObject(Cube.getInfo)
    when "sphere"     then Sphere.createObject(Sphere.getInfo)
    when "exit"    then exit
    else
        abort "Unidentified shape entered!"
    end
end

def main
    # x = createAShape          #->It can be used if you want to create a single shape.
    # x.showScreen

    x, y, z, t = Square.createObject(Square.getInfo), Circle.createObject(Circle.getInfo), Cube.createObject(Cube.getInfo), Sphere.createObject(Sphere.getInfo)
    [x, y, z, t].each do |shape|    #Shape çok biçimli davranır.
        puts "\n#{shape.class.superclass.name}, #{shape.class.name} shape information:\n#{"-"*50}"
        puts shape.showScreen
    end
end

main