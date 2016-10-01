typedef struct {
    char titulo[50];
    char nacionalidad[50];
    char director[50];
    int anio;
    int id_peliculas;
}ePeliculas;

typedef struct {
    char nombre[50];
    char fecha_nac[50];
    char pais_origen[50];
    int id_director;
}eDirectores;

typedef struct{
    int anio;
    int mes;
    int dia;
}eFecha;

int getOpcion(int opc);
void iniciarDatosArray(ePeliculas arrayPeli[], int cantElementos, int valor);

