<?php

if ($_SERVER['REQUEST_METHOD'] == 'POST' && $_FILES['uploaded_file']){
    if($_FILES['uploaded_file']['size'] <= 2 * 1024 * 1024){
        $accept_extensions = ['jpg', 'png', 'pdf'];
        
        $ext = strtolower(pathinfo($_FILES['uploaded_file']['name'], PATHINFO_EXTENSION));
        
        if (!in_array($ext, $accept_extensions)) {
            die("Error: Invalid file extension!");
        }
        $permitted_content = ['image/jpeg', 'image/png', 'application/pdf'];
        $open_scan = finfo_open(FILEINFO_MIME_TYPE);
        
        $mime = finfo_file($open_scan, $_FILES['uploaded_file']['tmp_name']);
        
        if (!in_array($mime, $permitted_content)) {
            die("Error: Invalid file content!");
        }
        $new_name = bin2hex(random_bytes(16)) .".". $ext;
        $destination = "uploads/" . $new_name;
        if(move_uploaded_file($_FILES['uploaded_file']['tmp_name'], $destination)){
            echo "<h3>" . "File upload successful: " . $new_name ."</h3>";
        }
        else{
            echo "File upload failed";
        }
    }
    else{
        echo "<h4>Error: File size exceeds the permitted limit!.</h3>";
    }
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Uploads File</title>
</head>
<body>
    <form enctype="multipart/form-data" method="POST">
        <input type="file" name="uploaded_file">
        <button type="submit">UPload</button>
    </form>
    
</body>
</html>