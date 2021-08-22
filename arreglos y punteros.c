#include <stdio.h>
#include <string.h>
#define MAX_ACCOUNTS 10


struct Account{ //Inicializar estructura para cuentas

	int numero;
	int monto;
	char nombre[20];
	char telefono[10];
	char email[50];
};

int selection;
int accountNumero=1;
int continueRunning=1;
int mainMenu();

int main(){ //Sentencias generales para las diferentes opciones del menu

	struct Account accountsArray[MAX_ACCOUNTS];

	while(continueRunning == 1){ //Loop para continuar corriendo hasta que el usuario lo indique
	selection = mainMenu();

	switch(selection){
		case 1: //Ver listado de cuentas
			printf("\n\n========= Ver cuentas en su banco =========\n\n");
			for(int i=0; i<MAX_ACCOUNTS; i++){
				printf("%d",accountsArray[i].numero);
				printf("%d",accountsArray[i].monto);
				printf("%s",accountsArray[i].nombre);
				printf("%s",accountsArray[i].telefono);
				printf("%s",accountsArray[i].email);
				printf("\n----------------\n");
			}

        break;
			
		case 2: //Crear una nueva cuenta
			printf("\n\n========= Crear una cuenta =========\n\n");
			char contactName[20];
			char contactTelephone[10];
			char contactEmail[50];
			accountsArray[accountNumero].numero = accountNumero;
			printf("\nNombre: ");
			scanf("%s", &accountsArray[accountNumero].nombre);
			printf("Telefono: ");
			scanf("%s", &accountsArray[accountNumero].telefono);
			printf("Email: ");
			scanf("%s", &accountsArray[accountNumero].email);
			printf("Monto: ");
			scanf("%d", &accountsArray[accountNumero].monto);

			printf(accountsArray[accountNumero].nombre);
			accountNumero++;
        break;
			
		case 3: //Editar detalles de la entrada de una cuenta 
			printf("\n\n========= Editar detalles de cuenta =========\n\n");

			int editAccNumber;
			printf("introduzca el numero de cuenta: ");
			scanf("%d", &editAccNumber);
			printf("\nLa cuenta pertenece a: %s",accountsArray[editAccNumber].nombre);

			printf("\n\nEdit Nombre: ");
			scanf("%s", &accountsArray[editAccNumber].nombre);
			printf("\n\nEditar monto: ");
			scanf("%d", &accountsArray[editAccNumber].monto);
			printf("\nEditar telefono: ");
			scanf("%s", &accountsArray[editAccNumber].telefono);
			printf("\nEditar Email: ");
			scanf("%s", &accountsArray[editAccNumber].email);

			printf("\nLa cuenta fue editada satisfactoriamente: %s",accountsArray[editAccNumber].nombre);

        break;
        
		case 4: //Buscador de cuentas creadas anteriormente
			printf("\n\n========= Buscar cuenta =========\n\n");

			int searchAccNumber;
			printf("Introduzca el numero de cuenta: ");
			scanf("%d", &searchAccNumber);
			printf("\nLa cuenta pertenece a: %s\n",accountsArray[searchAccNumber].nombre);

			printf("\nNumero de cuenta: ");
			printf("%d",accountsArray[searchAccNumber].nombre);
			printf("\nCuenta: ");
			printf("%d",accountsArray[searchAccNumber].monto);
			printf("\nNombre: ");
			printf("%s", accountsArray[searchAccNumber].nombre);
			printf("\nTelefono: ");
			printf("%s", accountsArray[searchAccNumber].telefono);
			printf("\nEmail: ");
			printf("%s", accountsArray[searchAccNumber].email);
			printf("\n----------------\n");

        break;
        
		case 5: //Eliminar una entrada o cuenta de usuario
			printf("\n\n========= Elimine una cuenta =========\n\n");

			int deleteAccNumber;
			printf("Introduzca el numero de cuenta: ");
			scanf("%d", &deleteAccNumber);
			printf("\nKa cuenta pertenece a: %s",accountsArray[deleteAccNumber].nombre);
			printf("\nEliminacion de cuenta satisfactoria");

			strcpy(accountsArray[deleteAccNumber].nombre, "");
			strcpy(accountsArray[deleteAccNumber].telefono, "");
			strcpy(accountsArray[deleteAccNumber].email, "");
			accountsArray[deleteAccNumber].monto=0;

			break;
			
		case 6: //Finaliza el loop y termina el programa
			printf("\n\n========= Salir del sistema =========\n\n");
			continueRunning=0;
			break;
			
		default:
			break;
	}
}

}

int mainMenu(){ //Menu principal da la bienvenida al usuario y regresa el valor seleccionado a la subfuncion main
	int select;
	printf("\n\n========= Sistema de gestion bancaria simple =========\n\n");
	printf("[1] Ver cuentas");
	printf("\n[2] Agregar cuenta");
	printf("\n[3] Editar cuenta");
	printf("\n[4] Buscar cuenta");
	printf("\n[5] Eliminar cuenta");
	printf("\n[6] Salir");

	printf("\n\nIntroduzca la seleccionada: ");
	scanf("%d",&select);

	return select;
}
