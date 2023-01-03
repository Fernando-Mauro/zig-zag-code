from datetime import date
anterior = date(2010, 8, 9)
actual = date.today()
print(anterior.strftime("%A")) #Usamos %a para el dia de la semana abreviado y %A para el dia de la semana completo
print("{}".format((actual - anterior).days))