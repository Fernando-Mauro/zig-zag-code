# https://omegaup.com/arena/problem/gobierno-de-mexico-1
cadena = input();
nombre = input();
# separar nombre completo en nombres, y apellidos
def primerVocal(cadena):
   for el in cadena:
      if el == 'a' or el == 'e' or el == 'i' or el == 'o' or el == 'u':
         return el;
primerApellido = 0
separados = nombre.split()
nacimiento = input();
clave = input();
valida = "";
valida += separados[1][0] if len(separados) == 3 else separados[2][0];
valida += primerVocal(separados[1]) if len(separados) == 3 else primerVocal(separados[2]);
print(valida)