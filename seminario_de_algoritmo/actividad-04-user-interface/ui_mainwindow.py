# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'mainwindow.ui'
##
## Created by: Qt User Interface Compiler version 5.15.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(250, 423)
        MainWindow.setWindowOpacity(500.000000000000000)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.gridLayout_2 = QGridLayout(self.centralwidget)
        self.gridLayout_2.setObjectName(u"gridLayout_2")
        self.groupBox = QGroupBox(self.centralwidget)
        self.groupBox.setObjectName(u"groupBox")
        self.gridLayout = QGridLayout(self.groupBox)
        self.gridLayout.setObjectName(u"gridLayout")
        self.spinBox_4 = QSpinBox(self.groupBox)
        self.spinBox_4.setObjectName(u"spinBox_4")
        self.spinBox_4.setMaximum(255)

        self.gridLayout.addWidget(self.spinBox_4, 4, 1, 1, 1)

        self.label_2 = QLabel(self.groupBox)
        self.label_2.setObjectName(u"label_2")

        self.gridLayout.addWidget(self.label_2, 1, 0, 1, 1)

        self.spinBox_5 = QSpinBox(self.groupBox)
        self.spinBox_5.setObjectName(u"spinBox_5")
        self.spinBox_5.setMaximum(255)

        self.gridLayout.addWidget(self.spinBox_5, 5, 1, 1, 1)

        self.label = QLabel(self.groupBox)
        self.label.setObjectName(u"label")

        self.gridLayout.addWidget(self.label, 0, 0, 1, 1)

        self.label_5 = QLabel(self.groupBox)
        self.label_5.setObjectName(u"label_5")

        self.gridLayout.addWidget(self.label_5, 4, 0, 1, 1)

        self.spinBox = QSpinBox(self.groupBox)
        self.spinBox.setObjectName(u"spinBox")
        self.spinBox.setMaximum(500)

        self.gridLayout.addWidget(self.spinBox, 0, 1, 1, 1)

        self.label_3 = QLabel(self.groupBox)
        self.label_3.setObjectName(u"label_3")

        self.gridLayout.addWidget(self.label_3, 2, 0, 1, 1)

        self.label_4 = QLabel(self.groupBox)
        self.label_4.setObjectName(u"label_4")

        self.gridLayout.addWidget(self.label_4, 3, 0, 1, 1)

        self.spinBox_3 = QSpinBox(self.groupBox)
        self.spinBox_3.setObjectName(u"spinBox_3")
        self.spinBox_3.setMaximum(255)

        self.gridLayout.addWidget(self.spinBox_3, 3, 1, 1, 1)

        self.label_6 = QLabel(self.groupBox)
        self.label_6.setObjectName(u"label_6")

        self.gridLayout.addWidget(self.label_6, 5, 0, 1, 1)

        self.lineEdit = QLineEdit(self.groupBox)
        self.lineEdit.setObjectName(u"lineEdit")

        self.gridLayout.addWidget(self.lineEdit, 2, 1, 1, 1)

        self.spinBox_2 = QSpinBox(self.groupBox)
        self.spinBox_2.setObjectName(u"spinBox_2")
        self.spinBox_2.setMaximum(500)

        self.gridLayout.addWidget(self.spinBox_2, 1, 1, 1, 1)

        self.pushButton = QPushButton(self.groupBox)
        self.pushButton.setObjectName(u"pushButton")

        self.gridLayout.addWidget(self.pushButton, 6, 0, 1, 2)


        self.gridLayout_2.addWidget(self.groupBox, 0, 0, 1, 1)

        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 250, 21))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.groupBox.setTitle("")
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"destino y", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"destino x ", None))
        self.label_5.setText(QCoreApplication.translate("MainWindow", u"green", None))
        self.label_3.setText(QCoreApplication.translate("MainWindow", u"velocidad", None))
        self.label_4.setText(QCoreApplication.translate("MainWindow", u"red", None))
        self.label_6.setText(QCoreApplication.translate("MainWindow", u"blue", None))
        self.pushButton.setText(QCoreApplication.translate("MainWindow", u"Agregar", None))
    # retranslateUi

