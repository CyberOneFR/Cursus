from collections import deque
from copy import deepcopy
import random

def bfs_stack_sort(start_stack_a, start_stack_b, target_stack_a, target_stack_b, instructions, output_file):
    """
    Perform BFS to find the shortest sequence of instructions to transform (start_stack_a, start_stack_b)
    into (target_stack_a, target_stack_b) and save training data to a file.

    Args:
        start_stack_a (list): Initial configuration of stack A.
        start_stack_b (list): Initial configuration of stack B.
        target_stack_a (list): Target configuration of stack A.
        target_stack_b (list): Target configuration of stack B.
        instructions (dict): Mapping of instruction names to functions that perform stack operations.
        output_file (str): File path to save training data.

    Returns:
        list: The shortest sequence of instructions to transform the stacks.
    """
    queue = deque([(start_stack_a, start_stack_b, [])])  # (current_stack_a, current_stack_b, current_sequence)
    visited = set()
    visited.add((tuple(start_stack_a), tuple(start_stack_b)))

    while queue:
        current_stack_a, current_stack_b, current_sequence = queue.popleft()

        # Check if the target stacks are reached
        if current_stack_a == target_stack_a and current_stack_b == target_stack_b:
            # Save training data
            with open(output_file, "a") as file:
                file.write(f"A: {start_stack_a}, B: {start_stack_b}, C: {target_stack_a}, D: {target_stack_b}, Steps: {len(current_sequence)}, Instructions: {current_sequence}\n")
            return current_sequence

        # Explore all possible instructions
        for instr_name, instr_func in instructions.items():
            new_stack_a = deepcopy(current_stack_a)
            new_stack_b = deepcopy(current_stack_b)

            instr_func(new_stack_a, new_stack_b)  # Apply instruction

            # Avoid revisiting the same stack configuration
            stack_tuple = (tuple(new_stack_a), tuple(new_stack_b))
            if stack_tuple not in visited:
                visited.add(stack_tuple)
                queue.append((new_stack_a, new_stack_b, current_sequence + [instr_name]))

    # If no solution is found
    return None

# Define stack operations
def sa(stack_a, stack_b):
    if len(stack_a) > 1:
        stack_a[0], stack_a[1] = stack_a[1], stack_a[0]

def sb(stack_a, stack_b):
    if len(stack_b) > 1:
        stack_b[0], stack_b[1] = stack_b[1], stack_b[0]

def pa(stack_a, stack_b):
    if stack_b:
        stack_a.insert(0, stack_b.pop(0))

def pb(stack_a, stack_b):
    if stack_a:
        stack_b.insert(0, stack_a.pop(0))

def ra(stack_a, stack_b):
    if stack_a:
        stack_a.append(stack_a.pop(0))

def rb(stack_a, stack_b):
    if stack_b:
        stack_b.append(stack_b.pop(0))

def rra(stack_a, stack_b):
    if stack_a:
        stack_a.insert(0, stack_a.pop())

def rrb(stack_a, stack_b):
    if stack_b:
        stack_b.insert(0, stack_b.pop())

# Map instructions to functions
instructions = {
    "sa": sa,
    "sb": sb,
    "pa": pa,
    "pb": pb,
    "ra": ra,
    "rb": rb,
    "rra": rra,
    "rrb": rrb,
}

def generate_random_stacks(size_a, size_b, max_value):
    """
    Generate random configurations for stacks A and B.

    Args:
        size_a (int): Number of elements in stack A.
        size_b (int): Number of elements in stack B.
        max_value (int): Maximum value for stack elements.

    Returns:
        tuple: Randomly generated stacks A and B.
    """
    elements = random.sample(range(1, max_value + 1), size_a + size_b)
    return elements[:size_a], elements[size_a:]

# Use BFS with random stacks to achieve A sorted and B empty
# Generate random stacks for testing
while True:
	capacity = random.randint(1, 8)
	size_a = random.randint(0, capacity)
	size_b = capacity - size_a
	random_a, random_b = generate_random_stacks(size_a, size_b, capacity)
	size_a = random.randint(0, capacity)
	size_b = capacity - size_a
	target_a, target_b = generate_random_stacks(size_a, size_b, capacity)
	output_file = "dataset"
	print("Random stack A:", random_a)
	print("Random stack B:", random_b)
	print("Target stack A:", target_a)
	print("Target stack B:", target_b)
	result_random_to_sorted = bfs_stack_sort(random_a, random_b, target_a, target_b, instructions, output_file)
	print("Random sequence to achieve A sorted and B empty:", result_random_to_sorted)
