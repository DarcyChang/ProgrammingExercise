promot_str = "Please input number"
num1 = input(promot_str + "1:\n")
num2 = input(promot_str + "2:\n")
num3 = input(promot_str + "3:\n")

if(num1 > num2):
    temp = num1
    num1 = num2
    num2 = temp
#print(str(num1) + " " + str(num2))

if(num2 > num3):
    temp = num2
    num2 = num3
    num3 = temp
#print(str(num2) + " " + str(num3))

if(num1 > num2):
    temp = num1
    num1 = num2
    num2 = temp
#print(str(num1) + " " + str(num2))

print("big >> small = " + str(num3) + " " + str(num2) + " " + str(num1))
print("big >> small = " + str(num1) + " " + str(num2) + " " + str(num3))