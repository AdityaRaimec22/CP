class Rectangle:

    def __init__(self,l,h):
        self.length = l
        self.height = h
        
    def area(self):
        return self.length * self.height
    
    def is_square(self):
        if self.length == self.height:
            return "square"
        else:
            return "not square"
        
a = Rectangle(2,3)
print(a.area())
print(a.is_square())
        