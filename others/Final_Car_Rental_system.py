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
        
class Customer:

    def __init__(self,Customer_Id):
        self.Customer_Id = Customer_Id

class CarRentalSystem(Car,Customer):

    def __init__(self,Car_Id,Car_Model,Car_Make,Car_Year,Car_RentalPrice_perDay,Customer_Id):

        super().__init__(Car_Id,Car_Model,Car_Make,Car_Year,Car_RentalPrice_perDay)
        # super(Customer,self).__init__(Customer_Id)
        self.Customer_Id = []

        for i in range(0,len(self.Car_Id)):
            self.Customer_Id.append(Customer_Id[i])

        self.Customer_Name = []
        self.Rented_cars_Id = []
        self.Rented_cars_Make = []
        self.Rented_cars_Model = []
        self.Rented_Car_RentalPrice_perDay = []
        self.Rental_Days = []
        self.Revenue_Generated = []
        self.Number_of_Days = []
        self.Rented_Car_CustomerId = []

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
        Input Number Here: """)

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

        if not self.Car_Id:

            print("Dhanda mast Chal rha hai! Saari Car rent ho gyi")

        else:

            for i in range(0,len(self.Car_Id)):
                
                print(f"{i+1}, Car Id: {self.Car_Id[i]}, Car Make: {self.Car_Make[i]}, Car Model: {self.Car_Model[i]}, Car Year: {self.Car_Year[i]}, Car rental Price Per day: ${self.Car_RentalPrice_perDay[i]}")

        self.menu()

    def Rent_Car(self):

        self.Customer_Name = []
        CustomerName = input("Enter Your Name: ")
        CarId = int(input("Enter the Car Id: "))
        

        if CarId in self.Car_Id:
            index = self.Car_Id.index(CarId)
        # try:
            # index = self.Car_Id.index(CarId)

            Rental_days = int(input("How many days the car is to be rented: "))
            self.Rental_Days.append(Rental_days)
            self.Rented_cars_Id.append(CarId)
            self.Customer_Name.append(CustomerName)
            self.Rented_cars_Make.append(self.Car_Make[index])
            self.Rented_cars_Model.append(self.Car_Model[index])
            self.Rented_Car_RentalPrice_perDay.append(self.Car_RentalPrice_perDay[index])
            self.Revenue_Generated.append(self.Car_RentalPrice_perDay[index])
            self.Number_of_Days.append(Rental_days)

            print(f"""Car Rented Successfully
            Your Car is {self.Car_Make[index]} {self.Car_Model[index]}. Your Customer ID is: {self.Customer_Id[index]}""")

            self.Rented_Car_CustomerId.append(self.Customer_Id[index])
            self.Customer_Id.remove(self.Customer_Id[index])
            self.Car_Id.remove(CarId)
            self.Car_Make.remove(self.Car_Make[index])
            self.Car_Model.remove(self.Car_Model[index])
            self.Car_RentalPrice_perDay.remove(self.Car_RentalPrice_perDay[index])

        else:

            print("please enter correct details")

        self.menu()

    def Return_car(self):

        self.user_name = input("Enter Your Name: ")
        Car_Id = int(input("Enter the Car Id: "))
        CustomerId = int(input("Enter the Customer ID: "))
        

        # for i in range(0,len(self.Customer_Name)): user_name in self.Customer_Name and
        if Car_Id in self.Rented_cars_Id and CustomerId in self.Rented_Car_CustomerId:
            index = self.Rented_cars_Id.index(Car_Id)
        # if user_name == self.Customer_Name[index] and Car_Id == self.Rented_cars_Id[index]:

            print("Car Returned Successfully. Your Bill is: $",self.Rental_Days[index]*self.Rented_Car_RentalPrice_perDay[index])

            self.Car_Id.append(Car_Id)
            self.Car_Make.append(self.Rented_cars_Make[index])
            self.Car_Model.append(self.Rented_cars_Model[index])
            self.Car_RentalPrice_perDay.append(self.Rented_Car_RentalPrice_perDay[index])
            self.Customer_Id.append(self.Rented_Car_CustomerId[index])
            self.Rented_Car_CustomerId.remove(self.Rented_Car_CustomerId[index])
            self.Rented_cars_Id.remove(Car_Id)
            self.Rented_cars_Make.remove(self.Rented_cars_Make[index])
            self.Rented_cars_Model.remove(self.Rented_cars_Model[index])
            self.Rental_Days.remove(self.Rental_Days[index])
            self.Rented_Car_RentalPrice_perDay.remove(self.Rented_Car_RentalPrice_perDay[index])

        else:

            print("car rent toh kar pehle!!")

        self.menu()

    def Rented_Cars(self):

        if not self.Rented_cars_Id:

            print("No Cars are rented")

        else:

            print("List of rented Cars")

            for i in range(0,len(self.Rented_cars_Id)):

                print(f"{i+1}. Car Id: {self.Rented_cars_Id[i]}, Car Make: {self.Rented_cars_Make[i]}, Car Model: {self.Rented_cars_Model[i]}")

        self.menu()

    def Total_revenue(self):

        sum = 0
        for i in range(0,len(self.Revenue_Generated)):

            sum = sum + self.Revenue_Generated[i]*self.Number_of_Days[i]

        print(f"The total revenue is: ${sum}")

        self.menu()

e = CarRentalSystem([1,2,3],[12020,12021,12022],["Honda","Tata","Hyundai"],[2020,2021,2022],[40,50,60],[1,2,3])
# a = Customer(1,2,3)
