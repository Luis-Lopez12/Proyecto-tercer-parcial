class Celda:
    def __init__(self, mina=False):
        self.mina = mina
        self.abierta = False
        self.marcada = False
        self.numero_minas_alrededor = 0

    def abrir(self):
        self.abierta = True

    def marcar(self):
        self.marcada = not self.marcada
