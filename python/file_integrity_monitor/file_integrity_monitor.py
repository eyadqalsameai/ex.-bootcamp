import hashlib
import time

def calculate_file_hash(filepath):
    hasher = hashlib.sha256()
    with open(filepath, 'rb') as file:
        file_data = file.read()
        hasher.update(file_data)
    return hasher.hexdigest()

target_file = "test_fim.txt"
baseline_hash = calculate_file_hash(target_file)

print(f"Surveillance has begun: {baseline_hash}")

while True:
    time.sleep(3)
    current_hash = calculate_file_hash(target_file)
    if current_hash != baseline_hash:
        print("Critical Alert: File has been modified.")
        baseline_hash = current_hash
