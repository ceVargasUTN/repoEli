

typedef struct{
    char titulo[50];
    char genero[50];
    char linkImagen[500];
    char descripcion[500];
    int duracion;
    int puntaje;
    int flag_estado;
    int id_movie;
}eMovie;

//FUNCIONES GENERICAS
void obtenerDatosPorTeclado( char mensaje[], char input[]);
int validarSoloLetras(char soloString[]);
int getStringValidado(char mensaje[], char input[]);
int esNumerico(char strInput[]);
int getNumerosString(char mensaje[],char input[]);

//FUNCIONES PELICULAS
void iniciarDatosArray(eMovie arrayM[], int cantElementos, int valor);
void hardcodear(eMovie arrayM[],int cantElementos);
int generarHTML(eMovie *peliculas,int cantElementos);
int generarArchBin(eMovie* arrayP);

//FUNCIONES AMB
int altaPeliculas(eMovie *peliculas,int cantElementos);


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
//int borrarPelicula(eMovie peliculas);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
//void generarPagina(eMovie lista[], char nombre[]);


