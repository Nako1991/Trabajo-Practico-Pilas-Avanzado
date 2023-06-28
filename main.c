#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//Declaracion
void ejercicioNro1();
void ejercicioNro2();
void ejercicioNro3();
void ejercicioNro4();
void ejercicioNro5();
void ejercicioNro6();
void ejercicioNro7();
void ejercicioNro8();
void ejercicioNro9();
void ejercicioNro10();
void ejercicioNro11();
void ejercicioNro12();
void ejercicioNro13();

//EJERCICIOS
//1. Sumar los elementos de una pila (usar variables enteras)
void ejercicioNro1()
{
    //Inicializacion de variables y pilas
    int suma, insertarHasta;
    Pila pila1, aux;
    inicpila(&pila1);
    inicpila(&aux);
    suma = 0;

    //Uso un contador generado aleatoreamente para cargar elementos a pila1
    srand(time(NULL)); //genera la semilla de rand
    insertarHasta = rand()%6+10; //Genera de 10 a 15 elementos
    printf("\nIntroduciendo elementos a la pila pila1...");
    while(insertarHasta > 0)
    {
        printf("\nApilando un nuevo elemento a pila1...");
        apilar(&pila1, rand()%10); //Los elementos tienen valores del 0 al 9
        //printf("\ninsertarHasta: %i", insertarHasta); //debug
        insertarHasta--;
    }
    printf("\n\npila1: ");
    mostrar(&pila1);

    //Sumatoria
    printf("\n\nSumando el tope de cada elemento de la pila1 hasta vaciarla...");
    while ( !pilavacia(&pila1) )
    {
        suma = suma + tope(&pila1);
        //printf("\nsuma: %i", suma); //debug
        apilar(&aux, desapilar(&pila1));
    }

    //Muestra el resultado
    printf("\n\nLa suma de todos los topes es de: %i", suma);
    printf("\n\naux: ");
    mostrar(&aux);
    //printf("\n\npila1: ");
    //mostrar(&pila1);
    printf("\n\nSaliendo del ejercicio...\n");
}

//2. Contar los elementos de una pila (usar variables enteras)
void ejercicioNro2()
{
    //Inicializacion de variables y pilas
    int contador, insertarHasta;
    Pila pila1, aux;
    inicpila(&pila1);
    inicpila(&aux);
    srand(time(NULL));
    contador = 0;

    //Uso un contador generado aleatoreamente para cargar elementos a pila1
    insertarHasta = rand()%6+10; //Genera de 10 a 15 elementos
    printf("\nIntroduciendo elementos a la pila pila1...");
    while(insertarHasta > 0)
    {
        printf("\nApilando un nuevo elemento a pila1...");
        apilar(&pila1, rand()%10); //Los elementos tienen valores del 0 al 9
        //printf("\ninsertarHasta: %i", insertarHasta); //debug
        insertarHasta--;
    }
    printf("\n\npila1: ");
    mostrar(&pila1);

    //Contando
    printf("\n\nContando los elementos de una pila...");
    while ( !pilavacia(&pila1) )
    {
        apilar(&aux, desapilar(&pila1));
        contador++;
    }

    //Muestra el resultado
    printf("\n\nLa cantidad de elementos en pila1 es: %i", contador);
    printf("\n\naux: ");
    mostrar(&aux);
    printf("\n\nSaliendo del ejercicio...\n");
}

//3. Calcular el promedio de los valores de una pila (usar variables)
void ejercicioNro3()
{
    //Inicializacion de variables y pilas
    int contador, insertarHasta;
    float promedio, suma;
    Pila pila1, aux;
    inicpila(&pila1);
    inicpila(&aux);
    contador = 0;
    suma = 0;

    //Uso un contador generado aleatoreamente para cargar elementos a pila1
    srand(time(NULL));
    insertarHasta = rand()%6+10; //Genera de 10 a 15 elementos
    printf("\nIntroduciendo elementos a la pila pila1...");
    while(insertarHasta > 0)
    {
        printf("\nApilando un nuevo elemento a pila1...");
        apilar(&pila1, rand()%10); //Los elementos tienen valores del 0 al 9
        //printf("\ninsertarHasta: %i", insertarHasta); //debug
        insertarHasta--;
    }
    printf("\n\npila1: ");
    mostrar(&pila1);

    //Calculando total de elementos y suma, luego el promedio
    printf("\nCalculando la cantidad de elementos de pila1 y su suma...");
    while ( !pilavacia(&pila1) )
    {
        suma = suma + tope(&pila1);
        contador++;
        apilar(&aux, desapilar(&pila1));
    }

    //Muestra el resultado
    printf("\nCantidad de elementos: %i, suma: %.0f.", contador, suma);
    printf("\nCalculando promedio...");
    promedio = suma / contador * (float)1; //agrego un valor *float* para convertir el lado derecho de la igualdad a un float
    printf("\nEl promedio de todos los topes de pila1 es de: %.2f", promedio);
    printf("\n\naux: ");
    mostrar(&aux);
    printf("\n\nSaliendo del ejercicio...\n");
}

//4. Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables enteras, solo pilas)
void ejercicioNro4()
{
    //Inicializacion de variables y pilas
    int insertarHasta; //Se utiliza para generar la pila aleatoriamente
    Pila pila1, menor, aux;
    inicpila(&pila1);
    inicpila(&menor);
    inicpila(&aux);

    //Uso un contador generado aleatoreamente para cargar elementos a pila1
    srand(time(NULL));
    insertarHasta = rand()%6+10; //Genera de 10 a 15 elementos
    printf("\nIntroduciendo elementos a la pila pila1...");
    while(insertarHasta > 0)
    {
        printf("\nApilando un nuevo elemento a pila1...");
        apilar(&pila1, rand()%10); //Los elementos tienen valores del 0 al 9
        //printf("\ninsertarHasta: %i", insertarHasta); //debug
        insertarHasta--;
    }
    printf("\n\npila1: ");
    mostrar(&pila1);

    //Buscando el menor
    //Creando el menor inicial
    if ( !pilavacia(&pila1) )
    {
        apilar(&menor, desapilar(&pila1));
    }
    //Mientras pila1 tenga al menos un elemento se continua buscando el menor
    printf("\nBuscando el menor valor comparando los topes de pila1 y menor...");
    while ( !pilavacia(&pila1) )
    {
        if ( tope(&pila1) < tope(&menor) )
        {
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(&pila1));
        }
        else
        {
            apilar(&aux, desapilar(&pila1));
        }

        ////Muestra en pantalla las pilas cada vez q se repite el bucle
        ////util para ver el proceso de seleccion
        //printf("\n\nmenor: ");
        //mostrar(&menor);
        //printf("\n\npila1: ");
        //mostrar(&pila1);
        //printf("\n\naux: ");
        //mostrar(&aux);
    }
    printf("\n\nmenor: ");
    mostrar(&menor);
    printf("\n\npila1: ");
    mostrar(&pila1);
    printf("\n\naux: ");
    mostrar(&aux);
    printf("\n\nSaliendo del ejercicio...\n");
}

//5. Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal
//que se conserve el orden. (sin variables enteras, solo pilas)
void ejercicioNro5()
{
    //Inicializacion y pilas
    Pila pila1, elemento, aux, salir, auxsalir;
    inicpila(&pila1);
    inicpila(&elemento);
    inicpila(&aux);
    inicpila(&salir);
    inicpila(&auxsalir);
    //Apila un valor en salir para inicializarlo no vacio
    apilar(&salir, 1);

    //Genera una pila1 de 6 elementos en orden
    printf("\nIntroduciendo elementos a la pila pila1 ordenada de menor(tope) a mayor(base)...");
    apilar(&pila1, 9);
    apilar(&pila1, 7);
    apilar(&pila1, 5);
    apilar(&pila1, 3);
    apilar(&pila1, 3);
    apilar(&pila1, 1);
    printf("\n\npila1: ");
    mostrar(&pila1);


    //Toma un valor del usuario y lo apila en elemento, luego consulta si se desea continuar agregando valores
    do
    {
        printf("\nAgregando un elemento a la pila1. ");
        leer(&elemento); //la pila elemento contiene un elemento y se detiene cuando este se desapila

        //Insertando elemento en la posicion correcta sin alterar el orden de la pila
        while ( !pilavacia(&elemento) )
        {
            if ( tope(&pila1) >= tope(&elemento) )
            {
                apilar(&pila1, desapilar(&elemento));
            }
            else
            {
                apilar(&aux, desapilar(&pila1));
            }

//            //Muestra el proceso en cada bucle, debug
//            printf("\n\npila1: ");
//            mostrar(&pila1);
//            printf("\n\nelemento: ");
//            mostrar(&elemento);
//            printf("\n\naux: ");
//            mostrar(&aux);
        }

        //Volviendo a apilar desde aux a pila1 luego de insertar el elemento
        while ( !pilavacia(&aux) )
        {
            apilar(&pila1, desapilar(&aux));
        }

        printf("\n\npila1: ");
        mostrar(&pila1);

        //puede producirse un error si se ingresan demasiados valores y se llena la pila
        printf("\nDesea seguir agregando elementos? (0 para salir, cualquier otro para continuar): ");
        leer(&salir);
        //Si el tope de salir == 0 entonces se desapila todo salir, y se sale del bucle.
        if ( tope(&salir) == 0)
        {
            while ( !pilavacia(&salir) )
            {
                apilar(&auxsalir, desapilar(&salir));
            }
        }

    }
    while ( !pilavacia(&salir) );

    printf("\n\nSaliendo del ejercicio...\n");
}

//6. Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que
//la segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de
//ordenación por selección.
void ejercicioNro6()
{
    //Inicializacion y pilas
    int insertarHasta; //Se utiliza para generar la pila aleatoriamente
    Pila pila1, menor, mayorAMenor, aux;
    inicpila(&pila1);
    inicpila(&menor);
    inicpila(&mayorAMenor);
    inicpila(&aux);

    //Uso un contador generado aleatoreamente para cargar elementos a pila1
    srand(time(NULL));
    insertarHasta = rand()%6+10; //Genera de 10 a 15 elementos
    printf("\nIntroduciendo elementos a la pila pila1...");
    while(insertarHasta >= 0)
    {
        printf("\nApilando un nuevo elemento a pila1...");
        apilar(&pila1, rand()%10); //Los elementos tiene valores del 0 al 9
        insertarHasta--;
    }
    printf("\n\npila1: ");
    mostrar(&pila1);

    //Ordenando la pila1 de mayor (tope) a menor (base) en mayorAMenor
    //Se hace un bucle que continua mientras haya elementos en aux
    //para asegurarme que hasta el ultimo el elemento sea apilado en mayorAMenor

    do
    {
        //Si aux tiene al menos un elemento volviendo a apilar todo aux a pila1
        if ( !pilavacia(&aux) )
        {
            while ( !pilavacia(&aux) )
            {
                apilar(&pila1, desapilar(&aux));
            }
        }
        //Inicializando el menor
        if ( pilavacia(&menor) && !pilavacia(&pila1) )
        {
            apilar(&menor, desapilar(&pila1));
        }
        //Encontrando el valor menor de este bucle
        while ( !pilavacia(&pila1) )
        {
            //printf("\ncomienzo del loop !pilavacia(&pila1)"); //debug
            if ( tope(&pila1) < tope(&menor) )
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&pila1));
            }
            else
            {
                apilar(&aux, desapilar(&pila1));
            }
        }
        /* //Muestra el proceso en cada bucle, debug
        printf("\nfin del loop !pilavacia(&pila1)");
        printf("\n\npila1: ");
        mostrar(&pila1);
        printf("\n\nmenor: ");
        mostrar(&menor);
        printf("\n\naux: ");
        mostrar(&aux); */
        //Menor encontrado, apilando en mayorAMenor
        printf("menor encontrado: %i, apilando en mayorAMenor...\n", tope(&menor));
        apilar(&mayorAMenor, desapilar(&menor));
    }
    while ( !pilavacia(&aux) );

    printf("\n\nmayorAMenor: ");
    mostrar(&mayorAMenor);

    printf("\n\nSaliendo del ejercicio...\n");
}

//7. Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la
//búsqueda.
void ejercicioNro7()
{
    //Inicializacion y pilas
    int insertarHasta; //Se utiliza para generar la pila aleatoriamente
    Pila pila1, elemento, aux;
    inicpila(&pila1);
    inicpila(&elemento);
    inicpila(&aux);

    //Uso un contador generado aleatoreamente para cargar elementos a pila1
    srand(time(NULL));
    insertarHasta = rand()%3+5; //Genera de 5 a 8 elementos
    printf("\nIntroduciendo elementos a la pila pila1...");
    while(insertarHasta >= 0)
    {
        printf("\nApilando un nuevo elemento a pila1...");
        apilar(&pila1, rand()%10); //Los elementos tiene valores del 0 al 9
        insertarHasta--;
    }
    printf("\n\npila1: ");
    mostrar(&pila1);

    //Que elemento se desea buscar dentro de la pila?
    printf("\nIngrese un valor para buscarlo dentro de pila1.\n");
    leer(&elemento);

    //Busca ese valor dentro de pila
    while ( (tope(&pila1) != tope(&elemento)) && !pilavacia(&pila1) )
    {
        apilar(&aux, desapilar(&pila1));
    }
    //Si salio del bucle significa que:
    //1. Se encontro el valor y los topes son iguales
    //2. No se encontro el valor y pila1 esta vacia
    if ( tope(&pila1) == tope(&elemento) )
    {
        printf("\nSe encontro el elemento dentro de pila1.");
    }
    else if ( pilavacia(&pila1) )
    {
        printf("\nNo se encontro el elemento dentro de pila1.");
    }

    printf("\n\nSaliendo del ejercicio...\n");
}

//8. Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido y dejar el resto en el mismo orden.
void ejercicioNro8()
{
    //Inicializacion y pilas
    int insertarHasta; //Se utiliza para generar la pila aleatoriamente
    Pila pila1, elemento, aux, eliminado, salir, auxsalir;
    inicpila(&pila1);
    inicpila(&elemento);
    inicpila(&aux);
    inicpila(&eliminado);
    inicpila(&salir);
    inicpila(&auxsalir);

    //Uso un contador generado aleatoreamente para cargar elementos a pila1
    srand(time(NULL));
    insertarHasta = rand()%6+10; //Genera de 10 a 15 elementos
    printf("\nIntroduciendo elementos a la pila pila1...");
    while(insertarHasta >= 0)
    {
        printf("\nApilando un nuevo elemento a pila1...");
        apilar(&pila1, rand()%10); //Los elementos tiene valores del 0 al 9
        insertarHasta--;
    }
    printf("\n\npila1: ");
    mostrar(&pila1);

    do
    {
        //Que elemento se desea eliminar dentro de la pila?
        printf("\nIngrese un valor para eliminar dentro de pila1.\n");
        leer(&elemento);

        //Busca ese valor dentro de pila
        while ( (tope(&pila1) != tope(&elemento)) && !pilavacia(&pila1) )
        {
            apilar(&aux, desapilar(&pila1));
        }
        //Si salio del bucle significa que:
        //1. Se encontro el valor y los topes son iguales
        //2. No se encontro el valor y pila1 esta vacia
        if ( tope(&pila1) == tope(&elemento) )
        {
            printf("\nEliminando el elemento de pila...");
            apilar(&eliminado, desapilar(&pila1));
        }
        else if ( pilavacia(&pila1) )
        {
            printf("\nNo se encontro el elemento dentro de pila1.");
        }

        //Vuelvo a apilar todo aux en pila1
        while ( !pilavacia(&aux) )
        {
            apilar(&pila1, desapilar(&aux));
        }

        //Muestro las pilas
        printf("\npila1: ");
        mostrar(&pila1);
        printf("\neliminado: ");
        mostrar(&eliminado);

        //puede producirse un error si se ingresan demasiados valores y se llena la pila
        printf("\nDesea seguir agregando elementos? (0 para salir, cualquier otro para continuar): ");
        leer(&salir);
        //Si el tope de salir == 0 entonces se desapila todo salir, y se sale del bucle.
        if ( tope(&salir) == 0)
        {
            while ( !pilavacia(&salir) )
            {
                apilar(&auxsalir, desapilar(&salir));
            }
        }
    }
    while ( !pilavacia(&salir) );

    printf("\n\nSaliendo del ejercicio...\n");
}

//9. Verificar si una pila dada es capicúa.
void ejercicioNro9()
{
    //Inicializacion y pilas
    int insertarHasta; //Se utiliza para generar la pila aleatoriamente
    Pila dada, dadaInvertida, aux, noEsCapicua, descarte;
    inicpila(&dada);
    inicpila(&dadaInvertida);
    inicpila(&aux);
    inicpila(&noEsCapicua);
    inicpila(&descarte);


    //Uso un contador generado aleatoreamente para cargar elementos a dada
    srand(time(NULL));
    insertarHasta = rand()%2+3; //Genera de 3 a 4 elementos
    printf("\nIntroduciendo elementos a la pila dada...");
    while(insertarHasta >= 0)
    {
        printf("\nApilando un nuevo elemento a dada...");
        apilar(&dada, rand()%3); //Los elementos tiene valores del 0 al 2
        insertarHasta--;
    }
    printf("\n\ndada: ");
    mostrar(&dada);

//    Pila dada capicua ejemplo
//    while ( !pilavacia(&dada) )
//        {
//            apilar(&dada, desapilar(&descarte));
//        }
//    apilar(&dada, 1);
//    apilar(&dada, 2);
//    apilar(&dada, 3);
//    apilar(&dada, 5);
//    apilar(&dada, 3);
//    apilar(&dada, 2);
//    apilar(&dada, 1);
//    printf("\n\ndada: ");
//    mostrar(&dada);

    //Copiando los valores de dada de forma invertida en dadaInvertida.
    printf("\nCopiando los valores de dada de forma invertida en dadaInvertida.");
    while( !pilavacia(&dada) )
    {
        apilar(&dadaInvertida, tope(&dada));
        apilar(&aux, desapilar(&dada));
    }
    //Volviendo a apilar todo aux en dada
    while( !pilavacia(&aux) )
    {
        apilar(&dada, desapilar(&aux));
    }
    printf("\ndada: ");
    mostrar(&dada);
    printf("\ndadaInvertida: ");
    mostrar(&dadaInvertida);

    //Comparando los valores de las pilas dada y dadaInvertida
    //si tienen la misma cantidad de elementos con los mismos topes, las pilas son capicua
    while ( !pilavacia(&dada) && !pilavacia(&dadaInvertida) )
    {
        if ( tope(&dada) == tope(&dadaInvertida) )
        {
            printf("\nLos topes son iguales, desapilando ambas pilas para seguir comparando...");
            apilar(&aux, desapilar(&dada));
            apilar(&aux, desapilar(&dadaInvertida));
        }
        else
        {
            printf("\nLos topes son distintos, las pilas no son capicua.");
            //Apilando noEsCapicua y desapilando una de las pilas completamente para salir del bucle
            apilar(&noEsCapicua, 1); //utilizo una pila como booleano
            while ( !pilavacia(&dada) )
            {
                apilar(&aux, desapilar(&dada));
            }
        }
    }
    //Comparo si el booleano noEsCapicua esta vacio (osea que ningun tope fue distinto)
    if ( pilavacia(&noEsCapicua) )
    {
        printf("\nTodos los topes son iguales, la pila DADA es capicua.");
    }


    printf("\n\nSaliendo del ejercicio...\n");
}

//10. Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos
//sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión.
//A : base 1 2 3 tope
//B: base 2 3 5 7 tope
//Pila AUB = base 3 2 1 7 5 tope
void ejercicioNro10()
{
    //Inicializando pilas
    Pila A, B, AUB, AUXB, AUXAUB, IGUALES, AUXIGUALES; //Utilizo la pila IGUALES como booleano
    inicpila(&A);
    inicpila(&B);
    inicpila(&AUB);
    inicpila(&AUXB);
    inicpila(&AUXAUB);
    inicpila(&IGUALES);
    inicpila(&AUXIGUALES);

    //Cargando datos en A y B
    apilar(&A, 1);
    apilar(&A, 2);
    apilar(&A, 3);
    apilar(&B, 2);
    apilar(&B, 3);
    apilar(&B, 5);
    apilar(&B, 7);
    printf("\nA:");
    mostrar(&A);
    printf("\nB:");
    mostrar(&B);

    //Calculando AUB
    //Copiar todos los elementos de A en AUB, usando AUXB como auxiliar
    printf("\nCopiando todos los elementos de A en AUB...");
    while ( !pilavacia(&A) )
    {
        apilar(&AUB, tope(&A));
        apilar(&AUXB, desapilar(&A));
    }
    //Volver a apilar todo AUXB en A
    while ( !pilavacia(&AUXB) )
    {
        apilar(&A, desapilar(&AUXB));
    }
    printf("\nA:");
    mostrar(&A);
    printf("\nAUB:");
    mostrar(&AUB);

    //Comparo cada tope de B con todos los topes de A
    printf("\nComparando cada tope de B con cada tope de AUB y copiando los que sean distintos...");
    while ( !pilavacia(&B) )
    {
        printf("\nComparando siguiente tope de B...");
        while ( !pilavacia(&AUB) )
        {
            printf("\nComparando siguiente tope de AUB...");
            printf("\nTope B: %i, Tope AUB: %i", tope(&B), tope(&AUB)); //debug
            if ( tope(&B) != tope(&AUB) )
            {
                printf("\nLos topes son distintos.");
                printf("\nApilando AUB en AUXAUB..."); //debug
                apilar(&AUXAUB, desapilar(&AUB));
            }
            else
            {
                printf("\nLos topes son iguales.");
                //printf("\nApilando en IGUALES como booleano..."); //debug
                apilar(&IGUALES, 1); // !pilavacia(&IGUALES) == 1.
                printf("\nApilando AUB en AUXAUB..."); //debug
                apilar(&AUXAUB, desapilar(&AUB));
            }
            //debug
            //printf("\nB:");
            //mostrar(&B);
            //printf("\nAUB:");
            //mostrar(&AUB);
            //printf("\nAUXAUB:");
            //mostrar(&AUXAUB);
        }

        //printf("\nSaliendo del loop while ( !pilavacia(&AUB) )"); //debug
        if ( !pilavacia(&IGUALES) )
        {
            //printf("\nLa pila IGUALES tiene al menos un elemento."); //debug
            printf("\nApilando B en AUXB..."); //debug
            apilar(&AUXB, desapilar(&B));
            while( !pilavacia(&AUXAUB) )
            {
                printf("\nApilando AUXAUB en AUB..."); //debug
                apilar(&AUB, desapilar(&AUXAUB));
            }
        }
        else
        {
            //printf("\nLa pila IGUALES esta vacia."); //debug
            while( !pilavacia(&AUXAUB) )
            {
                printf("\nApilando AUXAUB en AUB..."); //debug
                apilar(&AUB, desapilar(&AUXAUB));
            }
            printf("\n\nCopiando el tope de B en AUB...\n");
            apilar(&AUB, tope(&B));
            printf("\nApilando B en AUXB..."); //debug
            apilar(&AUXB, desapilar(&B));
        }

        //debug
        //printf("\nB:");
        //mostrar(&B);
        printf("\nAUB:");
        mostrar(&AUB);
        //printf("\nAUXAUB:");
        //mostrar(&AUXAUB);
    }

    //printf("\nSaliendo del loop while ( !pilavacia(&B) )"); //debug
    while ( !pilavacia(&AUXB) )
    {
        printf("\nApilando AUXB en B..."); //debug
        apilar(&B, desapilar(&AUXB));
    }
    printf("\nA:");
    mostrar(&A);
    printf("\nB:");
    mostrar(&B);
    printf("\nAUB:");
    mostrar(&AUB);

    printf("\n\nSaliendo del ejercicio...\n");
}

//11. Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando
//el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).
void ejercicioNro11()
{
    int insertarHasta;
    Pila ORDENADA1, ORDENADA2, MENOR1, MENOR2, AUX1, AUX2, ORDENADAFINAL;
    inicpila(&ORDENADA1);
    inicpila(&ORDENADA2);
    inicpila(&MENOR1);
    inicpila(&MENOR2);
    inicpila(&AUX1);
    inicpila(&AUX2);
    inicpila(&ORDENADAFINAL);

    //Uso un contador generado aleatoreamente para cargar elementos a ORDENADA1 y ORDENADA2
    srand(time(NULL));
    insertarHasta = rand()%4+6; //Genera de 6 a 9 elementos
    printf("\nGenerando elementos para las pilas ORDENADA1 y ORDENADA2.");
    printf("\nIntroduciendo elementos a la pila ORDENADA1...");
    while(insertarHasta > 0)
    {
        //printf("\nApilando un nuevo elemento a ORDENADA1...");
        apilar(&ORDENADA1, rand()%10); //Los elementos tienen valores del 0 al 9
        insertarHasta--;
    }
    printf("\nIntroduciendo elementos a la pila ORDENADA2...");
    insertarHasta = rand()%4+6; //Genera de 6 a 9 elementos
    while(insertarHasta > 0)
    {
        //printf("\nApilando un nuevo elemento a ORDENADA2...");
        apilar(&ORDENADA2, rand()%10); //Los elementos tienen valores del 0 al 9
        insertarHasta--;
    }
    printf("\n\nORDENADA1: ");
    mostrar(&ORDENADA1);
    printf("\n\nORDENADA2: ");
    mostrar(&ORDENADA2);

    //Ordenando ambas pilas
    //Ordenando ORDENADA1
    printf("\nOrdenando las pilas ORDENADA1 y ORDENADA2...");
    do
    {
        //Si AUX2 tiene al menos un elemento volviendo a apilar todo AUX2 a ORDENADA1
        if ( !pilavacia(&AUX2) )
        {
            while ( !pilavacia(&AUX2) )
            {
                apilar(&ORDENADA1, desapilar(&AUX2));
            }
        }
        //Inicializando el MENOR1
        if ( pilavacia(&MENOR1) && !pilavacia(&ORDENADA1) )
        {
            apilar(&MENOR1, desapilar(&ORDENADA1));
        }
        //Encontrando el valor MENOR1 de este bucle
        while ( !pilavacia(&ORDENADA1) )
        {
            if ( tope(&ORDENADA1) < tope(&MENOR1) )
            {
                apilar(&AUX2, desapilar(&MENOR1));
                apilar(&MENOR1, desapilar(&ORDENADA1));
            }
            else
            {
                apilar(&AUX2, desapilar(&ORDENADA1));
            }
        }
        apilar(&AUX1, desapilar(&MENOR1));
    }
    while ( !pilavacia(&AUX2) );
    while ( !pilavacia(&AUX1) )
    {
        apilar(&ORDENADA1, desapilar(&AUX1));
    }

    //Ordenando ORDENADA2
    do
    {
        //Si AUX2 tiene al menos un elemento volviendo a apilar todo AUX2 a ORDENADA2
        if ( !pilavacia(&AUX2) )
        {
            while ( !pilavacia(&AUX2) )
            {
                apilar(&ORDENADA2, desapilar(&AUX2));
            }
        }
        //Inicializando el MENOR2
        if ( pilavacia(&MENOR2) && !pilavacia(&ORDENADA2) )
        {
            apilar(&MENOR2, desapilar(&ORDENADA2));
        }
        //Encontrando el valor MENOR2 de este bucle
        while ( !pilavacia(&ORDENADA2) )
        {
            if ( tope(&ORDENADA2) < tope(&MENOR2) )
            {
                apilar(&AUX2, desapilar(&MENOR2));
                apilar(&MENOR2, desapilar(&ORDENADA2));
            }
            else
            {
                apilar(&AUX2, desapilar(&ORDENADA2));
            }
        }
        apilar(&AUX1, desapilar(&MENOR2));
    }
    while ( !pilavacia(&AUX2) );
    while ( !pilavacia(&AUX1) )
    {
        apilar(&ORDENADA2, desapilar(&AUX1));
    }

    //Mostrando las pilas ordenadas
    printf("\nLas pilas fueron ordenadas con exito.");
    printf("\n\nORDENADA1: ");
    mostrar(&ORDENADA1);
    printf("\n\nORDENADA2: ");
    mostrar(&ORDENADA2);

    //Volteando las pilas para trabajar con los valores más altos primero
    printf("\nVolteando las pilas ORDENADAS en AUX1 y AUX2 para trabajar con los topes mas altos...");
    while ( !pilavacia(&ORDENADA1) )
    {
        apilar(&AUX1, desapilar(&ORDENADA1));
    }
    while ( !pilavacia(&ORDENADA2) )
    {
        apilar(&AUX2, desapilar(&ORDENADA2));
    }

    //Mostrando las pilas ordenadas invertidas
    printf("\n\nAUX1: ");
    mostrar(&AUX1);
    printf("\n\nAUX2: ");
    mostrar(&AUX2);

    //Intercalando las pilas en orden creciente
    //Mientras haya al menos un elemento en ambas pilas se comparan los topes, y se apila el mayor
    while ( !pilavacia(&AUX1) && !pilavacia(&AUX2) )
    {
        if ( tope(&AUX1) > tope(&AUX2) )
        {
            apilar(&ORDENADAFINAL, desapilar(&AUX1));
        }
        else
        {
            apilar(&ORDENADAFINAL, desapilar(&AUX2));
        }
    }

    //Cuando una de las pilas se queda sin elementos, se apilan los restantes de ambas a ORDENADAFINAL
    while ( !pilavacia(&AUX1) )
    {
        apilar(&ORDENADAFINAL, desapilar(&AUX1));
    }
    while ( !pilavacia(&AUX2) )
    {
        apilar(&ORDENADAFINAL, desapilar(&AUX2));
    }

    //Mostrando la pila final resultado de intercalar de forma ordenada ambas pilas
    printf("\nLas pilas fueron ordenadas de forma intercalada.");
    printf("\n\nORDENADAFINAL: ");
    mostrar(&ORDENADAFINAL);
}

void ejercicioNro12()
{
    Pila ORIGEN, AUX, ORDENADA;
    inicpila(&ORIGEN);
    inicpila(&AUX);
    inicpila(&ORDENADA);

    //Generacion aleatoria de pila ORIGEN
    int insertarHasta;
    srand(time(NULL));
    insertarHasta = rand()%4+7; //Genera de 7 a 10 elementos
    printf("\nGenerando e introduciendo elementos en ORIGEN...");
    while(insertarHasta > 0)
    {
        apilar(&ORIGEN, rand()%10); //Los elementos tienen valores del 0 al 9
        insertarHasta--;
    }
    printf("\n\nORIGEN: ");
    mostrar(&ORIGEN);

    //Ordenamiento por insercion
    apilar(&ORDENADA, desapilar(&ORIGEN));
    while( !pilavacia(&ORIGEN) )
    {
        printf("\nORIGEN tiene al menos un elemento..."); //debug
        while( ( tope(&ORDENADA) > tope(&ORIGEN) ) && !pilavacia(&ORDENADA) )
        {
            printf("\nORDENADA tiene al menos un elemento y tope(&ORDENADA) > tope(&ORIGEN)..."); //debug
            printf("\nApilando ORDENADA(%i) en AUX(%i)...", tope(&ORDENADA), tope(&AUX)); //debug
            apilar(&AUX, desapilar(&ORDENADA));
        }
        printf("\ntope(&ORDENADA) < tope(&ORIGEN) u ORDENADA esta vacia..."); //debug
        printf("\nApilando ORIGEN(%i) en ORDENADA(%i)...", tope(&ORIGEN), tope(&ORDENADA)); //debug
        apilar(&ORDENADA, desapilar(&ORIGEN));
        while( !pilavacia(&AUX) )
        {
            printf("\nVolviendo a apilar AUX(%i) en ORDENADA(%i)...", tope(&AUX), tope(&ORDENADA)); //debug
            apilar(&ORDENADA, desapilar(&AUX));
        }
        printf("\n\nORIGEN: "); //debug
        mostrar(&ORIGEN); //debug
        printf("\n\nORDENADA: "); //debug
        mostrar(&ORDENADA); //debug
    }

    /*// FORMA COMPRIMIDA / Pilas: ORIGEN, ORDENADA, AUX.
    apilar(&ORDENADA, desapilar(&ORIGEN));
    while( !pilavacia(&ORIGEN) ) {
        while( ( tope(&ORDENADA) > tope(&ORIGEN) ) && !pilavacia(&ORDENADA) ) apilar(&AUX, desapilar(&ORDENADA));
        apilar(&ORDENADA, desapilar(&ORIGEN));
        while( !pilavacia(&AUX) ) apilar(&ORDENADA, desapilar(&AUX));
    } */

    //Volviendo a apilar todo desde ORDENADA a ORIGEN
    printf("\n\nVolviendo a apilar todo desde ORDENADA a ORIGEN");
    while( !pilavacia(&ORDENADA) )
    {
        apilar(&ORIGEN, desapilar(&ORDENADA));
    }

    //Mostrar las pilas procesadas
    printf("\n\nORIGEN: ");
    mostrar(&ORIGEN);
    printf("\n\nORDENADA: ");
    mostrar(&ORDENADA);
}

void ejercicioNro13()
{
    int sumaMano1, sumaMano2, sumaPuntaje1, sumaPuntaje2;
    sumaPuntaje1 = 0;
    sumaPuntaje2 = 0;
    Pila MAZO, MANOJUG1, MANOJUG2, PUNTOSJUG1, PUNTOSJUG2;
    inicpila(&MAZO);
    inicpila(&MANOJUG1);
    inicpila(&MANOJUG2);
    inicpila(&PUNTOSJUG1);
    inicpila(&PUNTOSJUG2);

    //Generacion aleatoria de pila MAZO
    int insertarHasta;
    srand(time(NULL));
    insertarHasta = 24; //Genera 24 elementos
    printf("\nGenerando e introduciendo elementos en MAZO...");
    while(insertarHasta > 0)
    {
        apilar(&MAZO, rand()%10); //Los elementos tienen valores del 0 al 13
        insertarHasta--;
    }
    printf("\n\nMAZO: ");
    mostrar(&MAZO);

    //juego
    while( !pilavacia(&MAZO) || !pilavacia(&MANOJUG1) || !pilavacia(&MANOJUG2) )
    {
        //Repartiendo cartas y sumando los valores
        printf("\nRepartiendo 2 cartas a cada jugador...\n");
        //Dos cartas a cada uno intercaladas
        apilar(&MANOJUG1, desapilar(&MAZO));
        apilar(&MANOJUG2, desapilar(&MAZO));
        sumaMano1 = tope(&MANOJUG1) + tope(&MAZO); //obtengo la suma de los topes antes de apilar
        apilar(&MANOJUG1, desapilar(&MAZO));
        sumaMano2 = tope(&MANOJUG2) + tope(&MAZO); //obtengo la suma de los topes antes de apilar
        apilar(&MANOJUG2, desapilar(&MAZO));
        //Mostrando las manos y el mazo
        printf("\n\nMAZO: ");
        mostrar(&MAZO);
        printf("\nMANOJUG1: ");
        mostrar(&MANOJUG1);
        printf("\nMANOJUG2: ");
        mostrar(&MANOJUG2);

        //Comparando la suma de los puntos de las manos de cada jugador (si es igual gana jugador 1)
        printf("\nLa suma de las cartas de la mano del jugador 1 es: %i", sumaMano1);
        printf("\nLa suma de las cartas de la mano del jugador 2 es: %i", sumaMano2);
        if( sumaMano1 >= sumaMano2 )
        {
            printf("\nEl jugador 1 ha ganado esta ronda, recolectando ambas manos en su pila de puntos...");
            sumaPuntaje1 = sumaPuntaje1 + tope(&MANOJUG1);
            apilar(&PUNTOSJUG1, desapilar(&MANOJUG1));
            sumaPuntaje1 = sumaPuntaje1 + tope(&MANOJUG1);
            apilar(&PUNTOSJUG1, desapilar(&MANOJUG1));
            sumaPuntaje1 = sumaPuntaje1 + tope(&MANOJUG2);
            apilar(&PUNTOSJUG1, desapilar(&MANOJUG2));
            sumaPuntaje1 = sumaPuntaje1 + tope(&MANOJUG2);
            apilar(&PUNTOSJUG1, desapilar(&MANOJUG2));
        }
        else
        {
            printf("\nEl jugador 2 ha ganado esta ronda, recolectando ambas manos en su pila de puntos...");
            sumaPuntaje2 = sumaPuntaje2 + tope(&MANOJUG1);
            apilar(&PUNTOSJUG1, desapilar(&MANOJUG1));
            sumaPuntaje2 = sumaPuntaje2 + tope(&MANOJUG1);
            apilar(&PUNTOSJUG1, desapilar(&MANOJUG1));
            sumaPuntaje2 = sumaPuntaje2 + tope(&MANOJUG2);
            apilar(&PUNTOSJUG1, desapilar(&MANOJUG2));
            sumaPuntaje2 = sumaPuntaje2 + tope(&MANOJUG2);
            apilar(&PUNTOSJUG1, desapilar(&MANOJUG2));
        }

        //Mostrando los puntajes hasta esta ronda
        printf("\nEl jugador 1 tiene %i puntos, el jugador 2 tiene %i puntos.", sumaPuntaje1, sumaPuntaje2);
    }

    if( sumaPuntaje1 > sumaPuntaje2 )
    {
        printf("\n\nEL JUGADOR 1 HA GANADO EL JUEGO!\n");
    }
    else
    {
        printf("\n\nEL JUGADOR 2 HA GANADO EL JUEGO!\n");
    }
}

//MAIN MENU
int main()
{
    int continuar, nroEjercicio;
    continuar = 1; //cuando continuar = 0 se sale del programa

    do
    {
        printf("\nUTN - FR Mar del Plata - Tecnico Universitario en Programacion");
        printf("\n\nProgramacion I y Laboratorio I");
        printf("\n\nTrabajo Practico Nro2: Pilas Avanzado");
        printf("\n\n1. Sumar los elementos de una pila (usar variables enteras)");
        printf("\n\n2. Contar los elementos de una pila (usar variables enteras)");
        printf("\n\n3. Calcular el promedio de los valores de una pila (usar variables)");
        printf("\n\n4. Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables enteras, solo pilas)");
        printf("\n\n5. Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal");
        printf("\nque se conserve el orden. (sin variables enteras, solo pilas)");
        printf("\n\n6. Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que");
        printf("\nla segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama metodo de");
        printf("\nordenacion por seleccion.");
        printf("\n\n7. Determinar si un elemento buscado esta dentro de una pila. Al encontrarlo, finalizar la busqueda.");
        printf("\n\n8. Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido y dejar el resto en el mismo orden.");
        printf("\n\n9. Verificar si una pila DADA es capicua.");
        printf("\n\n10. Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos");
        printf("\nsobre si mismo), realizar un programa que calcule en la pila C la operacion de union.");
        printf("\n\nA : base 1 2 3 tope");
        printf("\n\nB: base 2 3 5 7 tope");
        printf("\n\nPila AUB = base 3 2 1 7 5 tope");
        printf("\n\n11. Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando");
        printf("\nel resultado en una pila tambien ordenada en forma creciente (ORDENADAFINAL).");
        printf("\n\n12. Dada la pila ORIGEN ordenarla en forma ascendente por metodo de insercion dejando el");
        printf("\nresultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.");
        printf("\n\n13. Suponer un juego de cartas en el que en cada mano se reparten dos cartas por jugador. Un");
        printf("\njugador gana la mano cuando la suma de sus cartas es mayor que las del contrario y al");
        printf("\nhacerlo coloca todas las cartas (las de el y las de su rival) en su pila de puntos. En caso de");
        printf("\nempate (y para simplificar) siempre gana el jugador1. Simular la ejecucion del juego de tal");
        printf("\nmanera que dada una pila MAZO (con un numero de elementos multiplo de cuatro)");
        printf("\ndistribuya las cartas en las pilas PUNTOSJUG1 y PUNTOSJUG2 como si estos hubieran");
        printf("\njugado. Utilizar las pilas auxiliares que crea conveniente.");

        printf("\n\nIngrese un numero de ejercicio a ejecutar (0 para salir): ");
        scanf("%i", &nroEjercicio);

        switch(nroEjercicio)
        {
            case 1:
                ejercicioNro1();
                break;
            case 2:
                ejercicioNro2();
                break;
            case 3:
                ejercicioNro3();
                break;
            case 4:
                ejercicioNro4();
                break;
            case 5:
                ejercicioNro5();
                break;
            case 6:
                ejercicioNro6();
                break;
            case 7:
                ejercicioNro7();
                break;
            case 8:
                ejercicioNro8();
                break;
            case 9:
                ejercicioNro9();
                break;
            case 10:
                ejercicioNro10();
                break;
            case 11:
                ejercicioNro11();
                break;
            case 12:
                ejercicioNro12();
                break;
            case 13:
                ejercicioNro13();
                break;
            case 0:
                continuar = 0;
                break;
            default:
                printf("\nEl numero de ejercicio ingresado no es valido.\n\n");
                break;
        }

        if ( continuar != 0 )
        {
            printf("\nEjercicio finalizado, desea continuar ejecutando la guia? (0 para salir): ");
            scanf("%i", &continuar);
        }

    }
    while ( continuar != 0 );

    printf("\n\nSaliendo del programa...\n");
}
