from funciones import *

def main():

    clientes = {}


    while True:

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