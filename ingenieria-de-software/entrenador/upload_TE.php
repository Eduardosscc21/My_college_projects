<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_FILES['video'])) {
    $uploadDir = 'uploadsT/';
    $videoFile = $uploadDir . basename($_FILES['video']['name']);

    if (move_uploaded_file($_FILES['video']['tmp_name'], $videoFile)) {
        header('Location: R_tronco_E.php'); // Redirige a la página tronco
    } else {
        echo 'Error al cargar el video.';
    }
}