require 'flt'
include Flt

DecNum.context.precision = 102

ans = 0
for i in 1..100 do
    root = DecNum( i ).sqrt
    if root != root.to_i then
        ( 0..99 ).each do
            ans += ( root % 10 ).to_i()
            root *= 10;
        end
    end
end
puts ans
