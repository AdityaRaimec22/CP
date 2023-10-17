class ATM:

    def __init__(self):
        self.pin = ''
        self.balance = 0
        self.user_menu 

    def user_menu(self):
        user_input = input("""
    Hi how can I help you?
    1. Press 1 to create pin
    2. Press 2 to change pin
    3. Press 3 to check balance
    4. Press 4 to withdraw
    5. Anything else to exit
    """)
        # user_input = int(input("enter your number: "))
    
        if user_input == '1':
            # 