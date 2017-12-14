

print('\n=== Exercise ch06 p.175 ===')

def sanitize(time_string):
	if '-' in time_string:
		splitter = '-'
	elif ':' in time_string:
		splitter = ':'
	else:
		return(time_string)
	(mins, secs) = time_string.split(splitter)
	return(mins + '-' +secs)

def get_coach_data(filename):
	try:
		with open(filename) as f:
			data = f.readline()
			return(data.strip().split(','))
	except IOError as ioeer:
		print(str(ioeer))
		return(None)

sarah = get_coach_data('sarah2.txt')
(sarah_name, sarah_dob) = sarah.pop(0), sarah.pop(0)

print(sarah_name + "'s fastest times are: " + str(sorted(set([sanitize(t) for t in sarah]))[0:3]))


print('\n=== Exercise ch06 p.181 ===')

sarah = get_coach_data('sarah2.txt')
sarah_data = {}
type(sarah_data)
sarah_data['Name'] = sarah.pop(0)
sarah_data['DOB'] = sarah.pop(0)
sarah_data['Times'] = sarah
print(sarah_data['Name'] + "'s fastest times are: " + str(sorted(set([sanitize(t) for t in sarah_data[ 'Times' ]]))[0:3]))


print('\n=== Exercise ch06 p.185 ===')

def get_coach_data(filename):
	try:
		with open(filename) as f:
			data = f.readline()
		templ = data.strip().split(',')
		return({ 'Name' : templ.pop(0),
				'DOB' : templ.pop(0),
				'Times' : str(sorted(set([sanitize(t) for t in templ]))[0:3])
				})
	except IOError as ioeer:
		print('File error: '+ str(ioerr))
		return(None)

james = get_coach_data('james2.txt')

print(james[ 'Name' ] + " 's fastest times are: " + james['Times'])


