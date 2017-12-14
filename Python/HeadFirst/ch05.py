print('\n=== Exercise ch05 p.141 ===')

try:
	with open('james.txt') as jaf:
		data = jaf.readline()
	james = data.strip().split(',')
	with open('julie.txt') as juf:
		data = juf.readline()
	julie = data.strip().split(',')
	with open('sarah.txt') as saf:
		data = saf.readline()
	sarah = data.strip().split(',')
	with open('mikey.txt') as mif:
		data = mif.readline()
	mikey = data.strip().split(',')
	print(james)
	print(julie)
	print(sarah)
	print(mikey)

except IOError as err:
	print(str(err))

print('\n=== Exercise ch05 p.145 ===')

print(sorted(james))
print(sorted(julie))
print(sorted(sarah))
print(sorted(mikey))

print('\n=== Exercise ch05 p.149 ===')

def sanitize(time_string):
	if '-' in time_string:
		splitter = '-'
	elif ':' in time_string:
		splitter = ':'
	else:
		return(time_string)
	(mins, secs) = time_string.split(splitter)
	return(mins + '-' +secs)

print('\n=== Exercise ch05 p.151 ===')

clean_james=[]
clean_julie=[]
clean_sarah=[]
clean_mikey=[]

for each_time in james:
	clean_james.append(sanitize(each_time))
for each_time in julie:
	clean_julie.append(sanitize(each_time))
for each_time in sarah:
	clean_sarah.append(sanitize(each_time))
for each_time in mikey:
	clean_mikey.append(sanitize(each_time))

print(clean_james[0])
print(clean_james[1])
print(clean_james[2])
print(clean_james[3])

print(sorted(clean_james, reverse=True))
print(sorted(clean_julie, reverse=True))
print(sorted(clean_sarah, reverse=True))
print(sorted(clean_mikey, reverse=True))

print('\n=== Exercise ch05 p.157 list comprehension ===')

print(sorted([sanitize(each_time) for each_time in james]))
print(sorted([sanitize(each_time) for each_time in julie]))
print(sorted([sanitize(each_time) for each_time in sarah]))
print(sorted([sanitize(each_time) for each_time in mikey]))

print('\n=== Exercise ch05 p.161 ===')

james = sorted([sanitize(each_time) for each_time in james])
julie = sorted([sanitize(each_time) for each_time in julie])
sarah = sorted([sanitize(each_time) for each_time in sarah])
mikey = sorted([sanitize(each_time) for each_time in mikey])

unique_james = []
unique_julie = []
unique_sarah = []
unique_mikey = []
count = 1

for each_time in james:
	if each_time not in unique_james and count <= 3 :
		unique_james.append(each_time)
		count=count+1

for each_time in julie:
	if each_time not in unique_julie:
		unique_julie.append(each_time)
for each_time in sarah:
	if each_time not in unique_sarah:
		unique_sarah.append(each_time)
for each_time in mikey:
	if each_time not in unique_mikey:
		unique_mikey.append(each_time)
	
print('james count =', count)
print(unique_james)
print(unique_julie[0:3])
print(unique_sarah[0:3])
print(unique_mikey[0:3])

print('\n=== Exercise ch05 p.169 ===')

def get_coach_data(filename):
	try:
		with open(filename) as f:
			data = f.readline()
			return(data.strip().split(','))
	except IOError as ioeer:
		print(str(ioeer))
		return(None)

new_james = get_coach_data('james.txt')
new_julie = get_coach_data('julie.txt')
new_sarah = get_coach_data('sarah.txt')
new_mikey = get_coach_data('mikey.txt')

print(new_james)
print(new_julie)
print(new_sarah)
print(new_mikey)

print(sorted(set(sanitize(time) for time in new_james))[0:3])
print(sorted(set(sanitize(time) for time in new_julie))[0:3])
print(sorted(set(sanitize(time) for time in new_sarah))[0:3])
print(sorted(set(sanitize(time) for time in new_mikey))[0:3])
