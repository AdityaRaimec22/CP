# class rectangle:

#     def __init__(self,x,y):
#         self.len = x
#         self.wid = y
#         self.peri = self.perimeter()
#         self.are = self.area()

#     def perimeter(self):
#         peri = 2*self.len + 2*self.wid
#         return peri

#     def area(self):
#         are = self.len * self.wid
#         return are

# my_rectangle = rectangle(3,4)
# # my_rectangle.display()

class Rectangle:
    def __init__(self, x, y):
        self.len = x
        self.wid = y
        self.para = 0
        self.ara = 0
        # print('the length of the rectangle is: ',x)
        # print('the width of the rectangle is: ',y)
        self.perimeter()
        self.area()

    def perimeter(self):
        peri = 2 * self.len + 2 * self.wid
        self.para = peri
        # print('the perimeter of the ractangle is: ',peri)

    def area(self):
        are = self.len * self.wid
        self.ara = are
        # print('the area os rectangle is: ',are)
        # return are

    def dispay(self):
        length = self.len
        width = self.wid
        perimeter = self.para
        area = self.ara
        print('the length of the rectangle is: ',length)
        print('the width of the rectangle is: ',width)
        print('The perimeter of the rectanle is: ',perimeter)
        print('the area of the rectangle is: ',area)
        # print()

    
my_rectangle = Rectangle(3, 4)
my_rectangle.dispay()
