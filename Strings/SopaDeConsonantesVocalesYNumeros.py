# https://omegaup.com/arena/problem/Sopa-consonantes-vocales-y-num/
lineas = int(input())
consonantes = 0
numeros = 0
vocales = 0
while lineas > 0:
   cadena = input()
   for letra in cadena:
      if letra == "1" or letra == "2" or letra == "3" or letra == "4" or letra == "5" or letra == "6" or letra == "7" or letra == "8" or letra == "9" or letra == "0":
         numeros += 1
         continue
      elif letra == "a" or letra == "e" or letra == "i" or letra == "o" or letra == "u" or letra == "A" or letra == "E" or letra == "I" or letra == "O" or letra == "U":
         vocales += 1
         continue
      elif ord(letra) >= 65 and ord(letra) <= 90 or ord(letra) >= 97 and ord(letra) <= 122:
         consonantes += 1
   lineas -= 1
print(f"{consonantes} {vocales} {numeros}")