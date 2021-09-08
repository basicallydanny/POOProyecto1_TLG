# POOProyecto1_TLG

### Integrantes :adult: Juan Manuel Triana :adult: Jose Miguel López :woman: Daniela Gómez
 
## Enunciado :grey_exclamation:	

La dirección de los posgrados en ingeniería de software de la Pontificia Universidad Javeriana Cali quiere hacer un sistema de información que facilite la calificación de los trabajos de grado de maestría cuando los estudiantes realizan su sustentación pública. La directora espera que el sistema entregue un archivo de texto con los resultados de la 
calificación obtenida por el estudiante y los comentarios relacionados con la evaluación. Esta evaluación se registra en un acta de evaluación que es diligenciada normalmente durante una sesión de discusión luego de la sustentación  y está compuesta por:

- *Informacion General*: número, fecha, autor, nombre del trabajo, tipo de trabajo ( 1. Aplicado, 2. Investigación ), director, 
codirector (algunas veces existe un codirector), jurado 1, jurado 2.

- *Criterios de evaluación*: Actualmente son 8 criterios de evaluación pero podrían extenderse en el futuro. Cada criterio tiene:
    - Un identificador
    - Un texto que se presenta a los evaluadores.
    - Un porcentaje de ponderación definido y ajustado por la dirección de los posgrados.

- La *calificación* del jurado número 1 y la calificación del jurado número dos y los comentarios específicos para el criterio. 

- El acta permite incluir *observaciones adicionales* y *comentarios específicos* sobre las condiciones para la aprobación del trabajo final.

## :speech_balloon: Requisitos por Casos de Uso
### Asistente puede:
-	Crear una nueva acta con informacion base 
-	Ver la informacion de las actas creadas
### Jurado puede:
-	Evaluar y registrar lo evaluado en una tesis
-	Escribir observaciones para cada criterio
-	Saber la nota final del trabajo (aprovado o rechazado)
-	Ver la informacion de las actas creadas
- Exportar la informacion de las actas
### Director puede:
-	Modificar descripcion y peso de criterios de evaluacion
-	Ver el resumen de las actas creadas 
  - número del acta, la fecha, nombre del estudiante, estado, nota, nombre de los jurados y director.

## :white_circle: Requisitos Funcionales
-	:heavy_check_mark: Aquí especificaríamos los métodos que utilizamos para cumplir los requisitos



