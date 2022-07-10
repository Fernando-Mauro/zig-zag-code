#https://omegaup.com/arena/problem/Miguelito-30/
import math
primerNumero, segundoNumero = input().split()
primerNumero = int(primerNumero)
segundoNumero = int(segundoNumero)
primeraRaiz = math.ceil(math.sqrt(primerNumero)) 
segundaRaiz = math.floor(math.sqrt(segundoNumero))
print(segundaRaiz- primeraRaiz + 1)