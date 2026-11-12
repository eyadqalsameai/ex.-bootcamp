import hashlib
import time

def calculate_file_hash(filepath):
    hasher = hashlib.sha256()
    with open(filepath, 'rb') as file:
        while True:
            chunk = file.read(4096)
            if not chunk:
                break
            hasher.update(chunk)
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
