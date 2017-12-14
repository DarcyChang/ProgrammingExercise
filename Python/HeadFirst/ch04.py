#from callback import print_lol
from callback import *

'''
import sys
sys.path.append('./nester')
from nester import callback
'''
import pickle

print('\n=== Exercise ch04 p.107 ===')

man = []
woman1 = []
woman2 = []

try:
	data = open('bbc20130809.txt')
	for each_line in data:
		try:
			(role, line_spoken) = each_line.split(':', 1)
			line_spoken = line_spoken.strip()
			if role == 'Neil':
				man.append(line_spoken)
			elif role == 'Feifei':
				woman1.append(line_spoken)
			elif role == 'BB':
				woman2.append(line_spoken)
			else:
				pass
		except ValueError:
			pass
	data.close()

except IOError:
	print('File is not found.')

print(man)
print(woman1)
print(woman2)

print('\n=== Exercise ch04 p.110 ===')

out = open('temp.txt', "w") # overwrite
print("test01.", file = out)

out = open('temp.txt', "a") # append
print("test02.", file = out)

out = open('temp.txt', "w+") # seems like as overwrite
print("test03.", file = out)

#out = open('temp.txt', "r") # read only
#print("test04.", file = out)

print('\n=== Exercise ch04 p.111 ===')


try:
    man_file = open('man_data.txt', 'w')
    print(man, file = man_file)
    print('Create man_data.txt')
    woman1_file = open('woman1_data.txt', 'w')
    print(woman1, file = woman1_file)
    print('Create woman1_data.txt')
    woman2_file = open('woman2_data.txt', 'w')
    print(woman2, file = woman2_file)
    print('Create woman2_data.txt')

    error_file = open('empty.txt')
    print(woman2, file = error_file)
    print('You should not see this message.')
except IOError as message:
    print('Open file error')
    print(str(message))
finally:
    print('Error happen, please ignore this message.')
    man_file.close()
    woman1_file.close()
    woman2_file.close()

print('\n=== Exercise ch04 p.120 ===')

try:
    with open('temp.txt') as data:
        print('test', file=data)
except IOError as err:
    print(str(err))
#    pass

print('\n=== Exercise ch04 p.121 ===')


try:
    with open('man_data.txt', 'w') as man_file:
        print(man, file = man_file)
        print('Create man_data.txt')
    with open('woman1_data.txt', 'w') as woman1_file:
        print(woman1, file = woman1_file)
        print('Create woman1_data.txt')
    with open('woman2_data.txt', 'w') as woman2_file:
        print(woman2, file = woman2_file)
        print('Create woman2_data.txt')
except IOError as err:
    print(str(err))


print('\n=== Exercise ch04 p.127 ===')

try:
    with open('man_data.txt', 'w') as man_file:
        print_lol(man, True, 1,  man_file)
        print('Create man_data.txt')
    with open('woman1_data.txt', 'w') as woman1_file:
        print_lol(woman1, True, 1,  woman1_file)
        print('Create woman1_data.txt')
    with open('woman2_data.txt', 'w') as woman2_file:
        print_lol(woman2, True, 1, woman2_file)
        print('Create woman2_data.txt')
except IOError as err:
    print(str(err))

print('\n=== Exercise ch04 p.133 ===')

import pickle

try:
	with open('man_data.pickle', 'wb') as man_file:
		pickle.dump(man,man_file)
		print('pickle man_data.pickle')
	with open('woman1_data.pickle', 'wb') as woman1_file:
		pickle.dump(woman1, woman1_file)
		print('pickle woman1_data.pickle')
	with open('woman2_data.pickle', 'wb') as woman2_file:
		pickle.dump(woman2, woman2_file)
		print('pickle woman2_data.pickle')
except TabError as terr:
    print('TAB error : ' + str(terr))
except IndentationError as ieer:
    print('Identation error : ' + str(ierr))
except IOError as err:
    print('IO error : ' + str(err))
except pickle.PickleError as perr:
    print('pickle error : ' + str(perr))
	
try:
	with open('man_data.pickle', 'rb') as man_file:
		man_list = pickle.load(man_file)
		print(man_list)
	with open('woman1_data.pickle', 'rb') as woman1_file:
		woman1_list = pickle.load(woman1_file)
		print(woman1_list)
	with open('woman2_data.pickle', 'rb') as woman2_file:
		woman2_list = pickle.load(woman2_file)
		print(woman2_list)
except TabError as terr:
    print('TAB error : ' + str(terr))
except IndentationError as ieer:
    print('Identation error : ' + str(ierr))
except IOError as err:
    print('IO error : ' + str(err))
except pickle.PickleError as perr:
    print('pickle error : ' + str(perr))


