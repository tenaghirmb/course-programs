#coding:gbk
#Robot类
#可以说话的机器人
class Robot
  #说话
def say(words)
puts words
end

  #说你好!
def say_hello
say "你好!AKA!"
end
end

my_robot = Robot.new
my_robot.say_hello