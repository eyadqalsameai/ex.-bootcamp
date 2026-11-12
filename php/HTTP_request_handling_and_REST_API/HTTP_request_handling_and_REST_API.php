<?php
header("Content-Type: application/json");
$method= $_SERVER['REQUEST_METHOD'];
$headers = getallheaders();
switch($method){
    case "GET":
        echo json_encode(["message" => "GET request received"], JSON_PRETTY_PRINT);
        break;
    case "POST":
        $raw_data = file_get_contents("php://input");
        $parsed_data = json_decode($raw_data, true);
        http_response_code(200);
        echo json_encode([
            "status" => "success",
            "message" => "POST request received successfully",
            "data" => $parsed_data
            ], JSON_PRETTY_PRINT);
        break;
    case "PUT":
        $raw_data = file_get_contents("php://input");
        $parsed_data = json_decode($raw_data, true);
        http_response_code(200);
        echo json_encode([
            "status" => "success",
            "message" => "PUT request received successfully",
            "data" => $parsed_data
            ], JSON_PRETTY_PRINT);
        break;
    case "DELETE":
        echo json_encode(["message" => "DELETE request received"], JSON_PRETTY_PRINT);
        break;
    default:
    http_response_code(405);
    echo json_encode(["error" => "Method not allowed"], JSON_PRETTY_PRINT);
}
?>