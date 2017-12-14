def count_even(num):
    if num % 2 != 0:
        return
    sum = 0
    for i in range(1, num, 2):
        sum = sum+i-(i+1)
    print("count_even ANSWER is " + str(sum))
    print("count_even ANOTHER ANSWER is " + str((-1)*(num/2)))

def count():
    sum = 0
    total = 998
    for i in range(0, total, 2):
        sum = sum +i -(i+1)
    print("0-1+2-3....-999, sum = " + str(sum))
    print(int(-1*(total/2)))

def bubble_sort(num_list):
#    print("number list length is " + str(len(num_list)))
    for i in range(len(num_list)-1):
        flag = False
        for j in range(len(num_list)-i-1):
            if(num_list[j] > num_list[j+1]):
                tmp = num_list[j]
                num_list[j] = num_list[j+1]
                num_list[j+1] = tmp
                flag = True
        if flag == False:
            break;
        print(num_list)


if __name__ == '__main__':
    num_list=[]
    i = 1
    j = 6
#    while(i <= j):
#       num_list.append(int(input("Please keyin " + str(j) +" number, this is number " + str(i) +" :\n")))
#       i += 1
#    print(num_list)
#    bubble_sort(num_list)
#    count()
    count_even(30)