class Point:

    def __init__(self,x,y):
        self.x_cod = x
        self.y_cod = y

    def __str__(self):
        return '<{},{}>'.format(self.x_cod,self.y_cod)
    
# obj = LineObj(2,4)
# print(obj)
 
    def Distance(self,other):
        return ((self.x_cod - other.x_cod)**2 + (self.y_cod - other.y_cod)**2)**0.5
    
# p1 = LineObj(0,0)
# p2 = LineObj(6,8)
# print(p1.Distance(p2))

class Line:

    def __init__(self,A,B,C):
        self.A = A
        self.B = B
        self.C = C
        
    def __str__(self):
        return '{}x + {}y + {} = 0'.format(self.A,self.B,self.C)

    def Point_on_line(line,point):
        if line.A * point.x_cod + line.B * point.y_cod + line.C == 0:
            return "the point lies on the Line"
        else:
            return "The point does not lie on the line"
            
        
l1 = Line(1,2,3)
p1 = Point(3,4)
print(l1)
print(p1)
print(l1.Point_on_line(p1))


        
        

    
        