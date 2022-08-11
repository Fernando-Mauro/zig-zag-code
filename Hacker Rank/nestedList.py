# https://www.hackerrank.com/challenges/nested-list/problem?isFullScreen=false
def main():
   lista = []
   n = int(input())
   for i in range(0,n):
      name = input()
      score = float(input())
      listTemp = [score,name]
      lista.append(listTemp)
   lista.sort()
   minimum = lista[0][0]
   while lista[0][0] == minimum:
      lista.pop(0)
   newLista = []
   secondValue = lista[0][0]
   while lista[0][0] == secondValue:
      newLista.append([lista[0][1], lista[0][0]])
      lista.pop(0)
      if len(lista) == 0:
         break
   newLista.sort()
   for i in newLista:
      print(i[0])

if __name__ == '__main__':
   main()