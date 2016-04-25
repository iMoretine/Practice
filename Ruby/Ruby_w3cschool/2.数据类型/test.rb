#!/usr/bin/ruby -w

a = 123;
a = 1_2_3_4;
a = ?a;
a = 0xa;

b = 4.0e2;
puts a,b,a+b;

puts ?\n;
puts ' escape using "\\" ';
puts ' That\'s right ';
puts "#{a+b}";

puts ?\n;

ary = [  "fred", 10, 3.14, "This is a string", "last element", ];
ary.each do |i|
   puts i
end

puts ?\n;

hsh = { "red" => 0xf00, "green" => 0x0f0, "blue" => 0x00f };
hsh.each do |key, value|
   print key, " is ", value, "\n"
end

puts ?\n;

(10..15).each do |n|
   print n, ' ' ;
end

puts ?\n;
