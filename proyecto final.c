#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>

#define Tam_Nom 10

void gotoxy(int x, int y);
void clearScreen();
int opcion();
void registrarEstudiante();
void verInfoEstudiante();
void borrarRegistroAcademico();


int main(){
	system("color 1");
	
	switch(opcion()){
		case 1:
			registrarEstudiante();
			break;
		case 2:
			verInfoEstudiante();
			break;
		case 3:
			borrarRegistroAcademico();
			break;
		case 4:
			gotoxy(35,12);
			printf("GRACIAS POR UTILIZAR NUESTRO SISTEMA");			
	}
}
void gotoxy(int x, int y)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hConsole, dwPos);
}
void clearScreen() {
    system("cls");
}
int opcion(){
	int opc;
	
	gotoxy(35,6);
	printf("1- Registrar un estudiante\n");
	gotoxy(35,7);
	printf("2- Ver informacion de un estudiante\n");
	gotoxy(35,8);
	printf("3- Borrar registro academico\n");
	gotoxy(35,9);
	printf("4- Salir\n");
	gotoxy(35,10);
	printf("Elija una opcion: ");
	scanf("%d", &opc);	
	return opc;
}
void registrarEstudiante(){
	clearScreen();
	int doc, registro, archivo;
    char nombre[Tam_Nom];
    float matematicas;
    float quimica;
    float biologia;
    float informatica;
    float promedio;
	
	gotoxy(30, 0);
    printf("I E Las margaritas");
		
	gotoxy(1, 2);
	printf("numero de documento: ");
	scanf("%d", &doc);    
		
    gotoxy(20, 7);
    printf("Nombre");
    gotoxy(20, 8);
    scanf("%s", &nombre);

    gotoxy(30, 7);
    printf("Matematicas");
    gotoxy(34, 8);
    scanf("%f", &matematicas);
    while (matematicas < 0 || matematicas > 5)
    {
        gotoxy(30, 7);
        printf("Matematicas");
        gotoxy(34, 8);
        scanf("%f", &matematicas);
    }
		
    gotoxy(43, 7);
    printf("Quimica");
    gotoxy(45, 8);
    scanf("%f", &quimica);
    while (quimica < 0 || quimica > 5)
    {
        gotoxy(43, 7);
        printf("Quimica");
        gotoxy(45, 8);
        scanf("%f", &quimica);
    }
		
    gotoxy(53, 7);
    printf("Biologia");
    gotoxy(55, 8);
    scanf("%f", &biologia);
    while (biologia < 0 || biologia > 5)
    {
        gotoxy(53, 7);
        printf("Biologia");
        gotoxy(55, 8);
        scanf("%f", &biologia);
    }
		
    gotoxy(63, 7);
    printf("Informatica");
    gotoxy(67, 8);
    scanf("%f", &informatica);
    while (informatica < 0 || informatica > 5)
    {
        gotoxy(63, 7);
        printf("Informatica");
        gotoxy(67, 8);
        scanf("%f", &informatica);
    }
	
    gotoxy(77, 7);
    printf("promedio");
    gotoxy(78, 8);
    promedio = matematicas + quimica + biologia + informatica / 4;
    printf("%.2f", promedio);
    int cont = 1;	    
	FILE *file = fopen("registro.txt", "a"); // Abre el archivo para escribir 

    if (file == NULL)
    {
        printf("Error al abrir el archivo!\n");
    }

    // Escribe la informacion en el archivo 
    fprintf(file, "\nNumero de documento: %d\n", doc);
    fprintf(file, "Nombre: %s\n", nombre);
    fprintf(file, "Matematicas: %.2f\n", matematicas);
    fprintf(file, "Quimica: %.2f\n", quimica);
    fprintf(file, "Biologia: %.2f\n", biologia);
    fprintf(file, "Informatica: %.2f\n", informatica);
    fprintf(file, "Promedio: %.2f\n", promedio);

    do
    {
        gotoxy(50, 5);
        printf("desea registrar otro estudiante ¿? (1-SI o 2-NO): ");
        scanf("%d", &registro);

        if (registro == 2)
        {
            break;
        }
		gotoxy(1, 2); //1: cuantos  espacios a la derecha 2: cuantos espacios hacia abajo
		printf("numero de documento: ");
		scanf("%d", &doc); 
		
        gotoxy(20, 8 + cont);
        scanf("%s", &nombre);

        gotoxy(34, 8 + cont);
        scanf("%f", &matematicas);
        while (matematicas < 0 || matematicas > 5)
        {
            gotoxy(34, 8 + cont);
            scanf("%f", &matematicas);
        }

        gotoxy(45, 8 + cont);
        scanf("%f", &quimica);
        while (quimica < 0 || quimica > 5)
        {
            gotoxy(45, 8 + cont);
            scanf("%f", &quimica);
        }

        gotoxy(55, 8 + cont);
        scanf("%f", &biologia);
        while (biologia < 0 || biologia > 5)
        {
            gotoxy(55, 8 + cont);
            scanf("%f", &biologia);
        }

        gotoxy(67, 8 + cont);
        scanf("%f", &informatica);
        while (informatica < 0 || informatica > 5)
        {
            gotoxy(67, 8 + cont);
            scanf("%f", &informatica);
        }

        gotoxy(78, 8 + cont);
        promedio = matematicas + quimica + biologia + informatica / 4;
        printf("%.2f", promedio);

        // escribe la informacion en el archivo 
        fprintf(file, "\nNumero de documento: %d\n", doc);
        fprintf(file, "Nombre: %s\n", nombre);
        fprintf(file, "Matematicas: %.2f\n", matematicas);
        fprintf(file, "Quimica: %.2f\n", quimica);
        fprintf(file, "Biologia: %.2f\n", biologia);
        fprintf(file, "Informatica: %.2f\n", informatica);
        fprintf(file, "Promedio: %.2f\n", promedio);

        cont++;
    } while (registro == 1);

    fclose(file); // Cierre de archivo 

    gotoxy(35, 14);
    printf("Quieres guardar el archivo en un archivo de texto (1-SI o 2-NO): ");
    scanf("%d", &archivo);
    
    printf("\nPresione cualquier tecla para continuar...");
    getch();
    		
	printf("Para ingresar nuevamente al menu ingrese una de las opciones");
    system("cls");
            
	switch(opcion()){
		case 1:
			registrarEstudiante();
			break;
		case 2:
			verInfoEstudiante();
			break;
		case 3:
			borrarRegistroAcademico();
			break;
		case 4:
			gotoxy(35,12);
			printf("GRACIAS POR UTILIZAR NUESTRO SISTEMA");
	}
}
void verInfoEstudiante(){
	int documento;
    char nombre[Tam_Nom];
    float matematicas;
    float quimica;
    float biologia;
    float informatica;
    float promedio;
	
	
    clearScreen();
	printf("Numero de Documento: ");
	scanf("%d",&documento);
	
    // Buscar y mostrar informacion del estudiante por numero de documento
    FILE *archivo = fopen("registro.txt", "r");
	if (archivo != NULL) {
    	char linea[100];
    	int encontrado = 0;

	    while (fgets(linea, sizeof(linea), archivo) != NULL) {
			if (strstr(linea, "Numero de documento:") != NULL && atoi(strstr(linea, ":") + 1) == documento) {
				gotoxy(5,2);
	            printf("%s", linea);
	            fgets(linea, sizeof(linea), archivo);  // Saltar la linea de Promedio
	            gotoxy(5,3);
	            printf("%s", linea);
	            fgets(linea, sizeof(linea), archivo);
	            gotoxy(5,4);
	            printf("%s", linea);
	            fgets(linea, sizeof(linea), archivo);
	            gotoxy(5,5);
	            printf("%s", linea);
	            fgets(linea, sizeof(linea), archivo);
	            gotoxy(5,6);
	            printf("%s", linea);
	            fgets(linea, sizeof(linea), archivo);
	            gotoxy(5,7);
	            printf("%s", linea);
	            fgets(linea, sizeof(linea), archivo); 
	            gotoxy(5,8);
	            printf("%s", linea);
	            fgets(linea, sizeof(linea), archivo);																		            
	            encontrado = 1;
				}
	    	}
	
	        if (!encontrado) {
	            printf("No se encontro informacion para el estudiante con el numero de documento %d\n", documento);
	        }
	
	        fclose(archivo);
        }
		else {
        	printf("Error al abrir el archivo para leer la informacion.\n");
        }
        printf("\nPresione cualquier tecla para continuar...");
    	getch();
    		
		printf("Para ingresar nuevamente al menu ingrese una de las opciones");
        system("cls");
            
		switch(opcion()){
			case 1:
				registrarEstudiante();
				break;
			case 2:
				verInfoEstudiante();
				break;
			case 3:
				borrarRegistroAcademico();
				break;
			case 4:
				gotoxy(35,12);
				printf("GRACIAS POR UTILIZAR NUESTRO SISTEMA");
		}
}
void borrarRegistroAcademico() {
    int documento;
        
    printf("Ingrese el numero de documento: ");
    scanf("%d", &documento);

    // Buscar y borrar información del estudiante por número de documento
    FILE *archivo = fopen("registro.txt", "r");
    if (archivo != NULL) {
        FILE *archivoTemp = fopen("registro_temp.txt", "w");
        if (archivoTemp != NULL) {
            char linea[100];
            int encontrado = 0;

            while (fgets(linea, sizeof(linea), archivo) != NULL) {
                if (strstr(linea, "Numero de documento:") == NULL || atoi(strstr(linea, ":") + 2) != documento) {
                    fprintf(archivoTemp, "%s", linea);
                } else {
                    encontrado = 1;
                    // Saltar líneas adicionales correspondientes a la información del estudiante
                    int lineasInfo = 6; // Número de líneas adicionales a saltar (nombre, nota, etc.)
                    while (lineasInfo > 0 && fgets(linea, sizeof(linea), archivo) != NULL) {
                        lineasInfo--;
                    }
                }
            }

            fclose(archivo);
            fclose(archivoTemp);

            remove("registro.txt");
            rename("registro_temp.txt", "registro.txt");

            if (encontrado) {
                printf("El registro academico del estudiante con el numero de documento %d ha sido eliminado.\n", documento);
            } else {
                printf("No se encontro informacion para el estudiante con el numero de documento %d.\n", documento);
            }
            printf("\nPresione cualquier tecla para continuar...");
    		getch();
    		
			printf("Para ingresar nuevamente al menu ingrese una de las opciones");
            system("cls");
            
			switch(opcion()){
				case 1:
					registrarEstudiante();
					break;
				case 2:
					verInfoEstudiante();
					break;
				case 3:
					borrarRegistroAcademico();
					break;
				case 4:
					gotoxy(35,12);
					printf("GRACIAS POR UTILIZAR NUESTRO SISTEMA");					
			}
        }
    }
}
