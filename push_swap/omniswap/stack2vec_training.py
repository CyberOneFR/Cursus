import numpy as np
import tensorflow as tf
from collections import deque
from tensorflow.keras import layers, models

#a state is a tuple of (A, B) A and B are stacks of integers

#generate a random state
def generate_state(max_size, max_value):
	capacity = max_size
	a_size = np.random.randint(0, capacity)
	possible_values = np.random.choice(max_value, capacity, replace=False)
	A = possible_values[:a_size]
	B = possible_values[a_size:]
	return (A, B)

def targeted_state(state):
	A, B = state
	A = np.concatenate((A, B))
	A.sort()
	B = []
	return (A, B)

def apply_operation(state, op):
    A, B = state
    if op == 'sa' and len(A) > 1:
        A[0], A[1] = A[1], A[0]
    elif op == 'sb' and len(B) > 1:
        B[0], B[1] = B[1], B[0]
    elif op == 'pa' and len(B) > 0:
        A = [B[0]] + A
        B = B[1:]
    elif op == 'pb' and len(A) > 0:
        B = [A[0]] + B
        A = A[1:]
    elif op == 'ra' and len(A) > 1:
        A = A[1:] + [A[0]]
    elif op == 'rb' and len(B) > 1:
        B = B[1:] + [B[0]]
    elif op == 'rra' and len(A) > 1:
        A = [A[-1]] + A[:-1]
    elif op == 'rrb' and len(B) > 1:
        B = [B[-1]] + B[:-1]
    return (A, B)

def calculate_min_instructions(state):
	target_state = targeted_state(state)
	visited = set()
	queue = deque([(state, 0)])
	while queue:
		current_state, depth = queue.popleft()
		target_key = (tuple(target_state[0]), tuple(target_state[1]))
		current_state_key = (tuple(current_state[0]), tuple(current_state[1]))
		if current_state_key == target_key:
			return depth
		if current_state_key in visited:
			continue
		visited.add(current_state_key)

		for op in ['sa', 'sb', 'pa', 'pb', 'ra', 'rb', 'rra', 'rrb']:
			next_state = apply_operation(current_state, op)
			next_state_key = (tuple(next_state[0]), tuple(next_state[1]))
			if next_state_key not in visited:
				queue.append((next_state, depth + 1))
	return float('inf')

def get_input(state):
	A, B = state
	tA, tB = targeted_state(state)

	capacity = len(tA)
	a_size = len(A)
	b_size = len(B)

	a_distances = [abs(np.where(tA == a)[0][0] - i) for i, a in enumerate(A)]
	b_distances = [abs(np.where(tA == b)[0][0] - (len(A) + i)) for i, b in enumerate(B)]

	avg_a_distance = np.mean(a_distances) if len(a_distances) > 0 else 0
	avg_b_distance = np.mean(b_distances) if len(b_distances) > 0 else 0

	inversions = sum(1 for i in range(len(A)) for j in range(i + 1, len(A)) if A[i] > A[j])

	return np.array([capacity, a_size, b_size, avg_a_distance, avg_b_distance, inversions])


def build_model(input_dim):
    model = models.Sequential([
        layers.Dense(64, input_dim=input_dim, activation='relu'),
        layers.Dense(32, activation='relu'),
        layers.Dense(1)
    ])
    
    model.compile(optimizer='adam', loss='mean_squared_error', metrics=['mae'])
    return model


def generate_training_data(num_samples=100, max_size=5, max_value=1000):
    X_train = []
    y_train = []
    
    for _ in range(num_samples):
        state = generate_state(np.random.randint(1, max_size), max_value)
        features = get_input(state)
        target_instructions = target_instructions(state)
        
        X_train.append(features)
        y_train.append(target_instructions)
    
    return np.array(X_train), np.array(y_train)

state = generate_state(5, 1000)
print(state)
print(targeted_state(state))
print(calculate_min_instructions(state))

# num_samples = 100
# X_train, y_train = generate_training_data(num_samples)
# input_dim = X_train.shape[1]
# model = build_model(input_dim)

# test_state = generate_state(5, 1000)
# test_features = get_input(test_state)
# predicted_instructions = model.predict(np.array([test_features]))
# print(f"Nombre d'instructions prédites pour trier la pile : {predicted_instructions[0][0]}")