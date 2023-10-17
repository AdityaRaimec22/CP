class computational:

    def __init__(self):
        self.factorial = 0
        self.naturalSum = 0

    def multiple(self,n):
        result = 1
        for i in range(1, n+1):
            result *= i
            self.factorial = result
    
    def numberSum(self,n):
        nSum = n(n+1)/2
        self.naturalSum = nSum

    def primeTest(self,n):
        for i in range (1,n):
            if n%2==1 and n%n==0:
                print('wow! it is a prime number')
            else:
                print('oh! ye toh prime nhi hai')

    

# atm = factorial(5)
# print(factorial(5))
