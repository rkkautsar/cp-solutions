#!/usr/bin/ruby

n, t = gets.chomp.split.map(&:to_i)
if t == 10 and n == 1 then
	puts -1
else
	puts t*((10**(n-1)/t)+1).round
end
