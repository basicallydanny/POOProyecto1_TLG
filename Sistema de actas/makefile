all: compilar clean
compilar: acta criterio detalleActa direccionPos personal view main 
		g++ -o Sistema Acta.o Criterio.o DetalleActa.o DireccionPos.o Personal.o View.o Main.o
acta: Acta.cpp Acta.h DetalleActa.h 
		g++ -c Acta.cpp
criterio: Criterio.cpp Criterio.h
		g++ -c Criterio.cpp
detalleActa: DetalleActa.cpp DetalleActa.h Criterio.h
		g++ -c DetalleActa.cpp
direccionPos: DireccionPos.cpp DireccionPos.h Acta.h Personal.h
		g++ -c DireccionPos.cpp
personal: Personal.cpp Personal.h
		g++ -c Personal.cpp
view: View.cpp View.h DireccionPos.h
		g++ -c View.cpp
main: Main.cpp View.h 
	  g++ -c Main.cpp
clean: #comando para borrar los .o
	@echo "Cleaning compilation..."
	del *.o
