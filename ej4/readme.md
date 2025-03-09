# Justificación

## A, B)

Termine haciendo la misma funcion del a) usando char* y string, me di cuenta que el tiempo de ejecucion de char* es algo menor que el de string, que tiene sentido ya que char* es una estructura mas de bajo nivel que string que es una libreria de C++. Pero no es significativo, por lo que vi usar string es mucho menos "propenso a errores" que char*. Como la diferencia de tiempo es minima, me parece mas conveniente usar string.

Igualmente dejo el codigo con char* para que se pueda ver :p

## C)

Se que dije que string era mas conveniente que char*, pero por lo que busque, no podes usar el string asi nomas en una funcion constexpr, ya que implica alocar memoria dinamicamente, que no tiene sentido cuando queres que se corra en tiempo de compilacion. Podes usar algo que encontre como "String literal" pero no tenia ganas y use un char*.

(Despues de correr el codigo) 
Jajajsa va a las chapas esto, buenisimo. Lo corri un par de veces y la version en tiempo de compilacion es como 18 veces mas rapida que la version normalde char* siempre. Esto tiene sentido ya que toda la logica esta en la compilacion del archivo, una vez que se ejecuta el programa, solo tiene que acceder a un valor ya calculado.