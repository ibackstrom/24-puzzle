def gen(n)
  return ["%d"] if n == 1
  res = []
  1.upto(n-1) do |l|
    gen(l).product(gen(n-l)) do |a, b|
      res << "(#{a}%c#{b})"
    end
  end
  res
end

PATTERNS = gen(4)

def solve24(nums)
  nums.permutation.each do |a,b,c,d|
    ['+','-','*','/'].repeated_permutation(3).each do |o1,o2,o3|
      PATTERNS.each do |pat|
        expr = format(pat, a, o1, b, o2, c, o3, d)
        next if expr.include?("/0")
        begin
          return expr if (eval(expr) - 24).abs < 1e-9
        rescue
        end
      end
    end
  end
  "Нет решения"
end

puts solve24([3,3,8,8])
