# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'printui.ui'
##
## Created by: Qt User Interface Compiler version 5.14.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import (QCoreApplication, QMetaObject, QObject, QPoint,
    QRect, QSize, QUrl, Qt,SIGNAL)
from PySide2.QtGui import (QBrush, QColor, QConicalGradient, QFont,
    QFontDatabase, QIcon, QLinearGradient, QPalette, QPainter, QPixmap,
    QRadialGradient)
from PySide2.QtWidgets import *
import sys

PortsList     = []
PinsList      = []
ModeList      = []
InitialValue  = []
Ports          = ["PORTA","PORTA","PORTA","PORTA","PORTA","PORTA","PORTA","PORTA","PORTB","PORTB","PORTB","PORTB","PORTB","PORTB","PORTB","PORTB","PORTC","PORTC","PORTC","PORTC","PORTC","PORTC","PORTC","PORTC","PORTD","PORTD","PORTD","PORTD","PORTD","PORTD","PORTD","PORTD",]
Pins      = ["PIN0","PIN1","PIN2","PIN3","PIN4","PIN5","PIN6","PIN7","PIN0","PIN1","PIN2","PIN3","PIN4","PIN5","PIN6","PIN7","PIN0","PIN1","PIN2","PIN3","PIN4","PIN5","PIN6","PIN7","PIN0","PIN1","PIN2","PIN3","PIN4","PIN5","PIN6","PIN7"]

class Ui_Form(object):
    def setupUi(self, Form):
        if Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(657, 422)
        self.Pin0_GroupBox = QGroupBox(Form)
        self.Pin0_GroupBox.setObjectName(u"Pin0_GroupBox")
        self.Pin0_GroupBox.setGeometry(QRect(150, 30, 491, 231))
        self.Mode__GroupBox = QGroupBox(self.Pin0_GroupBox)
        self.Mode__GroupBox.setObjectName(u"Mode__GroupBox")
        self.Mode__GroupBox.setGeometry(QRect(10, 40, 120, 131))
        self.Output_radioButton = QRadioButton(self.Mode__GroupBox)
        self.Output_radioButton.setObjectName(u"Output_radioButton")
        self.Output_radioButton.setGeometry(QRect(10, 40, 97, 20))
        self.Input__radioButton = QRadioButton(self.Mode__GroupBox)
        self.Input__radioButton.setObjectName(u"Input__radioButton")
        self.Input__radioButton.setGeometry(QRect(10, 80, 97, 20))
        self.Input__radioButton.setChecked(True)
        self.OutputConfig_GroupBox = QGroupBox(self.Pin0_GroupBox)
        self.OutputConfig_GroupBox.setObjectName(u"OutputConfig_GroupBox")
        self.OutputConfig_GroupBox.setEnabled(False)
        self.OutputConfig_GroupBox.setGeometry(QRect(160, 40, 311, 61))
        self.High_radioButton = QRadioButton(self.OutputConfig_GroupBox)
        self.High_radioButton.setObjectName(u"High_radioButton")
        self.High_radioButton.setGeometry(QRect(10, 30, 97, 20))
        self.Low_radioButton = QRadioButton(self.OutputConfig_GroupBox)
        self.Low_radioButton.setObjectName(u"Low_radioButton")
        self.Low_radioButton.setGeometry(QRect(160, 30, 97, 20))
        self.Low_radioButton.setChecked(True)
        self.InputConfig_GroupBox = QGroupBox(self.Pin0_GroupBox)
        self.InputConfig_GroupBox.setObjectName(u"InputConfig_GroupBox")
        self.InputConfig_GroupBox.setGeometry(QRect(160, 110, 311, 61))
        self.PullUp_radioButton = QRadioButton(self.InputConfig_GroupBox)
        self.PullUp_radioButton.setObjectName(u"PullUp_radioButton")
        self.PullUp_radioButton.setGeometry(QRect(10, 30, 97, 20))
        self.HighImpedance_radioButton = QRadioButton(self.InputConfig_GroupBox)
        self.HighImpedance_radioButton.setObjectName(u"HighImpedance_radioButton")
        self.HighImpedance_radioButton.setGeometry(QRect(160, 30, 131, 20))
        self.HighImpedance_radioButton.setChecked(True)
        self.PinName_lineEdit = QLineEdit(self.Pin0_GroupBox)
        self.PinName_lineEdit.setObjectName(u"PinName_lineEdit")
        self.PinName_lineEdit.setEnabled(False)
        self.PinName_lineEdit.setGeometry(QRect(10, 190, 181, 22))
        self.DefaultName_checkBox = QCheckBox(self.Pin0_GroupBox)
        self.DefaultName_checkBox.setObjectName(u"DefaultName_checkBox")
        self.DefaultName_checkBox.setGeometry(QRect(210, 190, 101, 20))
        self.DefaultName_checkBox.setChecked(True)
        self.OutputPath_lineEdit = QLineEdit(Form)
        self.OutputPath_lineEdit.setObjectName(u"OutputPath_lineEdit")
        self.OutputPath_lineEdit.setGeometry(QRect(60, 280, 341, 31))
        self.Generate_pushButton = QPushButton(Form)
        self.Generate_pushButton.setObjectName(u"Generate_pushButton")
        self.Generate_pushButton.setGeometry(QRect(420, 280, 93, 28))
        self.PinName_Compobox = QComboBox(Form)
        self.PinName_Compobox.addItem(str())
        self.PinName_Compobox.addItem(str())
        self.PinName_Compobox.addItem(str())
        self.PinName_Compobox.addItem(str())
        self.PinName_Compobox.addItem(str())
        self.PinName_Compobox.addItem(str())
        self.PinName_Compobox.addItem(str())
        self.PinName_Compobox.addItem(str())
        self.PinName_Compobox.setObjectName(u"PinName_Compobox")
        self.PinName_Compobox.setGeometry(QRect(20, 130, 111, 31))
        self.PortName_Compobox = QComboBox(Form)
        self.PortName_Compobox.addItem(str())
        self.PortName_Compobox.addItem(str())
        self.PortName_Compobox.addItem(str())
        self.PortName_Compobox.addItem(str())
        self.PortName_Compobox.setObjectName(u"PortName_Compobox")
        self.PortName_Compobox.setGeometry(QRect(20, 70, 111, 31))
        self.saveChanges_pushButton = QPushButton(Form)
        self.saveChanges_pushButton.setObjectName(u"saveChanges_pushButton")
        self.saveChanges_pushButton.setGeometry(QRect(20, 190, 111, 31))

        self.retranslateUi(Form)
        QObject.connect(self.DefaultName_checkBox,SIGNAL("clicked(bool)"), self.PinName_lineEdit.setDisabled)
        QObject.connect(self.Output_radioButton,SIGNAL("clicked(bool)"),self.OutputConfig_GroupBox.setEnabled)
        QObject.connect(self.Output_radioButton,SIGNAL("clicked(bool)"), self.InputConfig_GroupBox.setDisabled)
        QObject.connect(self.Input__radioButton,SIGNAL("clicked(bool)"), self.InputConfig_GroupBox.setEnabled)
        QObject.connect(self.Input__radioButton,SIGNAL("clicked(bool)"), self.OutputConfig_GroupBox.setDisabled)

        self.saveChanges_pushButton.clicked.connect(self.SaveFunction)
        self.Generate_pushButton.clicked.connect(self.GenerateFunction)

        QMetaObject.connectSlotsByName(Form)
    # setupUi
    def SaveFunction(self):
        PortsList.append(self.PortName_Compobox.currentText()+'_'+self.PinName_Compobox.currentText())
        #print(PortsList[0])
        #PinsList.append(self.PinName_Compobox.currentText())
        if self.Output_radioButton.isChecked():
            if self.High_radioButton.isChecked():
                    ModeList.append("OUTPUT")
                    InitialValue.append("OUTPUT_HIGH")

            else:                                                   
                    ModeList.append("OUTPUT")
                    InitialValue.append("OUTPUT_LOW")

        else:
            if self.PullUp_radioButton.isChecked():
                    ModeList.append("INPUT")
                    InitialValue.append("PULL_UP_RESISTANCE")

            else:             
                    ModeList.append("INPUT")
                    InitialValue.append("HIGH_IMPEDANCE")


    def GenerateFunction(self):
        MFIC_Handler = open(self.OutputPath_lineEdit.text() + r'\MFIC.h','w')
        DIO_Handler = open(self.OutputPath_lineEdit.text() + r'\DIO_Config.h','w')
        for i in range(0,31):
          lastIndex=-1
          for j in range(0,len(PortsList)):
            if(str(Ports[i]+'_'+Pins[i]) == PortsList[j]):
                lastIndex=j
          if(lastIndex != -1):
            DIO_Handler.write('#define '+PortsList[lastIndex]+'_DIR                       '+ModeList[lastIndex] +'\n')
            DIO_Handler.write('#define '+PortsList[lastIndex]+'_INITIAL_VALUE             '+InitialValue[lastIndex] +'\n\n')

          DIO_Handler.write('#define '+Ports[i]+'_'+Pins[i]+'_DIR                       '+'INPUT\n')
          DIO_Handler.write('#define '+Ports[i]+'_'+Pins[i]+'_INITIAL_VALUE             '+'HIGH_IMPEDANCE\n\n')
            
        MFIC_Handler.close()
        DIO_Handler.close()

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"SimpleTool", None))
        self.Pin0_GroupBox.setTitle(QCoreApplication.translate("Form", u"Pin Configuration", None))
        self.Mode__GroupBox.setTitle(QCoreApplication.translate("Form", u"Mode", None))
        self.Output_radioButton.setText(QCoreApplication.translate("Form", u"Output", None))
        self.Input__radioButton.setText(QCoreApplication.translate("Form", u"Input", None))
        self.OutputConfig_GroupBox.setTitle(QCoreApplication.translate("Form", u"Output Configuration", None))
        self.High_radioButton.setText(QCoreApplication.translate("Form", u"High", None))
        self.Low_radioButton.setText(QCoreApplication.translate("Form", u"Low", None))
        self.InputConfig_GroupBox.setTitle(QCoreApplication.translate("Form", u"input Configuration", None))
        self.PullUp_radioButton.setText(QCoreApplication.translate("Form", u"Pull Up", None))
        self.HighImpedance_radioButton.setText(QCoreApplication.translate("Form", u"High Impedance", None))
        self.PinName_lineEdit.setText(QCoreApplication.translate("Form", u"Enter Pin Name", None))
        self.DefaultName_checkBox.setText(QCoreApplication.translate("Form", u"Default Name", None))
        self.OutputPath_lineEdit.setText(QCoreApplication.translate("Form", u"Enter Output Path", None))
        self.Generate_pushButton.setText(QCoreApplication.translate("Form", u"Generate", None))
        self.PinName_Compobox.setItemText(0, QCoreApplication.translate("Form", u"PIN0", None))
        self.PinName_Compobox.setItemText(1, QCoreApplication.translate("Form", u"PIN1", None))
        self.PinName_Compobox.setItemText(2, QCoreApplication.translate("Form", u"PIN2", None))
        self.PinName_Compobox.setItemText(3, QCoreApplication.translate("Form", u"PIN3", None))
        self.PinName_Compobox.setItemText(4, QCoreApplication.translate("Form", u"PIN4", None))
        self.PinName_Compobox.setItemText(5, QCoreApplication.translate("Form", u"PIN5", None))
        self.PinName_Compobox.setItemText(6, QCoreApplication.translate("Form", u"PIN6", None))
        self.PinName_Compobox.setItemText(7, QCoreApplication.translate("Form", u"PIN7", None))

        self.PortName_Compobox.setItemText(0, QCoreApplication.translate("Form", u"PORTA", None))
        self.PortName_Compobox.setItemText(1, QCoreApplication.translate("Form", u"PORTB", None))
        self.PortName_Compobox.setItemText(2, QCoreApplication.translate("Form", u"PORTC", None))
        self.PortName_Compobox.setItemText(3, QCoreApplication.translate("Form", u"PORTD", None))

        self.saveChanges_pushButton.setText(QCoreApplication.translate("Form", u"Save", None))
    # retranslateUi

app = QApplication(sys.argv)
Widget = QWidget()
Form = Ui_Form()
Form.setupUi(Widget)
Widget.show()
app.exec_()