# wap to find the primitive root of prime number in python.

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def find_primitive_root(p):
    if not is_prime(p):
        return None

    def is_primitive_root(g, p):
        powers = set()
        for i in range(1, p):
            powers.add(pow(g, i, p))
            if len(powers) == p - 1:
                return True
        return False

    for g in range(2, p):
        if is_primitive_root(g, p):
            return g

    return None

# Input: Prime number 'p'
p = int(input("Enter a prime number (p): "))

primitive_root = find_primitive_root(p)

if primitive_root is not None:
    print(f"The primitive root of {p} is {primitive_root}.")
else:
    print(f"No primitive root found for {p}.")
