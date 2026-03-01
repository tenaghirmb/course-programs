#encoding:utf-8
require 'tk'

root = TkRoot.new do 
  title "AKA向你问好!"
  geometry "500x300"
end

l=TkLabel.new(root) do
  text 'AKA'
  font "arial 50 bold"
  place('x'=>150, 'y'=>20)
end

b=TkButton.new(root) do
  text "点灯"
  font "arial 20"
  place('x'=>218, 'y'=>190)
end
b.bind("ButtonPress"){l.configure('foreground'=>'yellow')}
b.bind("Leave"){l.configure('foreground'=>'black')}

Tk.mainloop