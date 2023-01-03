// https://omegaup.com/arena/problem/CR-Buscando-repeticiones/
process.stdin.on("data", (data) => {
   let entrada = data.toString().split("\n");
   solve(entrada)
   process.exit()
});

function solve([palabra, cadena]){
   const palabraMinuscula = palabra.toLowerCase();
   cadena = cadena.split(/[(, )(,)( )]+/);
   // console.log(cadena);
   let incidencias = cadena.filter((x) => x === palabraMinuscula);
   // console.log(incidencias)
   let last;
   (incidencias.length != 1 ? last = "veces" : last = "vez");
   console.log(`${palabra} se repite ${incidencias.length} ${last}.`);
}