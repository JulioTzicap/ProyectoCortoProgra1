/*
Julio Alejandro Tzicap Santiago-202308013
Shairy Anali Gomez Castillo-202308092
Roberto Jose Ramos Lopez-202308021
*/
#include <iostream>//La Biblioteca principal.
#include <string>//Biblioteca para guardar texto.
#include <cstdlib>//Biblioteca para limpiar la pantalla.

using namespace std;
string nombres ( string persona_1, string persona_2){ //Declaramos una función que registre el nombre de los 2 jugadores.
    string jugadores;
    jugadores = persona_1 + "" + persona_2;
    return jugadores;
}
void fichas (int filas){ //Declaramo una función que dibuje las fichas.
    for (int i=1; i<=filas; i++){
        cout<<"|";//Figuras del juego
    }
    cout<<endl;

}
void graficos (int fila_a, int fila_b, int fila_c) {//declarmos una funcion que llamara a la función anterior para dibujar las filas de el juego.
    cout<<"Fila 1:          "; fichas (fila_a);
    cout<<"Fila 2:         "; fichas (fila_b);
    cout<<"Fila 3:        "; fichas (fila_c);
    }
void limpiar (int pantalla){//Función que nos ayuda a limpiar la pantalla cada vez que sea necesario.
 #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux y macOS.
    #endif
}

int main (){
    string jugador_1; string jugador_2; //Variables de los nombres
    int puntos = 0;
    int puntos_2 = 0;
    int limpio = 0;//Variables para limpiar
    int quitar_fila, quitar_ficha;//Variables para seleccionar la fila y eliminar las fichas.
    char tecla;//Variable es para volver a jugar.

    nombres (jugador_1, jugador_2);
    cout<<"Ingrese el nombre del jugador 1: ";
    cin>>jugador_1;
    cout<<"Ingrese el nombre del jugador 2: ";
    cin>>jugador_2;

    do {
        limpiar (limpio);
        puntos = puntos;
        puntos_2 = puntos_2;
        int fila_1=3, fila_2=5, fila_3 = 7; //Variables para los gráficos.
        bool turno_jugador_1 = true;//Variable para verificar que turno corresponde, aqui se usa la variable booleana requerida.

        while (fila_1 + fila_2 + fila_3 > 1){
            if (turno_jugador_1) {
                cout<<"Es turno de: "<<jugador_1<<endl;
                cout<<"Puntos: "<<puntos<<endl;
            } else {
                cout<<"Es turno de: "<<jugador_2<<endl;
                cout<<"Puntos: "<<puntos_2<<endl;
            }
            graficos(fila_1, fila_2, fila_3);
            cout<<"Que fila desea modificar (del 1 al 3): ";
            cin>>quitar_fila;

            //Validación de fila
            while (quitar_fila < 1 || quitar_fila > 3 || (quitar_fila == 1 && fila_1 == 0) || (quitar_fila == 2 && fila_2 == 0) || (quitar_fila == 3 && fila_3 == 0)) {
                cout << "Por favor, ingrese un número válido de fila: ";
                cin >> quitar_fila;
            }

            if (quitar_fila == 1) {
                cout<<"Que ficha desea quitar (1 al "<<fila_1<<") :";
                cin>>quitar_ficha;

                //Validación de ficha.
                while (quitar_ficha < 1 || quitar_ficha > fila_1) {
                    cout << "Por favor, ingrese un número válido de fichas a quitar (1 al " << fila_1 << "): ";
                    cin >> quitar_ficha;
                }

                fila_1 -= quitar_ficha;
            } else if (quitar_fila == 2) {
                cout<<"Que ficha desea quitar (1 al "<<fila_2<<"): ";
                cin>>quitar_ficha;

                //Validación de ficha
                while (quitar_ficha < 1 || quitar_ficha > fila_2) {
                    cout << "Por favor, ingrese un número válido de fichas a quitar (1 al " << fila_2 << "): ";
                    cin >> quitar_ficha;
                }

                fila_2 -= quitar_ficha;
            } else {
                cout<<"Que ficha desea quitar (1 al "<<fila_3<<") :";
                cin>>quitar_ficha;

                //Validación de ficha
                while (quitar_ficha < 1 || quitar_ficha > fila_3) {
                    cout << "Por favor, ingrese un número válido de fichas a quitar (1 al " << fila_3 << "): ";
                    cin >> quitar_ficha;
                }

                fila_3 -= quitar_ficha;
            }

            if((fila_1 + fila_2 + fila_3) > 1){
                turno_jugador_1 = !turno_jugador_1;//Para cambiar de jugador
            }
            cout<<endl;

        }if((fila_1 + fila_2 + fila_3) == 1){
      //Sumatoria cuando gana el jugador 1
            if(turno_jugador_1) {
                graficos(fila_1, fila_2, fila_3);
                cout<<endl;
                cout<<"Victoria de: "<<jugador_1<<endl;
                puntos += 3;
                cout<<"Puntos: "<<puntos<<endl;
                cout<<"Derrota de: "<<jugador_2<<endl;
                cout<<"Puntos: "<<puntos_2<<endl;
    //Sumatoria cuando gana el jugador 2
            } else {
                graficos(fila_1, fila_2, fila_3);
                cout<<endl;
                cout<<"Victoria de: "<<jugador_2<<endl;
                puntos_2 += 3;
                cout<<"Puntos: "<<puntos_2<<endl;
                cout<<"Derrota de: "<<jugador_1<<endl;
                cout<<"Puntos: "<<puntos<<endl;
            }
        //Sumatoria en caso de empate
        } else if((fila_1 + fila_2 + fila_3) == 0) {
            graficos(fila_1, fila_2, fila_3);
            cout<<endl;
            cout<<"Empate"<<endl;
            puntos+= 1;
            puntos_2+=1;
            cout<<"Puntos de: "<<jugador_1<<" son: "<<puntos<<endl;
            cout<<"Puntos de: "<<jugador_2<<" son: "<<puntos_2<<endl;

        }
        cout<<"\nPresione la letra C para continuar jugando.\nO Presione cualquier tecla para salir del juego \nSeguido de su seleccion presione enter\n";
        cin>>tecla;

    }while (tecla=='C' || tecla=='c');
    //Se determina quien es el ganador de la partida
    if (puntos>puntos_2){
        cout<<"\nEl ganador de la partida es "<<jugador_1<<" con un total de "<<puntos<<" puntos."<<endl;
        cout<<"El perdedor de la partida es "<<jugador_2<<" con un total de "<<puntos_2<<" puntos."<<endl;

    }else if (puntos_2>puntos){
         cout<<"\nEl ganador de la partida es "<<jugador_2<<" con un total de "<<puntos_2<<" puntos."<<endl;
         cout<<"El perdedor de la partida es "<<jugador_1<<" con un total de "<<puntos<<" puntos."<<endl;
    }else{
        cout<<"\nAmbos jugadores empataron la partida"<<endl;
        cout<<"El jugador "<<jugador_1<<" con "<<puntos<<" puntos."<<endl;
        cout<<"El jugador "<<jugador_2<<" con "<<puntos_2<<" puntos."<<endl;
    }

    return 0;
}
