#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Tamaño del array de los contactos del usuario.
#define TAMANO_CONTACTO 10

//Variable global que indica el indice de contactos creados
int posicionContactos = 0;

//Estructura del registro Contacto.
struct Contacto
{
    int codigo; //Falta implementar un codigo autoincremental
    char nombre[40];
    char apellido[40];
    char referencia[40];
    char numeroTelefono[12];
};

//Definición de la estructura Contacto
typedef struct Contacto Contacto;

//Estructura del registro Usuario.
struct Usuario
{
    int codigo; //Falta implementar un codigo autoincremental
    char nombre[40];
    char apellido[40];
    char fechaNacimiento[10];
    Contacto contacto[TAMANO_CONTACTO];
};

//Definición de la estructura Usuario
typedef struct Usuario Usuario;

//Procedimiento usado como utilidad para eliminar los saltos de linea que genera el fgets
void eliminarSaltoLinea(char *cadena){
    if ((strlen(cadena) > 0) && (cadena[strlen(cadena) - 1] == '\n'))
    {
        //Eliminamos la ultima posicion la cual almacena el fgets como un salto de linea y se produce dos veces con el printf
        cadena[strlen(cadena) - 1] = '\0';
    }
}

//Función que retorna un registro Contacto
Contacto registrarContacto()
{

    Contacto contacto;

    printf("\nIngrese el codigo del contacto: ");
    scanf("%i", &contacto.codigo);
    fflush(stdin);

    printf("Ingrese el nombre: ");
    fgets(contacto.nombre, 40, stdin);
    eliminarSaltoLinea(contacto.nombre);
    fflush(stdin);

    printf("Ingrese el apellido: ");
    fgets(contacto.apellido, 40, stdin);
    eliminarSaltoLinea(contacto.apellido);
    fflush(stdin);

    printf("Ingrese la referencia: ");
    fgets(contacto.referencia, 40, stdin);
    eliminarSaltoLinea(contacto.referencia);
    fflush(stdin);

    printf("Ingrese el numero de telefono: ");
    fgets(contacto.numeroTelefono, 12, stdin);
    eliminarSaltoLinea(contacto.numeroTelefono);
    fflush(stdin);

    return contacto;
}

//Función que retorna un registro Usuario
//FALTA MEJORAR LA IMPLEMENTACIÓN DE ESTA FUNCION Y LAS DEMAS PERTENECIENTES A LA ESTRUCTURA USUARIO
Usuario registrarUsuario()
{
    Usuario usuario;

    printf("Ingresa tu codigo: ");
    scanf("%i", &usuario.codigo);
    fflush(stdin);

    printf("Ingrese tu nombre: ");
    fgets(usuario.nombre, 40, stdin);
    eliminarSaltoLinea(usuario.nombre);
    fflush(stdin);

    printf("Ingrese tu apellido: ");
    fgets(usuario.apellido, 40, stdin);
    eliminarSaltoLinea(usuario.apellido);
    fflush(stdin);

    printf("Ingrese la fecha de tu nacimiento: ");
    fgets(usuario.fechaNacimiento, 10, stdin);
    eliminarSaltoLinea(usuario.fechaNacimiento);
    fflush(stdin);

    return usuario;
}

//Procedimiento que a traves de un puntero de tipo Usuario modifica los datos pertenecientes
//al contacto identificado con el codigo proporcionado por el usuario
void editarContacto(Usuario *usuario, int codigoContacto)
{
    int existeContacto = 0;
    //Buscamos si se encuentra el contacto a traves del codigo brindado por el usuaro
    for (int i = 0; i < posicionContactos; i++)
    {
        if (codigoContacto == usuario->contacto[i].codigo)
        {
            printf("Ingrese los nuevos datos del contacto: \n");
            //Si es encontrado, le solicita nuevamente los datos del contacto
            usuario->contacto[i] = registrarContacto();
            printf("\nContacto editado correctamente.\n");
            existeContacto = 1;
        }
    }
    if (existeContacto == 0)
    {
        printf("\nNo se encontro el usuario.\n");
    }
}

//Procedimiento que a traves de un puntero de tipo Usuario elimina el registro perteneciente
//al contacto identificado con el codigo proporcionado por el usuario
void eliminarContacto(Usuario *usuario, int codigoContacto)
{
    int existeContacto = 0;
    //Se busca al contacto
    for (int i = 0; i < posicionContactos; i++)
    {
        //Si se encuentra se hace un intercambio con las siguientes posiciones para eliminar ese registro
        if (codigoContacto == usuario->contacto[i].codigo)
        {
            for (int j = i; j < TAMANO_CONTACTO; j++)
            {
                usuario->contacto[j] = usuario->contacto[j + 1];
            }
            printf("\nContacto eliminado correctamente.\n");
            posicionContactos--;
            existeContacto = 1;
        }
    }
    if (existeContacto == 0)
    {
        printf("\nNo se encontro el usuario.\n");
    }
}

//Imprime todos los contactos que tiene el usuario
void imprimirUsuario(Usuario usuario)
{
    printf("\n%s [beta], tus contactos son:\n", usuario.nombre);
    for (int i = 0; i < posicionContactos; i++)
    {
        printf("Codigo: %i: Nombre: %s. Apellido: %s. Referencia: %s. Numero: %s\n", usuario.contacto[i].codigo, usuario.contacto[i].nombre, usuario.contacto[i].apellido, usuario.contacto[i].referencia, usuario.contacto[i].numeroTelefono);
    }
}

//Procedimiento que representa el menu principal del usuario [FALTAN AJUSTES]
void menuPrincipal(Usuario usuario){
    int decision;
    int codigoUsuario;

    do
    {
        printf("\nQue accion desea realizar? \n1. Agregar contacto. \n2. Visualizar mis contactos. \n3. Editar contacto. \n4. Eliminar contacto. \n0. Salir.\n");
        scanf("%i", &decision);
        fflush(stdin);

        switch (decision)
        {
        case 1:
            usuario.contacto[posicionContactos] = registrarContacto(usuario);
            posicionContactos++;
            printf("\nContacto agregado correctamente.\n");
            break;
        case 2:
            imprimirUsuario(usuario);
            break;
        case 3:
            printf("\nIngrese el codigo del contacto a editar: ");
            scanf("%i", &codigoUsuario);
            editarContacto(&usuario, codigoUsuario);
            break;
        case 4:
            printf("\nIngrese el codigo del contacto a eliminar: ");
            scanf("%i", &codigoUsuario);
            eliminarContacto(&usuario, codigoUsuario);
            break;
        case 0:
            printf("Hasta luego");
            break;
        default:
            printf("Opcion incorrecta\n");
            break;
        }

    } while (decision != 0);
}

int main()
{
    Usuario usuario;
    usuario = registrarUsuario(); //Incompleto, falta agregar la lista de usuarios (tipo login)

    menuPrincipal(usuario);

    return 0;
}