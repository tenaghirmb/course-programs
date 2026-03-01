require 'tk'
resultsVar = TkVariable.new
root = TkRoot.new do
  title "Calculator"
  geometry "295x360"
end

result=TkLabel.new(root)do
  textvariable
  font 8
  justify 'left'
  width 28
  height 3
  background 'grey'
  grid('rowspan'=>2,'columnspan'=>4)
end
result['textvariable']=resultsVar

b2=TkButton.new(root) do
  text "0"
  font 8
  borderwidth 4
  width 13
  height 2
  grid('row'=>6,'columnspan'=>2)
end
b2.bind("ButtonPress"){resultsVar.value+="0";resultsVar.value=0 if resultsVar.value.include?("=")}

b3=TkButton.new(root) do
  text "."
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>6,'column'=>2)
end
b3.bind("ButtonPress"){resultsVar.value+=".";resultsVar.value="." if resultsVar.value.include?("=")}

b4=TkButton.new(root) do
  text "="
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>6,'column'=>3)
end
b4.bind("ButtonPress")do
  r=resultsVar.value
  raise RuntimeError if r.include?("=")
  j=0;p=r.count "+";q=r.count "-";m=r.count "*";n=r.count "/"
  j+=1 if r.include?("+")
  j+=1 if r.include?("-")
  j+=1 if r.include?("*")
  j+=1 if r.include?("/")
  raise RuntimeError if j>1||p>1||q>1||m>1||n>1
  case $operator.chomp
  when "+"
    a=r.split(/\+/)
    res=a[0].to_r+a[1].to_r
  when "-"
    b=r.split(/\-/)
    res=b[0].to_r-b[1].to_r
  when "*"
    c=r.split(/\*/)
    res=c[0].to_r*c[1].to_r
  when "/"
    d=r.split(/\//)
    res=d[0].to_r/d[1].to_r
  else
    raise RuntimeError
  end
  i=res.to_f.to_s.split(/\./)
  if i[1].to_f==0
    res=res.to_i
  else
    res=res.to_f
  end
  resultsVar.value+="=#{res}"
end

b5=TkButton.new(root) do
  text "1"
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>5,'column'=>0)
end
b5.bind("ButtonPress"){resultsVar.value+="1";resultsVar.value=1 if resultsVar.value.include?("=")}
 
b6=TkButton.new(root) do
  text "2"
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>5,'column'=>1)
end
b6.bind("ButtonPress"){resultsVar.value+="2";resultsVar.value=2 if resultsVar.value.include?("=")}

b7=TkButton.new(root) do
  text "3"
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>5,'column'=>2)
end
b7.bind("ButtonPress"){resultsVar.value+="3";resultsVar.value=3 if resultsVar.value.include?("=")}

b8=TkButton.new(root) do
  text "+"
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>5,'column'=>3)
end
b8.bind("ButtonPress"){resultsVar.value+="+";$operator="+";resultsVar.value=nil if resultsVar.value.include?("=")}

b9=TkButton.new(root) do
  text "4"
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>4,'column'=>0)
end
b9.bind("ButtonPress"){resultsVar.value+="4";resultsVar.value=4 if resultsVar.value.include?("=")}

b10=TkButton.new(root) do
  text "5"
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>4,'column'=>1)
end
b10.bind("ButtonPress"){resultsVar.value+="5";resultsVar.value=5 if resultsVar.value.include?("=")}

b11=TkButton.new(root) do
  text "6"
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>4,'column'=>2)
end
b11.bind("ButtonPress"){resultsVar.value+="6";resultsVar.value=6 if resultsVar.value.include?("=")}

b12=TkButton.new(root) do
  text "-"
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>4,'column'=>3)
end
b12.bind("ButtonPress"){resultsVar.value+="-";$operator="-";resultsVar.value=nil if resultsVar.value.include?("=")}

b13=TkButton.new(root) do
  text "7"
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>3,'column'=>0)
end
b13.bind("ButtonPress"){resultsVar.value+="7";resultsVar.value=7 if resultsVar.value.include?("=")}

b14=TkButton.new(root) do
  text "8"
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>3,'column'=>1)
end
b14.bind("ButtonPress"){resultsVar.value+="8";resultsVar.value=8 if resultsVar.value.include?("=")}

b15=TkButton.new(root) do
  text "9"
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>3,'column'=>2)
end
b15.bind("ButtonPress"){resultsVar.value+="9";resultsVar.value=9 if resultsVar.value.include?("=")}

b16=TkButton.new(root) do
  text "*"
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>3,'column'=>3)
end
b16.bind("ButtonPress"){resultsVar.value+="*";$operator="*";resultsVar.value=nil if resultsVar.value.include?("=")}

b17=TkButton.new(root) do
  text "C"
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>2,'column'=>0)
end
b17.bind("ButtonPress"){resultsVar.value=nil}

b18=TkButton.new(root) do
  text "Del"
  font 8
  borderwidth 4
  width 13
  height 2
  grid('row'=>2,'column'=>1,'columnspan'=>2)
end
b18.bind("ButtonPress"){resultsVar.value=resultsVar.value.chop;resultsVar.value=nil if resultsVar.value.include?("=")}

b20=TkButton.new(root) do
  text "/"
  font 8
  borderwidth 4
  width 6
  height 2
  grid('row'=>2,'column'=>3)
end
b20.bind("ButtonPress"){resultsVar.value+="/";$operator="/";resultsVar.value=nil if resultsVar.value.include?("=")}

Tk.mainloop