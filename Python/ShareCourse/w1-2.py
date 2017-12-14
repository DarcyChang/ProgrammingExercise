

x = 'hello'
print(x)
type(x)

print(10%3)

print('a'+str(5)+'b')
#print('a'+5+'b')

""" ============== """


print("I'm python,",'I say "Hello"')
print("I'm python,"+'I say "Hello"')
text = "I'm python,"+'I say "Hello"'
print(text)
print(len(text))
print(text[5:])

words = text.split(',')
print(text[0])
print(text[1])

""" ============== """

x = (10,20)
print(x)
try:
    x[0] = 1
    print('x error')
except:
    y = list(x)
    print('y ='+str(y))

slist = ['A', 'B', 'C', 'D']

if 'E' in slist:
    print('True')
else:
    print('False')

""" ============== """

dic = {'Jack':64, 'Ben':84, 'Cathy':73}

print(dic['Jack'])
print(dic.keys())
print(dic.values())

""" ============== """


