esto solo son notas mentales 

next step when finish ft_printf
1. get next line
Start Study And Understand Get Next Line

1	 what its a macro?
un macro es una regla de sustitución que el compilador aplica antes de compilar el programa es decir:
El preprocesador reemplaza texto por texto.
	Ejemplo básico
#define PI 3.14
	Cuando escribes:
float x = PI;
	El compilador ve realmente:
float x = 3.14;
	otro ejemplo
#define BUFFER_SIZE 42
	Esto significa:
Cada vez que lea del archivo, leeré 42 bytes como máximo
	Y cuando escribes:
read(fd, buffer, BUFFER_SIZE);
	En realidad el compilador ve:
read(fd, buffer, 42);


2	 how i can use buffer?
Un buffer es un espacio de memoria temporal donde guardas datos mientras los procesas, puese ser un malloc o un calloc o un strdup o un array, la diferencia entre buffer y el stash es que el buffer es temporal el stash es persistente, el buffer vive en la funcion el stash vive entre llamadas, el buffer se sobre escribe el stash se conserva, el buffer trae datos el stash guarda restos


3	 how use read good?
4	why its necessary static? 
es necesario ya que es la memoria persistente

5	 what functions auxiliary i need use?
las funciones que necesitare estan en la libft pero como no puedo usar mi libreria las hare localmente en el file de ultis  

6	 whats stash?
el stash es donde se guarda lo no leido, osea gnl solo trabaja hasta el salto de lina por ejemplo si tengo hola\nmundo\ncomo\nesta read lee hola y en el stash se queda mundo, cuando lo volvamos a llamar como ya leyo hola, ahora lee mundo y en el stash queda como y asi hasta que se null o 0.
	¿Qué guardas exactamente en el stash?
Guardo únicamente el contenido leído que está después del salto de línea, para usarlo en la siguiente llamada ejemplos.
	ABC\nDEF\nGHI
read = "ABC\n"
stash = "ABC\n"
return "ABC\n"
stash = ""
	second call
read = "DEF\n"
stash = "DEF\n"
return "DEF\n"
stash = ""
	third call
read → "GHI"
stash = "GHI"
return "GHI"
stash = NULL
	think mental
1. Tengo un stash
2. Leo del fd
3. Añado lo leído al stash
4. Si hay '\n':
       - corto una línea
       - guardo el resto
       - devuelvo la línea
5. Si no hay '\n' y hay EOF:
       - devuelvo lo que quede
6. Si no hay nada:
       - devuelvo NULL


9 	MAYBE try whit structs MAYBE 
typedef struct s_gnl
{
    char    *stash;
}   t_gnl;
cada vez que llamamos a nuetra funcion empieza de cero, pero t_gnl sigue teniendo lo que guardo antes, asi que para manejar bien esa memoria voy a obtar en usar structuras para alli almacenar el stash y asi no liarme esto creo que puede ser clave y una forma sencilla de hacerlo, teniendo en cuenta que las estructuras ya las manejamos con las listas enlazadas, Usar un struct nos permite mantener todos los datos relacionados a un descriptor en un solo lugar, así GNL puede recordar lo que queda por leer entre llamadas y manejar varios archivos al mismo tiempo de forma segura.
Sin struct: variables globales, difícil mantenimiento, riesgo de errores.
Con struct: datos encapsulados, fácil de mantener, (multi-fd preparado - a lo mejor con esto me he colado pero vamos viendo).
en resumen tratar de hacer el gnl lo mas sencillo posible



8	 control that need 
* memory leaks
* free final stash
* segfaults
* need control of the read == -1
* get line whiteout \n when exist 