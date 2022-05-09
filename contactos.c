#include<stdio.h>
#include<conio.h>
#include<string.h>

#define TAMANO_USU 10

int posicion = 0;

struct Contacto{
    int codigo;
    char nombre[40];
    char apellido[40];
    char referencia[40];
    char numeroTelefono[12];
};

struct Usuario{
    int codigo;
    char nombre[40];
    char apellido[40];
    char fechaNacimiento[100];
    struct Contacto contacto[TAMANO_USU];
};

struct Contacto registrarContacto(){

    struct Contacto contacto;

    printf("\nIngrese el codigo del contacto: ");
    scanf("%i", &contacto.codigo);
    fflush(stdin);

    printf("Ingrese el nombre: ");
    scanf("%s", &contacto.nombre);
    fflush(stdin);

    printf("Ingrese el apellido: ");
    scanf("%s", &contacto.apellido);
    fflush(stdin);

    printf("Ingrese la referencia: ");
    scanf("%s", &contacto.referencia);
    fflush(stdin);

    printf("Ingrese el numero de telefono: ");
    scanf("%s", &contacto.numeroTelefono);
    fflush(stdin);

    return contacto;
}

struct Usuario registrarUsuario(){
    struct Usuario usuario;

    printf("Ingrese el codigo del usuario: ");
    scanf("%i", &usuario.codigo);
    fflush(stdin);

    printf("Ingrese el nombre: ");
    scanf("%s", &usuario.nombre);
    fflush(stdin);

    printf("Ingrese el apellido: ");
    scanf("%s", &usuario.apellido);
    fflush(stdin);

    printf("Ingrese la fecha de nacimiento: ");
    scanf("%s", &usuario.fechaNacimiento);
    fflush(stdin);

    return usuario;
}

void imprimirUsuario(struct Usuario usuario){
    printf("\n%s, tus contactos son:\n", usuario.nombre);
    for(int i=0; i<posicion; i++){
        printf("Codigo: %i: Nombre: %s. Apellido: %s. Referencia: %s. Numero: %s\n", usuario.contacto[i].codigo, usuario.contacto[i].nombre, usuario.contacto[i].apellido, usuario.contacto[i].referencia, usuario.contacto[i].numeroTelefono);
    }
}

int main(){

    struct Usuario usuario;

    usuario = registrarUsuario();

    int decision;

    do{
        printf("\nQue accion desea realizar? \n1. Agregar contacto. \n2. Visualizar mis contactos. \n0. Salir.\n");
        scanf("%i", &decision);
        fflush(stdin);

        switch (decision)
        {
        case 1:
            usuario.contacto[posicion] = registrarContacto(usuario);
            posicion++;
            printf("\nContacto agregado correctamente.\n");
            break;
        case 2:
            imprimirUsuario(usuario);
            break;
        case 0:
            printf("Hasta luego");
            break;
        default:
            printf("Opcion incorrecta\n");
            break;
        }

    }while(decision!=0);

    return 0;
}
