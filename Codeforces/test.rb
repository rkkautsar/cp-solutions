#! /usr/bin/env ruby

x = ARGV[0].to_i
puts (Math.log2(x)+1).round
while x > 0 do
	puts x % 2
	x /= 2
end
