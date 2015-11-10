#! /usr/bin/env ruby

require 'prime'

x = gets.to_i
divisors = x.prime_division
ans = 1
divisors.each { |i,j| ans*=i }
puts ans
