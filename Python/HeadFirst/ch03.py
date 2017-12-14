import os

print('\n=== Exercise ch03 p.85 ===')

if os.path.exists('bbc20130809.txt'):
	data = open('bbc20130809.txt')
	for each_line in data:
		if each_line.find(':') != -1:
			(role, line_spoken) = each_line.split(':', 1)
			print(role, end='')
			print(' said:', end='')
			print(line_spoken, end='')

	data.close()
else:
	print('bbc20130809 is not found.')

print('\n=== Exercise ch03 p.99 ===')

try:
	data = open('bbc20130809.txt')
	for each_line in data:
		try:
			(role, line_spoken) = each_line.split(':', 1)
			print(role, end='')
			print(' said:', end='')
			print(line_spoken, end='')
		except ValueError:
			pass
#			print(each_line)
	data.close()
except IOError:
	print('bbc20130809 is not found.')
