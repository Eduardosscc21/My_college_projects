from algoritmos import distancia_euclidiana
from particula import Particula


class Adminisrador:
    def __init__(self):
        self.__particulas = []

    def agregar_final(self, particula: Particula):
        self.__particulas.append(particula)

    def agregar_inicio(self, particula: Particula):
        self.__particulas.insert(0, particula)

    def mostrar(self):
        for particula in self.__particulas:
            print(particula)




l01 = Particula(id=11, origen_x=10, origen_y=10, destino_x=20, destino_y=30, velocidad=200, red=1,
                green=3, blue=7, distancia=distancia_euclidiana)
l02 = Particula(id=22, origen_x=8, origen_y=10, destino_x=28, destino_y=18, velocidad=100, red=3,
                green=6, blue=12, distancia=distancia_euclidiana)
particulas = Adminisrador()
particulas.agregar_inicio(l01)
particulas.agregar_final(l02)
particulas.mostrar()
