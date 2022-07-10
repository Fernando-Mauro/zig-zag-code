# https://omegaup.com/arena/problem/Divisores-de-una-cadena
import math;
cadena = input()
valor = 0
for el in cadena:
   valor += ord(el.upper())
divisores = 2;
for i in range(2,valor,1):
   if (valor % i == 0):
      divisores += 1
print(divisores);