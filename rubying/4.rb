# generate Fibonacci sequence
f = [1,1]
n = 2..35
n.each do |i|
  f[i] = f[i-2] + f[i-1]
end

# generate nodes
j = [0]
i = 1
a = (2..6).to_a + (1..5).to_a.reverse
a.each do |c|
  j[i] = j[i-1] +c
  i+= 1
end

# generate pyramids
(5*8).times { print (" ") }
for i in 0..35
  a = f[i]
  t = 0
  loop do
    a/=10
    t+=1
    break if a==0
  end
  (8-t-(8-t)/2).times { print (" ") }
  print (f[i])
  ((8-t)/2).times { print (" ") }
  8.times { print (" ") }
  if x = j.index(i)
    puts
    ((x-4)*8).abs.times { print (" ") }
  end  
end