#!/usr/bin/ruby

require 'prime'

n = gets.to_i
if Prime.prime?(n) then
	puts 1
	puts n
else
	n -= 3
	if Prime.prime?(n) then
		puts 2
		puts("3 #{n}")
	else
		Prime.each(n) do |p|
			if Prime.prime?(n-p) then
				puts 3
				puts("3 #{p} #{n-p}")
				break
			end
		end
	end
end
