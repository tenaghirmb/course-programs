#encoding:utf-8
loop do
  puts "请输入第一个数字"
  a = gets.chomp
  puts "请输入第二个数字"
  b = gets.chomp
  puts "请输入运算符"
  c = gets.chomp

  print "\t结果是 #{a.to_f} #{c} #{b.to_f} = "
  case c
    when "+"   then puts a.to_f+b.to_f
    when "-"   then puts a.to_f-b.to_f
    when "*"   then puts a.to_f*b.to_f
    when "/"   then puts a.to_f/b.to_f
    else       puts "???","\t抱歉，此功能尚未生成"
  end
  puts "还要再次运算吗？输入y继续，否则退出"
  break if gets.chomp != "y"
end