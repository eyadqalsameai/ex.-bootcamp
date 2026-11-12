import secrets
import hashlib
import string


alphabet = string.ascii_letters + string.digits + string.punctuation
def generate_password(length):
    password =""
    for i_lenght in range(length):
        password += secrets.choice(alphabet)
    
    return password

def hash_password(password):
    results = hashlib.sha256(password.encode('utf-8')).hexdigest()    
    return results


my_length= 16
my_pass = generate_password(my_length)
my_hash = hash_password(my_pass)

print(f"Your Password Is: {my_pass}")
print(f"Your hash Is: {my_hash}")

