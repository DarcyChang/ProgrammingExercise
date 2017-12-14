#import ch01
from callback import print_lol

print('\n=== Exercise ch02 p.43 ===')
cast=['Palin', 'Cleese', 'Idle', 'Jones', 'Gilliam', 'Chapman', 13]
#ch01.print_lol(cast)
print_lol(cast)

print('\n=== Exercise ch02 p.67 ===')

movies = ['The Holy Grail', 1975, 'Terry Jones & Terry Gilliam',91, 
	   		['Graham Chapam', 
				['Michael Palin', 'John Cleese', 'Terry Gilliam', 'Eric Idle', "Terry Jones"]
			]
	   	]

print_lol(movies, False, 10)
print_lol(movies, True,  2)
