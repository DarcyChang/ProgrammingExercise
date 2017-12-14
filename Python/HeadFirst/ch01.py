# p.10

print('\n=== Exercise Ch01 p.10 ===')
MLB_Player=[
			"Yankees", ["Derek_Jeter", "CH_Wang", "A_Rod" ,"Posada"], 
			"Red_Sox", ["Ortiz", "Ramiraze", "David_Wells"]
			]
print(MLB_Player)
MLB_Player.append('Ray')
print(MLB_Player)
#MLB_Player.pop()
MLB_Player.remove('Ray')
print(MLB_Player)
MLB_Player.extend(['Rays',['David_Price', 'Carols_Pena']])
print(MLB_Player)

# p.21
print('\n=== Exercise Ch01 p.21 ===')

def print_lol(players):
	
	for items in players:
#		if isinstance(players, list): # List all character
		if isinstance(items, list):
			print_lol(items)
		else:
			print(items)

print_lol(MLB_Player)

