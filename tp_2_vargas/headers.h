typedef struct
{
    char dni[9];
    char nombre[50];
    int edad;
    int flag_estado;
    int id;
}ePersona;

int getOpcion(int opc);

void obtenerDatosPorTeclado( char mensaje[], char input[]);
int validarSoloLetras(char soloString[]);
int getStringValidado(char mensaje[], char input[]);
int esNumerico(char strInput[]);
int getNumerosString(char mensaje[],char input[]);

void iniciarDatosArray(ePersona arrayP[], int cantElementos, int valor);
int buscarPrimerOcurrencia(ePersona arrayP[], int cantElementos, int valor);
int buscarPorID(ePersona personas[], int cantElementos, int valorInt);
int buscarPorChar(ePersona personas[], int cantElementos, char ValorChar[] );
int buscarDatoByID(ePersona arrayP[], int cantElemetos, int valor[]);//revisar este
int getFreeIndex (ePersona personas[],int cantElementos);//ver este
void hardcodeoPro(ePersona personas[],int cantElementos);
