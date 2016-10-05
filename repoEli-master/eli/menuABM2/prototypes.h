typedef struct
{
    char dni[9];
    char nombre[50];
    int edad;
    int flag_estado;
}ePersona;

int getOpcion(int opc);
void inicializarArrayPersonas(ePersona persona[], int cantElementos, int valor);
int buscarPrimerOcurrencia(ePersona persona[], int cantElementos, int valor);

void altaPersona(ePersona persona, int flagE, int pos);
int obtenerEdad(char mensaje[]);//obtener Int
int validarSoloLetras(char soloString[]);
int obtenerNombreValidado(char mensaje[], char ingresoNombre[] );//obtener string


int getStringNumeros(char mensaje[],char input[]);
