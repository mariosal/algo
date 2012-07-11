# https://en.wikipedia.org/wiki/Repeating_decimal#Fractions_with_prime_denominators

N = 1000

isPrime = [ False ] * 2 + [ True ] * ( N - 1 )
for i in range( 2, int( N ** 0.5 ) + 1 ):
  if isPrime[ i ]:
    for j in range( i * i, N + 1, i ):
      isPrime[ j ] = False

for i in range( N, 0, -1 ):
  if not isPrime[ i ]:
    continue

  j = 1
  while ( 10 ** j - 1 ) % i:
    j += 1
  if i - j == 1:
    print( i )
    break
