<!DOCTYPE html>
<html>
<head>
    <title>Subir y Mostrar PDF</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            text-align: center;
            background-color: #BBE2F3 ;
        }

        .container {
            max-width: 600px;
            margin: 0 auto;
        }

        h1 {
            background-color: #D6A2F4;
            color: white;
            padding: 10px;
        }

        form {
            padding: 20px;
            background-color: #f4f4f4;
            border: 1px solid #D6A2F4;
        }

        .pdf-container {
            margin-top: 20px;
        }
    </style>
</head>
<body>
    <div class="container">
        

        <h1>PDF Disponible</h1>
        <div class="pdf-container">
            <?php
            $pdfDir = 'C:\xampp\htdocs\xampp\proyecto ingenieria de software\validar\Premium\pedidos/';

            $pdfFile = glob($pdfDir . '*.pdf');
            
            if (count($pdfFile) > 0) {
                echo '<embed src="' . $pdfFile[0] . '" type="application/pdf" width="100%" height="600px" />';
            } else {
                echo 'No hay PDF disponible.';
            }
            ?>
        </div>
    </div>
</body>
</html>