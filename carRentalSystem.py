class Car:

    def __init__(self,Car_Id,Car_Model,Car_Make,Car_Year,Car_RentalPrice_perDay):
        self.Car_Id = []
        self.Car_Model = []
        self.Car_Make = []
        self.Car_Year = []
        self.Car_RentalPrice_perDay = []
        for i in range (0,len(Car_Id)):
            self.Car_Id.append(Car_Id[i])
            self.Car_Model.append(Car_Model[i])
            self.Car_Make.append(Car_Make[i])
            self.Car_Year.append(Car_Year[i])
            self.Car_RentalPrice_perDay.append(Car_RentalPrice_perDay[i])
        
class Customer(Car):

    def __init__(self,Customer_Id):
        self.Customer_Id = Customer_Id

class CarRentalSystem(Car):

    def __init__(self,Car_Id,Car_Model,Car_Make,Car_Year,Car_RentalPrice_perDay):
        super().__init__(Car_Id,Car_Model,Car_Make,Car_Year,Car_RentalPrice_perDay)
        self.Customer_Name = []
        self.Rented_cars_Id = []
        self.Rented_cars_Make = []
        self.Rented_cars_Model = []
        self.menu()
        
    def menu(self):
        user_input = input("""
        Welcome to Car Rental System!
        1. Display available cars for rent
        2. Rent a car
        3. Return a car
        4. Display the list of rented cars
        5. Display the total revenue
        6. Exit
        Input NUmber Here: """)

        if user_input == '1':
            self.Car_Info()
            
        elif user_input == '2':
            self.Rent_Car()

        elif user_input == '3':
            self.Return_car()

        elif user_input == '4':
            self.Rented_Cars()

        elif user_input == '5':
            self.Total_revenue()

        else:
            exit()

    def Car_Info(self):
        for i in range(0,len(self.Car_Id)):
            print(f"{i+1}, Car Id: {self.Car_Id[i]}, Car Make: {self.Car_Make[i]}, Car Model: {self.Car_Model[i]}, Car Year: {self.Car_Year[i]}, Car rental Price Per day: ${self.Car_RentalPrice_perDay[i]}")
        self.menu()

    def Rent_Car(self):
        self.Customer_Name = []
        CustomerName = input("Enter Your Name: ")
        self.Customer_Name.append(CustomerName)
        CarId = int(input("Enter the Car Id: "))
        self.Rented_cars_Id.append(CarId)
        self.Rental_days = int(input("How many days the car is to be rented: "))
        self.Rented_cars_Make.append(self.Car_Make[CarId-1])
        self.Rented_cars_Model.append(self.Car_Model[CarId-1])
        print(f"""Car Rented Successfully
        Your Car is {self.Car_Make[CarId-1]} {self.Car_Model[CarId-1]}""")
        self.menu()

    def Return_car(self):
        user_name = input("Enter Your Name: ")
        Car_Id = int(input("Enter the Car Id: "))
        for i in range(0,len(self.Customer_Name)):
            if user_name == self.Customer_Name[i] and Car_Id == self.Rented_cars_Id[i]:
                print("Car Returned Successfully. Your Bill is: $",self.Rental_days*self.Car_RentalPrice_perDay[Car_Id-1])
                # self.Car_Id.append(Car_Id)
                # self.Car_Make.append(self.Car_Make[Car_Id-1])
                # self.Car_Model.append(self.Car_Model[Car_Id-1])
                self.Rented_cars_Id.remove(Car_Id)
                self.Rented_cars_Make.remove(self.Car_Make[Car_Id-1])
                self.Rented_cars_Model.remove(self.Car_Model[Car_Id-1])

            else:
                print("car rent toh kar pehle!!")

        self.menu()

    def Rented_Cars(self):
        print("List of rented Cars")
        for i in range(0,len(self.Rented_cars_Id)):
            print(f"{i+1}. Car Id: {self.Rented_cars_Id[i]}, Car Make: {self.Rented_cars_Make[i]}, Car Model: {self.Rented_cars_Model[i]}")
        self.menu()

    def Total_revenue(self):
        self.menu()

e = CarRentalSystem([1,2,3],[12020,12021,12022],["Honda","Tata","Hyundai"],[2020,2021,2022],[40,50,60])
a = Customer(1,2,3)
