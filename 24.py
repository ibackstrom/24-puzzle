from itertools import permutations, product


def generate_patterns(n=4):

    if (n==1):
        return ["%s"]

    
    patterns = []

    for left_size in range(1,n):
        right_size = n - left_size
        left_patterns = generate_patterns(left_size)
        right_patterns = generate_patterns(right_size)

        for lp in left_patterns:
            for rp in right_patterns:
                patterns.append(f"({lp}%s{rp})")
    return patterns

PATTERNS = generate_patterns(4)

def solve_24(nums):

    for a,b,c,d in permutations(nums):
        for o1,o2,o3 in product('+-*/', repeat=3):
            for pat in PATTERNS:
                expr = pat % (a, o1, b, o2, c, o3, d)

                if '/0' in expr or '(/0' in expr:
                    continue
                try:
                    result = eval(expr)
                    if abs(result -24) < 1e-9:
                        return expr
                except:
                    continue


print(solve_24([1, 3, 4, 6]))
        


        






