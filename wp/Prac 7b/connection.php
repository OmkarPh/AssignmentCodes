<?php
    $host = "localhost";
    $user = "root";
    $passowrd = "root1234";
    $db = "college";
    $con = mysqli_connect($host,$user,$passowrd,$db);
    if(!$con){
        die("Could not connect to MySQL: " . mysqli_connect_error());
    }
    // $showtables = mysqli_query($con, "SHOW TABLES FROM $db");
    // while($table = mysqli_fetch_array($showtables)) {
    //     echo($table[0] . "<br>");
    // }
    $alltuples = mysqli_query($con, "SELECT * FROM student");
    while($row = mysqli_fetch_array($alltuples)) {
        echo($row['stuId'] . " ");
        echo($row['lastName'] . "\n");
    }

    try {
        mysqli_query($con, "INSERT INTO student values(110, 'JOHN', null)");
    }
    catch(Exception $e) {
        // echo nl2br("already present");
    }

?>