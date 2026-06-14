<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_FILES['video'])) {
    $uploadDir = 'uploadsI/';
    $videoFile = $uploadDir . basename($_FILES['video']['name']);

    if (move_uploaded_file($_FILES['video']['tmp_name'], $videoFile)) {
        header('Location: R_tren_inferior_E.php'); // Redirige a la página principade tren inferior
    } else {
        echo 'Error al cargar el video.';
    }
}