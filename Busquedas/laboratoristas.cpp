#include <bits/stdc++.h> 

using namespace std;

typedef long long int i64;

// El desfase de traduce como ¿Cuantos de agregaron al principio o en que posicion fue a dar el que estaba en el inicio?
i64 desfase = 0;
i64 minStudent = 0;
i64 maxStudent;
i64 n;

vector <long long int> students;

string binarySearch(i64 studentNumber){
    if(students[minStudent] > studentNumber || students[maxStudent] < studentNumber)
        return "No Laurencio";

    i64 start = minStudent;
    i64 end = maxStudent;
    i64 middle;
    
    while(start <= end){
        middle = start + (end - start) / 2;
        if(students[middle] == studentNumber){
            // A el indice donde encontramoe el elemento
            // Le vamos a restar el inicio 
            // O en otras palabras vamos a corregir el desfase
            // De los elementos que borramos al inicio
            middle -= minStudent;
            // Ahora solo hay que corregir con el desfase de movimientos
            middle = (middle + desfase + 1) % n;
            // Si despues del modulo obtuvimos un 0
            // Es porque estamos hasta el final
            if(middle == 0)
                return to_string(n);
            return to_string(middle);
        }

        if(students[middle] > studentNumber){
            end = middle -1;
        }
        if(students[middle] < studentNumber){
            start = middle + 1;
        }
    }
}


void move(i64 pos){
    // Reducimos el tamaño del arreglo(no se hace dinamicamente porque
    // el arreglo fisico nunca se modifica)
    // Si el ultimo se va a mover al inicio
    if(pos == -1){
        // Entonces el desfase se aumenta en 1, ya que va haber 1 estudiante más al frente de la fila
        // Hacemos modulo n, para que en caso de que el desfase se salga del rango de estudiantes no salgamos
        // de los indices del array
        desfase = (desfase + 1) % n;
    }else{
        // En caso de que el desfase sea negativo es porque ahora el primer estudiante se 
        // tendra que ir al final
        desfase -= 1;
        if(desfase < 0)
            desfase = (n - 1);
    }
}

void remove(i64 pos){
    n --;
    // El array reduce de tamaño
    if(pos == 1){
        // Si atendimos al estudiante con el numero más grande
        // entonces el index del ultimo estudiante se resta
        maxStudent--;
        // Si el desfase es diferente de 0 (osea que  hay al menos un estudiante al frente)
        if(desfase != 0)
            desfase--;
        // Le restamos 1 porque eliminamos un estudiante del frente eso quiere decir que el desfase decrece
    }else{
        // Le aumento 1 al indice del minimo student
        minStudent++;
        // Si el desfase en este caso sobrepasa a n, le hacemos modulo n
        // Podria pasar que m = 5 n = 5 esto quiere decir que el primer elemento 
        // Estaba hasta el final
        desfase %= n;
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    students.resize(n);    

    minStudent = 0;
    maxStudent = n - 1;

    for(int i = 0; i < n; ++i){
        cin >> students[i];
    }

    int q;
    cin >> q;
    
    while(q--){
        char opt;
        cin >> opt;

        i64 pos;
        cin >> pos;
        switch (opt){
            case 'M': move(pos); break;
            case 'L': cout << binarySearch(pos) << "\n"; break;
            case 'Q': remove(pos); break;
        }
    }

    return 0;
}