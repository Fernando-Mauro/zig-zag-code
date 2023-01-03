// https://omegaup.com/arena/problem/RedistribuyendoSoftwareLibre/
process.stdin.on("data", (data) => {
   let entrada = data.toString().split("\n");
   solve(entrada);
   process.exit();
});

function solve(entrada){
   // console.log(entrada);
   for(let i = 1; i < entrada.length; ++i){
      let numero = parseInt(entrada[i]);
      if(numero >= 3) process.stdout.write("Ok\n");
      else process.stdout.write("No\n");
   }
}