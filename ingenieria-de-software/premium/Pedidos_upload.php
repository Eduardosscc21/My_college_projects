<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_FILES['pdf'])) {
    $uploadDir = 'pedidos/';
    $pdfFile = $uploadDir . basename($_FILES['pdf']['name']);

    if (move_uploaded_file($_FILES['pdf']['tmp_name'], $pdfFile)) {
        header('Location: PedidosU.php'); // Redirige a la página principal
    } else {
        echo 'Error al cargar el PDF.';
    }
}