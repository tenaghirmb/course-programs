a = 2..10000
a.each do |i|
  prime = 1
  for j in 2..(i-1)
    if i%j==0
      prime = 0
      next
    end
  end
  if prime==1  then p i
  end
end