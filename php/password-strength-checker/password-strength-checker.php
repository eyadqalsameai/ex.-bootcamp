<?php
function Password_verification_traditional_method($password){
    $password_lenght = strlen($password);
    $password_is_upper = false;
    $password_is_lower = false;
    $password_is_digits = false;
    $password_is_symbols = false;

    if($password_lenght >= 8){
        for($i=0;$i < $password_lenght;$i++){
            if(ctype_digit($password[$i])){
                $password_is_digits =true;
            }
            if(ctype_upper($password[$i])){
                $password_is_upper =true;
            }
            if(ctype_lower($password[$i])){
                $password_is_lower =true;
            }
            if(ctype_punct($password[$i])){
                $password_is_symbols =true;
            }

        }

    }
    $score_password = 0;
    if($password_is_digits) $score_password++;
    if($password_is_lower) $score_password++;
    if($password_is_symbols) $score_password++;
    if($password_is_upper) $score_password++;

    return $score_password;
}



$password = "78%^HFJefjfkjfjk";
$resultes = Password_verification_traditional_method($password);
if($resultes  <2 ){ 
    echo "Password $password is weak!";
}
elseif($resultes >= 2 && $resultes <= 3){
    echo "Password $password is medium!";
}
else {
    
    echo "Password $password is strong!";
}
?>
<br>
<?php
function checker_password($password){
    $password_length = strlen($password);

    if ($password_length < 8) {
        return false;
    }

    $password_is_digits  = preg_match('/[0-9]/', $password);
    $password_is_upper   = preg_match('/[A-Z]/', $password);
    $password_is_lower   = preg_match('/[a-z]/', $password);
    $password_is_symbols = preg_match('/[^A-Za-z0-9]/', $password);

    $accepted_pass = $password_is_digits && $password_is_lower && $password_is_symbols && $password_is_upper;
    
    return $accepted_pass;
}

$password = "5%^HFJefjfkjfjk";
$results = checker_password($password);

if ($results) {
    echo "Password $password is accepted!";
} else {
    echo "Password $password is not accepted!";
}
?>