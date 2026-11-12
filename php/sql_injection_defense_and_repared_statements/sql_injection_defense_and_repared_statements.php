<?php
$pdo = new PDO("sqlite::memory:");
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

$pdo->exec("CREATE TABLE users (id INTEGER PRIMARY KEY, username TEXT, role TEXT)");
$pdo->exec("INSERT INTO users (username, role) VALUES ('admin', 'SuperAdmin')");
$pdo->exec("INSERT INTO users (username, role) VALUES ('user', 'Analyst')");

$username = $_GET['username'] ?? 'user';
$mode = $_GET['mode'] ?? 'insecure';

$sql = "SELECT * FROM users WHERE username = '$username'";
$stmt = $pdo->query($sql);

foreach($stmt as $stmte){
    echo "Welcome $username , Your Role Is: " . $stmte['role'] . "<br>";
}

$secure_sql = "SELECT * FROM users WHERE username = ? ";
$stmt_secure = $pdo->prepare($secure_sql);
$stmt_secure->execute([$username]);
foreach ($stmt_secure as $stmte_secure){
    echo "Welcome $username , Your Role Is: " . $stmte_secure['role'] . "<br>";
}
?>