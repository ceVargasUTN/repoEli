
typedef struct{
    char cliente_name[50];
    char direccion[50];
    char tipo_urgencia[50];
    int flag_estado;
    int id_entrega;
}eEntrega;

eEntrega* entregas_new(char cliente[], char urgencia[], char direccion[50] );
eEntrega* entregas_alta();
