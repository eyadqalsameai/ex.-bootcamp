import re


sql_pattern = re.compile(r"union.*select", re.IGNORECASE)
path_pattern = re.compile(r"\.\./", re.IGNORECASE)
ip_pattern = re.compile(r"\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}")
counters_attack =0
with open('web_log.txt','r') as file:
    for line_num, line in enumerate(file, 1):
        if sql_pattern.search(line):
            attacker_ip = ip_pattern.search(line).group()
            print(f"[ALERT] Attack Type: SQL Injection  | Line: {line_num} | Attacker IP: {attacker_ip}")
            counters_attack +=1
        elif path_pattern.search(line):
            attacker_ip = ip_pattern.search(line).group()
            print(f"[ALERT] Attack Type: Path Traversal | Line: {line_num} | Attacker IP: {attacker_ip}")
            counters_attack +=1

print(f"Total Attacks Detected: {counters_attack}")