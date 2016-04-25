#!/usr/bin/ruby -w

END {
   puts "Terminating Ruby Program"
}

BEGIN {
   puts "Initializing Ruby Program"
}


puts "This is main Ruby Program"

puts "Hello, Ruby!"

print << EOF
    This is the first way of creating
    here document ie. multiple line string.
EOF

print <<"EOF";                # 与上面相同
    This is the second way of creating
    here document ie. multiple line string.
EOF

print <<`EOC`                 # 执行命令
    echo hi there
    echo lo there\n
EOC

print <<"foo", <<"bar"        # 您可以把它们进行堆叠
    I said foo.
foo
    I said bar.
bar

=begin
This is a annotation.
=end

#This is also a annotation.
