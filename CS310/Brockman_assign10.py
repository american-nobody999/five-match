# Title: Brockman_assign10.py
# Author: Leslie Brockman (
# Date: November 15, 2025
# Description: This program demonstrates the Normal Order Evaluation problem
# in recursive factorial functions and implements memoization as a solution.
# PROBLEM: Normal Order Evaluation causes redundant calculations
# - factorial(5) calculates: 5! = 5*4*3*2*1*0!
# - Later factorial(3) recalculates: 3*2*1*0! (redundant work!)
#
# SOLUTION: Memoization - cache previously calculated results

# Dictionary to store previously calculated factorial results (the cache!)
factorial_cache = {}

def factorial_original(n):
    """Original recursive factorial - demonstrates the inefficiency problem"""
    print(f"  Calculating factorial({n}) - Original method")
    
    if n == 0:
        return 1
    else:
        return n * factorial_original(n-1)

def factorial_memoized(n):
    """Improved factorial with memoization - eliminates redundant calculations"""
    
    # Check if we already calculated this factorial (EFFICIENCY!)
    if n in factorial_cache:
        print(f"  factorial({n}) found in cache! No recalculation needed.")
        return factorial_cache[n]
    
    print(f"  Calculating factorial({n}) - First time, storing in cache")
    
    # Base case
    if n == 0:
        result = 1
    else:
        result = n * factorial_memoized(n-1)
    
    # Store result in cache for future use (SOLUTION TO THE PROBLEM!)
    factorial_cache[n] = result
    return result

def demonstrate_problem():
    """Demonstrate the Normal Order Evaluation problem and solution"""
    print("="*60)
    print("DEMONSTRATION: Normal Order Evaluation Problem & Solution")
    print("="*60)
    
    print("\n--- ORIGINAL METHOD (Redundant Calculations) ---")
    print("Calculating factorial(3) using original recursive method:")
    result1 = factorial_original(3)
    print(f"Result: {result1}")
    
    print("\nCalculating factorial(3) AGAIN using original method:")
    result2 = factorial_original(3)  # Recalculates everything!
    print(f"Result: {result2}")
    print("PROBLEM: Same calculation done twice - inefficient!")
    
    print("\n--- MEMOIZED METHOD (Efficient Caching) ---")
    print("Calculating factorial(3) using memoized method:")
    result3 = factorial_memoized(3)
    print(f"Result: {result3}")
    
    print("\nCalculating factorial(3) AGAIN using memoized method:")
    result4 = factorial_memoized(3)  # Uses cached result!
    print(f"Result: {result4}")
    print("SOLUTION: Second calculation uses cached result - efficient!")
    
    print(f"\nCurrent cache contents: {factorial_cache}")

# Original Professor Krasso code with improvements
def main_program():
    """Main program with user input and error handling"""
    try:
        # Ask the user to enter a number 
        num = int(input("\nEnter a number to calculate factorial: "))
        
        # If the input is negative value, print an error message
        if num < 0:
            print("Sorry, factorial does not exist for negative numbers")
        else:
            # Calculate using memoized version (efficient!)
            result = factorial_memoized(num)
            print(f"The factorial of {num} is {result}")
            
            # Show cache efficiency
            print(f"Cache now contains: {list(factorial_cache.keys())}")
            
    except: 
        # Handle the exception if the input is not a numeric value
        print('Input must be a number and cannot be empty')

if __name__ == "__main__":
    # First demonstrate the problem and solution
    demonstrate_problem()
    
    # Then run the main program
    main_program()
    
    print("\n" + "="*60)
    print("ASSIGNMENT SOLUTION COMPLETE:")
    print("Normal Order Evaluation problem identified")
    print("Memoization implemented to eliminate redundant calculations") 
    print("Efficiency improved through caching mechanism")
    print("Original functionality preserved with enhanced performance")
    print("="*60)

#--- ignore these--inetranl notes only ---
# NORMAL ORDER EVALUATION PROBLEM:
# - Recursive functions recalculate same values repeatedly
# - factorial(5) then factorial(3) = redundant calculations for 3,2,1,0

# this is the same friggin issue as the ch10 exercise_take 7 with the input handling--wtf? The world is a small place.

#The solution is caching/memoization to avoid redundant work
#getcin() from C is like input() in Python, both read from standard input

#Avoid redundant computation through intelligent caching/storage
#This applies to: Recursive functions (Python factorial memoization) Object creation (C++ banking system efficiency) Input buffer management (cin.get() vs getch() handling) Database queries (cache results instead of re-querying) Web requests (cache API responses)  Graphics rendering (cache textures instead of reloading)



# MEMOIZATION SOLUTION:
# - Cache previously calculated results in dictionary
# - Check cache before calculating - return cached value if exists
# - Dramatically improves efficiency for repeated calculations
# 
# EXAMPLE: factorial(3) called twice
# - Original: 6 total calculations (3*2*1 + 3*2*1)  
# - Memoized: 3 calculations first time, 0 second time (uses cache)--I smell Parallelism here.
# Memoization + parallelism = advanced optimization
#Add memoization to eliminate redundant factorial calculations
