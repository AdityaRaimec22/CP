import numpy as np

class Student:

    def __init__(self,student_id,marks,age):
        self.__student_id = student_id
        self.__marks = marks
        self.__age = age

    def get_student_id(self):
        return self.__student_id
    
    def set_student_id(self, student_id):
        self.__student_id = student_id
        
    def get_age(self):
        return self.__age
    
    def set_age(self, age):
        self.__age = age
        
    def get_marks(self):
        return self.__marks
    
    def set_marks(self, marks):
        self.__marks = marks
    # def set_data(self):
    #     self.__id = 
    #     pass

    def validate_marks(self):
        if self.__marks >= 0 and self.__marks <= 100:
            return True
        else:
            return False
        
    def validate_age(self):
        if self.__age > 20:
            return True
        else:
            return False
        
    def check_qualificaion(self):
        if self.__marks>= 65 and self.__age>20: 
            return True
        else:
            return False
        
s = Student(12345,25,15)
print(s.check_qualificaion())
print(s.validate_age())
print(s.validate_marks())



    
