# https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/problem
def main():
   n = int(input())
   arr = list(map(int,input().split()))
   maximo = max(arr)
   while max(arr) == maximo:
      arr.remove(max(arr))
   print(max(arr))

if __name__ == '__main__':
   main()