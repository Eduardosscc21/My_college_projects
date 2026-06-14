from PySide2.QtWidgets import QMainWindow,QFileDialog,QMessageBox
from PySide2.QtCore import Slot
from ui_mainwindow import Ui_MainWindow
from particula import Particula
from administrador import Adminisrador

class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow,self).__init__()

        self.administrador=Adminisrador()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.ui.agregar_final_pushButton.clicked.connect(
            self.click_agregar_final)
        self.ui.agregar_inicio_pushButton.clicked.connect(
            self.click_agregar_inicio)
        self.ui.mostar_pushButton.clicked.connect(self.click_mostrar)
        self.ui.actionAbrir.triggered.connect(self.action_abrir_archivo)
        self.ui.actionGuardar.triggered.connect(self.action_guardar_archivo)

    @Slot()
    def action_abrir_archivo(self):
        ubicacion=QFileDialog.getOpenFileName(
            self,
            'Abrir archivo',
            '.',
            'JSON(*.json)'
        )[0]
        print(ubicacion)
        if self.administrador.abrir(ubicacion):
            QMessageBox.information(
                self,
                "Exito",
                "se cargo el archivo" + ubicacion
            )
        else:
            QMessageBox.critical(
                self,
                "Error",
                "Error al abrir el archivo" + ubicacion
            )    
            

    
    @Slot()
    def action_guardar_archivo(self):
        #print('guardar_archivo')
        ubicacion=QFileDialog.getSaveFileName(
            self,
            'Guardar',
            '.',
            'JSON(*.json)'
        )[0]
        print(ubicacion)
        if self.administrador.guardar(ubicacion):
            QMessageBox.information(
                self,
                "Exito",
                "se pudo crear el archivo" + ubicacion
            )
        else:
            QMessageBox.critical(
                self,
                "Error",
                "No se pudo crear el archivo" + ubicacion
            )



    
    @Slot()
    def click_mostrar(self):
        self.ui.salida.clear()
        self.ui.salida.insertPlainText(str(self.administrador))

    @Slot()
    def click_agregar_final(self):
        id = self.ui.id_lineEdit.text()
        origen_x = self.ui.origen_x_spinBox.value()
        origen_y = self.ui.origen_y_spinBox.value()
        destino_x = self.ui.destino_x_spinBox.value()
        destino_y = self.ui.destino_y_spinBox.value()
        velocidad = self.ui.velocidad_spinBox.value()
        red = self.ui.red_spinBox.value()
        green = self.ui.green_spinBox.value()
        blue = self.ui.blue_spinBox.value()
        distancia = self.ui.distancia_spinBox.value()

        particula=Particula(id,origen_x,origen_y,destino_x,destino_y,velocidad,red,green,blue,distancia)
        self.administrador.agregar_final(particula)

    @Slot()
    def click_agregar_inicio(self):
        id = self.ui.id_lineEdit.text()
        origen_x = self.ui.origen_x_spinBox.value()
        origen_y = self.ui.origen_y_spinBox.value()
        destino_x = self.ui.destino_x_spinBox.value()
        destino_y = self.ui.destino_y_spinBox.value()
        velocidad = self.ui.velocidad_spinBox.value()
        red = self.ui.red_spinBox.value()
        green = self.ui.green_spinBox.value()
        blue = self.ui.blue_spinBox.value()
        distancia = self.ui.distancia_spinBox.value()

        particula=Particula(id,origen_x,origen_y,destino_x,destino_y,velocidad,red,green,blue,distancia)
        self.administrador.agregar_inicio(particula)


      


        
