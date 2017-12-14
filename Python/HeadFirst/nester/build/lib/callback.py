import sys

print('\n=== You call function from module callback.py ===')

def print_lol(players, indent = False ,start_tab_level = 0, fh=sys.stdout):
	
	for items in players:
#		if isinstance(players, list): # List all character
		if isinstance(items, list):
			print_lol(items, indent, start_tab_level+1, fh)
		else:
			if indent:
				for stop_tab in range(start_tab_level):
					print("\t", end='', file=fh)
			print(items, file=fh)

