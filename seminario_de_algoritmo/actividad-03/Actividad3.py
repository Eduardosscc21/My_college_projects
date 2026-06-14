
from pydoc import doc
from unittest import case



def cuadrado():
    lado = int(input("Ingrese medida del lado del cuadrado: "))
    area = lado*lado
    print("El area de el rectangulo es: ", area)

def triangulo():
    base = float(input("Ingrese la base : "))
    altura = float(input("ingrese altura : "))
    area = (base*altura)/2
    print("El area es: ", area)
    
def circulo():
    radio = float(input("Cual es el radio del circulo: "))
    Pi = 3.1416
    area = Pi*radio**2
    print("El area del circulo es: ", area)

def obtener_signo(dia_nacimiento, mes_nacimiento):
    signo = ""
    if mes_nacimiento == 1:
        if dia_nacimiento <= 20:
            signo = "Capricornio"
        else:
            signo = "Acuario"
    elif mes_nacimiento == 2:
        if dia_nacimiento <= 18:
            signo = "Acuario"
        else:
            signo = "Piscis"
    elif mes_nacimiento == 3:
        if dia_nacimiento <= 20:
            signo = "Piscis"
        else:
            signo = "Aries"
    elif mes_nacimiento == 4:
        if dia_nacimiento <= 20:
            signo = "Aries"
        else:
            signo = "Tauro"
    elif mes_nacimiento == 5:
        if dia_nacimiento <= 21:
            signo = "Tauro"
        else:
            signo = "Géminis"
    elif mes_nacimiento == 6:
        if dia_nacimiento <= 21:
            signo = "Géminis"
        else:
            signo = "Cáncer"
    elif mes_nacimiento == 7:
        if dia_nacimiento <= 22:
            signo = "Cáncer"
        else:
            signo = "Leo"
    elif mes_nacimiento == 8:
        if dia_nacimiento <= 23:
            signo = "Leo"
        else:
            signo = "Virgo"
    elif mes_nacimiento == 9:
        if dia_nacimiento <= 23:
            signo = "Virgo"
        else:
            signo = "Libra"
    elif mes_nacimiento == 10:
        if dia_nacimiento <= 23:
            signo = "Libra"
        else:
            signo = "Escorpio"
    elif mes_nacimiento == 11:
        if dia_nacimiento <= 22:
            signo = "Escorpio"
        else:
            signo = "Sagitario"
    elif mes_nacimiento == 12:
        if dia_nacimiento <= 21:
            signo = "Sagitario"
        else:
            signo = "Capricornio"
    return signo

def limites():

    limite=float(input("Digite el limite: "))
    n=0
    e=0
    while n<limite:
       e+=1/factorial(n)
       n=n+1
    print("El valor es: ",e) 


def factorial(n):
    factorial = 1
    for i in range(n):
        factorial *= i+1
    return factorial




menu={}
while True:
    print("-----------Menu---------")
    print("[1]------cuadrado-------")
    print("[2]------triangulo------")
    print("[3]------circulo--------")
    print("[4]------zodiaco--------")
    print("[5]------limite---------")
    print("[6]------salir---------")
    
    opc=int(input("seleccione opcion: "))

    if opc==1:
         cuadrado()
    elif opc==2:
         triangulo()
    elif opc==3:
         circulo()
    elif opc==4:
            mes = int(input("Ingresa tu mes de nacimiento [1-12]: "))
            dia = int(input("Ingresa tu día de nacimiento [1-31]: "))
            signo = obtener_signo(dia, mes)
            print(f"Tu signo es {signo}")    
    elif opc==5:
          limites()
    elif opc==6:
        exit(0)      
          


    



