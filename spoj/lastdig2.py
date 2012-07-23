t = int( input() )
while t:
  s = input().split( ' ' )

  print( pow( int( s[ 0 ] ), int( s[ 1 ] ), 10 ) )
  t -= 1
