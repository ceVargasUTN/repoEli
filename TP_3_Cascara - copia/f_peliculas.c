#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

void iniciarDatosArray(eMovie arrayM[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i++)
    {
        arrayM[i].flag_estado = valor;
    }
}

int buscarLugarLibre(eMovie arrayM[],int cELEMENTS,int valor)
{
    int i;

    for(i=0; i<cELEMENTS; i++)
    {
        if ((arrayM[i].flag_estado == EMPTY || arrayM[i].flag_estado == DELETED)&& valor == -1)//si  el  estado  es vacio, o borrado, y  ademas el  valor es -1
        {
            return i;
        }
    }

    return -1;

}
void hardcodear(eMovie arrayM[],int cantElementos)
{

    char auxDescripcion[5][500]={"Scott Pilgrim vs. The World —Scott Pilgrim contra el mundo en España y en Hispanoamérica Scott Pilgrim vs. los ex de la chica de sus sueños","Biohazard (バイオハザード Baiohazādo?, ‘Peligro biológico’) —nombre con que se conoce en Japón—, rebautizado en Estados Unidos y Europa como ","Boy meets girl. Boy falls in love. Girl doesn’t. This post modern love story is never what we expect it to be — it’s thorny yet exhilarating, ","Forrest Gump is a 1994 American comedy-drama film based on the 1986 novel of the same name by Winston Groom. The film was directed by Robert Zemeckis","Pulp Fiction (conocida en Latinoamérica como Tiempos violentos) es una película estadounidense de 19941 dirigida por Quentin Tarantino, quien coescribió el guion con Roger Avary. "};
    char auxTitulo[5][20]={"scott pillgrin vs the world","Resident evil","500 days of summer","Forest gump","Pulp fiction"};
    char auxLinkImagen[5][500]={"https://s-media-cache-ak0.pinimg.com/236x/06/7e/55/067e5548ce87ff6f812f3cbc71c15b9c.jpg","http://images4.fanpop.com/image/photos/23100000/Resident-Evil-Movie-resident-evil-movie-23148922-500-400.jpg","http://4.bp.blogspot.com/_WFI8OnZ87YU/TTnitFsCElI/AAAAAAAAAEo/ykY1jwXBSF4/s1600/500-Days-of-Summer-500-days-of-summer-15255319-400-395.jpg","http://www.truthdig.com/images/made/images/cartoonuploads/assortedrom_500_400_322.jpg","http://images4.fanpop.com/image/photos/22100000/Mia-Wallace-pulp-fiction-22137012-500-400.jpg"};
    int auxDuracion[5]={28,22,23,56,30};
    int auxPuntaje[5]={10,5,9,5,10};
    int auxId[5]={1,2,3,4,5};
    char flag_estadoAux[5] = {1,1,1,1,1};

    int i=0;

    for(i==0;i<cantElementos;i++)
    {
        strcpy(arrayM[i].titulo,auxTitulo[i]);
        strcpy(arrayM[i].descripcion,auxDescripcion[i]);
        strcpy(arrayM[i].linkImagen,auxLinkImagen[i]);
        arrayM[i].duracion=auxDuracion[i];
        arrayM[i].flag_estado=flag_estadoAux[i];
        arrayM[i].id_movie=auxId[i];
    }
}
/** \brief Genera un archivo html
 * \param El array de peliculas
 * \param la cantidad de elementos del array
 */


int generarHTML(eMovie *peliculas,int cantElementos)
{
    int i;

    FILE *pArchivo;

    pArchivo=fopen("index.html","w");
    if(pArchivo != NULL)
    {
        fprintf(pArchivo,"<!DOCTYPE html><html>");
        for(i=0; i<cantElementos; i++)
        {

            if(peliculas[i].flag_estado == OCCUPIED)
            {
               // fprintf(parch,"<body bgcolor=rgb(116,116,116)><h1>Titulo: %s </h1>\n\n<h2>Genero: %s</h2>\n\n<h3>Puntaje: %d </h3>\n\n<p>Sinopsis: %s \n\n\n\n</p><img src=%s style='width:304px;height:228px;'>",peliculas[i].titulo,peliculas[i].genero,peliculas[i].puntaje,peliculas[i].descripcion,peliculas[i].linkImagen);
                fprintf(pArchivo, "<article class='col-md-4 article-intro'>");
                fprintf(pArchivo, "<a href='#'>");
                fprintf(pArchivo, "<img class='img-responsive img-rounded' src='%s' alt=''>" , peliculas[i].linkImagen);
                fprintf(pArchivo, "</a><h3><a href='#'>Titulo: %s\n</a></h3>", peliculas[i].titulo);
                fprintf(pArchivo, "<ul><li>Género: %s</li>", peliculas[i].genero);
                fprintf(pArchivo, "<li>Puntaje: %d</li>", peliculas[i].puntaje);
                fprintf(pArchivo, "<li>Duracion: %d</li></ul>", peliculas[i].duracion);
                fprintf(pArchivo, "<p>%s</p>",peliculas[i].descripcion);
                fprintf(pArchivo, "</article>");
            }
        }
        fprintf(pArchivo,"</body></html>");
        fclose(pArchivo);
        return 1;

    }
    return 0;

}

/** \brief Genera un archivo binario
 * \param El array de peliculas
 * \param la cantidad de elementos del array
 */

int generarArchBin(eMovie* arrayP)
{
    FILE* pArch;
    pArch=fopen("bin.dat","ab+");
    if(pArch==NULL)
    {
        printf("Error no hay archivo.");
    }
    else
    {
        fwrite(arrayP,sizeof(eMovie),1,pArch);
        fclose(pArch);
        return 1;

    }

    return 0;
}
