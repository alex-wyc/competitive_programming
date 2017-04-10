# Input
# T
# for q in T
#   N

def main()
	_T = gets.chomp.to_i
	_N = nil
	
	# puts "TEST T is #{_T}"
	
	(1.._T).each do |q|
		_N = gets.chomp.to_i
		w = get_last_tidy(_N)
	
		print "Case ##{q}: "
		# test(_N)
		print "#{w}"
		puts
	end
	
	# [129, 999, 7, 123, 321, 2220, 12342372 ].each do |n|
	# 	# test(n)
	# end
	
	# 100.times do
	# 	n = rand(2**10)
	# 	# test(n)
	# end
end

def tidy?(n)
	# Convert to integer values
	digits = n.to_s.split('').map { |ch| ch.to_i }
	# Check ascending order
	return digits.each_cons(2).all? { |i,j| i <= j }
end

def get_unbalanced_idx(n)
	if tidy?(n)
		return -1
	else
		# Convert to integer values
		digits = n.to_s.split('').map { |ch| ch.to_i }
	
		# Iterate through digits to check ascending order
		(1..(digits.length-1)).each do |idx|
			# Return index if untidy
			i = digits[idx-1]
			j = digits[idx]
			return (idx-1) if i >= j
		end
	end
end

def get_last_tidy(n)
	if tidy?(n)
		return n
	else
		# Brute force
		# n.downto(1) do |i|
		#  	return i if tidy?(i)
		# end

		digits = n.to_s.split('').map { |ch| ch.to_i }
		idx = get_unbalanced_idx(n)
		digits[idx] = digits[idx] - 1

		((idx+1)..(digits.length-1)).each do |idx|
			digits[idx] = 9
		end

		return digits.join('').to_i
	end
end

def test(n)
	puts "TEST n = #{n}"
	puts "is tidy? #{tidy?(n)}"
	puts "last tidy: #{get_last_tidy(n)}"
	puts "unbalanced_idx: #{get_unbalanced_idx(n)}"
	puts
end

main()

