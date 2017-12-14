#Practice 1
practice  = 3

if(practice == 1):
    total_days = input("Please input days number:\n")
    weeks = int(total_days) / 7
    days = int(total_days) % 7
    print(total_days + " days are " + str(int(weeks)) + " weeks, " + str(days) + " days")

elif(practice == 2):
    num = input("Please input a number:\n")
    if(int(num) %2 == 0):
        print(num + " is even.")
    else:
        print(num + " is odd.")

elif(practice == 3):
    num = input("Please input a number:\n")
    if (int(num) % 2 == 0):
        print(num + " is a multiple of 2.")
    if (int(num) % 3 == 0):
        print(num + " is a multiple of 3.")
    if (int(num) % 5 == 0):
        print(num + " is a multiple of 5.")
    if (int(num) % 7 == 0):
        print(num + " is a multiple of 7.")
    if (int(num) % 2 != 0 and int(num) % 3 != 0 and int(num) % 5 != 0 and int(num) % 7 != 0):
        print(num + " is a Prime number.")

else:
    print("You enter a wrong number.")
