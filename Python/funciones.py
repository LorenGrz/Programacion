def crear_cliente():
        cuit = input("Introduce el CUIT del cliente: ")
        nombre = input("Introduce el nombre del cliente: ")
        direccion = input("Introduce la dirección del cliente: ")
        telefono = input("Introduce el teléfono del cliente: ")
        correo = input("Introduce el correo electrónico del cliente: ")
        preferente = bool(input("¿Es un cliente preferente? (True/False): "))

        return {"cuit": cuit, "nombre": nombre, "direccion": direccion, "telefono": telefono, "correo": correo, "preferente": preferente}

def mostrar_cliente(cliente):
    print("------------------------------------")
    print("**Datos del cliente**")
    print("------------------------------------")
    print(f"CUIT: {cliente['cuit']}")
    print(f"Nombre: {cliente['nombre']}")
    print(f"Dirección: {cliente['direccion']}")
    print(f"Teléfono: {cliente['telefono']}")
    print(f"Correo electrónico: {cliente['correo']}")
    print(f"Cliente preferente: {'Sí' if cliente['preferente'] else 'No'}")
    print("------------------------------------")

def listar_clientes(clientes):
    print("------------------------------------")
    print("**Listado de clientes**")
    print("------------------------------------")
    for cuit, cliente in clientes.items():
        print(f"CUIT: {cuit}")
        print(f"Nombre: {cliente['nombre']}")
        print("-----------------------")

def listar_clientes_preferentes(clientes):
    print("------------------------------------")
    print("**Listado de clientes preferentes**")