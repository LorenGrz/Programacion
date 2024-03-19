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

def main():
    clientes = {}
    opcion = 0

    while opcion != 6:
            # Mostrar el menú al usuario
        print("------------------------------------")
        print("**Gestión de base de datos de clientes**")
        print("------------------------------------")
        print("1. Añadir cliente")
        print("2. Eliminar cliente")
        print("3. Mostrar cliente")
        print("4. Listar todos los clientes")
        print("5. Listar clientes preferentes")
        print("6. Terminar")
        print("------------------------------------")

        opcion = int(input("Introduce una opción"))

        if opcion < 1 or opcion > 6:
            print("Opción no válida. Inténtalo de nuevo.")
        
        if opcion == 1:
            # Añadir un nuevo cliente
            nuevo_cliente = crear_cliente()
            clientes[nuevo_cliente["cuit"]] = nuevo_cliente
            print("Cliente añadido correctamente.")

        elif opcion == 2:
            # Eliminar un cliente
            cuit = input("Introduce el CUIT del cliente a eliminar: ")
            if cuit in clientes:
                del clientes[cuit]
                print("Cliente eliminado correctamente.")
            else:
                print(f"No se encuentra ningún cliente con el CUIT {cuit}.")

        elif opcion == 3:
            # Mostrar los datos de un cliente
            cuit = input("Introduce el CUIT del cliente a mostrar: ")
            if cuit in clientes:
                mostrar_cliente(clientes[cuit])
            else:
                print(f"No se encuentra ningún cliente con el CUIT {cuit}.")

        elif opcion == 4:
            # Listar todos los clientes
            listar_clientes(clientes)

        elif opcion == 5:
            # Listar los clientes preferentes
            listar_clientes_preferentes(clientes)

        elif opcion == 6:
            # Terminar el programa
            print("¡Hasta pronto!")
            break
            
main()
