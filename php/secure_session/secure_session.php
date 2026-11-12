<?php

session_set_cookie_params([
    'httponly' => true,
    'samesite' => 'Strict'
]);


session_start();
session_regenerate_id(true);
setcookie('unprotected_cookie','Vulnerable_Data');
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Secure Session</title>
</head>
<body>
    <script>
        alert("Cookies seen by JS: " + document.cookie);
    </script>
    <h1>Welcome.</h1>
</body>
</html>