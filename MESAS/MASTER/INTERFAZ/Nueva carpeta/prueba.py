diccionario = {'mesa': 'mesa1OFF', 'color': '#000000'}
valores=diccionario.get("mesa")

if valores == 'mesa1ON':
	dato=1
	if dato == 1:
		color=diccionario.get("color")
		print(color)
if valores == 'mesa1OFF':
	dato=2
	print(dato)



