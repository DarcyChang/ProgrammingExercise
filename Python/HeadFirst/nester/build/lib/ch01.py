print('\n=== You call function from module ch01.py ===')

def print_lol(players):
	
	for items in players:
#		if isinstance(players, list): # List all character
		if isinstance(items, list):
			print_lol(items)
		else:
			print(items)

