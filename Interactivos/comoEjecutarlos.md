# Como hacer pruebas con los problemas interactivos

## Linux/MacOS
* Extrae todos los archivos a una carpeta y abre la terminal y dirígete a la carpeta donde extrajiste los archivos.
* Se recomienda que tengas instalados los siguientes paquetes: make, gcc, g++, fpc, python y openjdk-7-jdk.
* Escribe make para compilar todos los programas que necesitas y make run para ejecutar tu código. Recuerda que el validador espera una entrada en la consola, así que debes ya sea escribirla o pasársela como archivo (make run
  < entrada.in).
* Para probar tu solución con un caso de prueba, escribe make test. Esto es equivalente a correr make run < examples/sample.in.

## Windows 

* Extrae todos los archivos a una carpeta, abre la consola y dirígete a la carpeta donde extrajiste los archivos.

* Debes tener instalado Code::Blocks (asegúrate de bajar la versión que dice MinGW) y haberlo ejecutado al menos una vez.
   * Si quieres usar C o C++, simplemente abre el archivo de proyecto de Code::Blocks que viene incluido en la carpeta que acabas de extraer. Puedes ignorar el resto de los pasos. Para intentar otros casos de prueba, modifica el archivo sample.in que se encuentra en el proyecto.
   * Si quieres usar Java, debes tener instalado el JDK.
   * Si quieres usar Pascal, debes tener instalado Lazarus y haberlo ejecutado al menos una vez.
   * Si quieres usar Python, debes tener instalado Python 2.7
* Escribe run (o run.bat) para compilar todos los programas que necesitas y posteriormente ejecutar tu código. Recuerda que el validador espera una entrada en la consola, así que debes ya sea escribirla o pasársela como archivo (run < entrada.in).

*  Para probar tu solución con un caso de prueba, escribe test (o test.bat). Esto es equivalente a correr run.bat < examples\sample.in.