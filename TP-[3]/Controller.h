// JUGADORES
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador); //
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador); //

int controller_agregarJugador(LinkedList* pArrayListJugador); //
int controller_editarJugador(LinkedList* pArrayListJugador); //
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion); //

int controller_listarJugadores(LinkedList* pArrayListJugador);//

int controller_ordenarJugadoresYSelecciones(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion); //

int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador); //
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador); //


// SELECCION
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion); //
int controller_editarSeleccion(LinkedList* pArrayListSeleccion); // checkear

int controller_listarSelecciones(LinkedList* pArrayListSeleccion ); //

int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);//

// ------------ CONTROLLERS AGREGADOS --------------- //

// MENUS
int controller_MunuEdit(); //
int controller_MunuListar(); //
int controller_MunuListarPorOrden(); //
int controller_MunuConvocar(); //

// LISTAR
int controller_listado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion); //
int controller_listarConvocados( LinkedList* pArrayListJugador); //

// CONVOCAR
int controller_Convocar ( LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//

int controller_filterConfederaciones(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion); //

// ID
/// @brief busca el id DE un Jugador
///
/// @param pArrayListJugador
/// @param id
/// @return
int controller_BuscarID( LinkedList* pArrayListJugador, int id );

/// @brief busca un id de Seleccion
///
/// @param pArrayListSeleccion
/// @param id
/// @return
int controller_BuscarIDSeleccion( LinkedList* pArrayListSeleccion, int id );

/// @brief obtengo una id del archivo
///
/// @param pId
/// @return 1 ok, 0 error
int controller_JugadorID(int* pId );

/// @brief actualizo la id maxima del archivo
///
/// @param id
/// @return 1 ok, 0 error
int controller_NewID(int id);

/// @brief Guarda la id maxima pasada por el puntero pId en el archivo en forma binaria
///
/// @param pFile
/// @param path
/// @param pArrayListJugador
/// @return 1 ok, o error
int controller_guardarID ( FILE* pFile, char* path, LinkedList* pArrayListJugador );

/// @brief busco el id maxima y la guardo en el puntero pID
///
/// @param pFile
/// @param pArrayListJugador
/// @param pID
/// @return 1 ok , 0 error
int controller_BuscarMayorID ( FILE* pFile, LinkedList* pArrayListJugador, int* pID );
