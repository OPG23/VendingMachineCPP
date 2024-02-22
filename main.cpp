#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

float creditos = 0;
float productos[4]= {3200, 4000, 2500, 5300};
float fopre_total = 0;
int gaseosas = 0, chocoramos = 0, papas = 0, galletas = 0;
int can_gaseosas = 0, can_chocoramos = 0, can_papas = 0, can_galletas = 0;
char variable2_it[11], variable2_it1[18],variable2_it2[20], variable2_it3[18], variable2_it4[15];
int it2gaseosas = 0, it2chocoramos = 0, it2galletas = 0, it2papas = 0;
int itgaseosas = 0, itchocoramos = 0, itgalletas = 0, itpapas = 0;

void inventario_inicial(){
  ifstream inventario1("inventario.csv");

  inventario1 >> variable2_it;
  inventario1 >> variable2_it1;
  inventario1 >> it2gaseosas;
    
  inventario1 >> variable2_it2;
  inventario1 >> it2chocoramos;
  
  inventario1 >> variable2_it3;
  inventario1 >> it2galletas;
  
  inventario1 >> variable2_it4;
  inventario1 >> it2papas;

  inventario1.close();
}




//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
void agregar_credito(){
  int credito_agregado = 0;
  int opcion = 0;
  cout<<"------------------------------------------------------------"<<endl<<endl;
  cout<<"Actualmente usted cuenta con: "<<creditos<<"$"<<endl;

  for(int i = 0; i==0;){
    cout<<"¿Desea agregar credito? Digite 1 para si o 2 para no."<<endl;
    cin>> opcion;

    if(opcion == 1){
      cout<<"Nuestra maquina unicamente recibe los siguientes tipos de monedas y billetes:"<<endl;
      cout<<"||Monedas||             ||Billetes||"<<endl;
      cout<<"|| *50   ||             || *1000  ||"<<endl;
      cout<<"|| *100  ||             || *2000  ||"<<endl;
      cout<<"|| *200  ||             || *5000  ||"<<endl;
      cout<<"|| *500  ||             || *10000 ||"<<endl;
      cout<<"                        || *20000 ||"<<endl;
      cout<<"                        || *50000 ||"<<endl;
      cout<<"                        || *100000||"<<endl<<endl;
      cout<<"Digite el saldo en monedas o billetes, digite 0 para leer el saldo en la maquina:"<<endl;
      
      for(int i = 0; i==0;){
        cin>>credito_agregado;
        if(credito_agregado == 0){
          cout<<"Credito registrado en la maquina."<<endl<<endl;
          break;
        }
        if(credito_agregado != 50 && credito_agregado != 100 && credito_agregado != 200 && credito_agregado !=500 && credito_agregado !=1000 && credito_agregado != 2000 && credito_agregado != 5000 && credito_agregado != 10000 && credito_agregado != 20000 && credito_agregado != 50000 && credito_agregado != 100000 && credito_agregado != 0){
        cout<<"Error al leer la moneda o billete, intentelo nuevamente:"<<endl;
      }else {
        creditos+=credito_agregado;
        cout<<"Saldo agregado correctamente, Credito actual: "<<creditos<<endl; 
      }
        
      }
      break;
    }
    if(opcion == 2){
      break;
    }
    if(opcion != 1 && opcion !=2){
      cout<<"Opcion no valida intentelo nuevamente."<<endl;
    }
  } 
}

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
void comprar_productos(){
  int opcion = 0;
  float cantidad = 0;
  cout<<"------------------------------------------------------------"<<endl<<endl;
        for(int i = 0; i == 0;){
          cout<<"Digite el numero del producto que desea comprar: "<<endl;
          cin>> opcion;
  

          switch(opcion){

              case 1:
                  cout<<"Digite la cantidad de gaseosas que desea comprar: "<<endl;
                  cin>> cantidad;
                if(cantidad > 0){
                  if(cantidad <= it2gaseosas){
                  if(creditos >= productos[0]*cantidad){
                        
                        creditos = creditos - productos[0]*cantidad;
                        
                        gaseosas = gaseosas + cantidad;

                        can_gaseosas += cantidad;
                      
                        cout<<"Este producto cuenta con FOPRE por lo cual parte de su precio se donara."<<endl<<endl;

                        fopre_total = fopre_total + productos[0]*0.06*cantidad;

                        cout<<"La compra fue realizada con exito, su saldo restante es: &"<<creditos<<endl<<endl;
                        
            
                      } else{

                        cout<<" El credito actual no es suficiente para comprar el/los productos, por favor regrese a la pantalla principal y agregue credito."<<endl<<endl;
                         
                      }
                  i = 1;
                }else{
                  cout<<"Lo sentimos, la cantidad digitada es muy alta o el producto deseado esta agotado, por favor verifique esto en la disponibilidad de la maquina o compre un producto diferente."<<endl;
                    i=1;
                }
                }else{
                  cout<<"La cantidad ingresada es incorrecta, intentelo nuevamente."<<endl;
                }
                
       
               break;

            case 2:
                  cout<<"Digite la cantidad de chocoramos que desea comprar: "<<endl;
                  cin>> cantidad;
              if(cantidad > 0){
                if(cantidad <= it2chocoramos){
                  if(creditos >= productos[1]*cantidad){
            
                        creditos = creditos - productos[1]*cantidad;

                        chocoramos = chocoramos + cantidad;

                        can_chocoramos += cantidad;
            
                        cout<<"La compra fue realizada con exito, su saldo restante es: $"<<creditos<<endl<<endl;
            
                      } else{

                        cout<<" El credito actual no es suficiente para comprar el/los productos, por favor regrese a la pantalla principal y agregue credito."<<endl<<endl;
                      
                      } 
                  i = 1;
                }else{
                  cout<<"Lo sentimos, la cantidad digitada es muy alta o el producto deseado esta agotado, por favor verifique esto en la disponibilidad de la maquina o compre un producto diferente."<<endl;
                  i=1;
                }
              }else{
                  cout<<"La cantidad ingresada es incorrecta, intentelo nuevamente."<<endl;
                }
                
                    
                      
              break;

            case 3:
                  cout<<"Digite la cantidad de galletas que desea comprar: "<<endl;
                  cin>> cantidad;
              if(cantidad >0){
                 if(cantidad<= it2galletas){
                  if(creditos >= productos[2]*cantidad){
            
                        creditos = creditos - productos[2]*cantidad;

                        galletas = galletas + cantidad;

                        can_galletas += cantidad;
            
                        cout<<"Este producto cuenta con FOPRE por lo cual parte de su precio se donara."<<endl<<endl;

                        fopre_total = fopre_total + productos[2]*0.06*cantidad;

                        cout<<"La compra fue realizada con exito, su saldo restante es: $"<<creditos<<endl<<endl;
            
                      } else{

                        cout<<" El credito actual no es suficiente para comprar el/los productos, por favor regrese a la pantalla principal y agregue credito."<<endl;
                        
  
                      }
                  i = 1;
                }else{
                  cout<<"Lo sentimos, la cantidad digitada es muy alta o el producto deseado esta agotado, por favor verifique esto en la disponibilidad de la maquina o compre un producto diferente."<<endl;
                    i=1;
                }
              }else{
                  cout<<"La cantidad ingresada es incorrecta, intentelo nuevamente."<<endl;
                }
               
                    
                      
              break;
            case 4:
                  cout<<"Digite la cantidad de papas que desea comprar: "<<endl;
                  cin>> cantidad;
              if(cantidad > 0){
                if(cantidad<= it2papas){
                if(creditos >= productos[3]*cantidad){
            
                        creditos = creditos - productos[3]*cantidad;

                        papas = papas + cantidad;

                        can_papas += cantidad;  
            
                        cout<<"La compra fue realizada con exito, su saldo restante es: $"<<creditos<<endl;
            
                      } else{

                        cout<<" El credito actual no es suficiente para comprar el/los productos, por favor regrese a la pantalla principal y agregue credito."<<endl<<endl;
                        
  
                      }
                 i = 1;
              }else{
                cout<<"Lo sentimos, la cantidad digitada es muy alta o el producto deseado esta agotado, por favor verifique esto en la disponibilidad de la maquina o compre un producto diferente."<<endl;
                  i=1;
              }
              }else{
                  cout<<"La cantidad ingresada es incorrecta, intentelo nuevamente."<<endl;
                }
              
                    
                     
              break;
            default:
              cout<<"Opcion incorreta, digite nuevamente."<<endl<<endl;
              break;
            
          }
  
        }
  }
  

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

void registro_compras(){
  int cantidad_productos[4]= {gaseosas, chocoramos, galletas, papas};
  int max_producto = 0;
  string producto_mas_comprado;
    if(gaseosas >0 || chocoramos >0 || galletas >0 || papas >0){
      for(int i = 0; i<4; i++){
        if(cantidad_productos[i] >= max_producto){
          max_producto= cantidad_productos[i];
          if(i==0){
            producto_mas_comprado = "Gaseosas.";
          }
          if(i==1){
            producto_mas_comprado = "Chocoramos.";
          }
          if(i==2){
            producto_mas_comprado = "Galletas.";
          }
          if(i==3){
            producto_mas_comprado = "Papas.";
          }
        }
        
      }
    } else{
      producto_mas_comprado= "Ninguno.";
    }
      

  cout<<"------------------------------------------------------------"<<endl<<endl;
  cout<<"*********************"<<endl;
  cout<<"*REGISTRO DE COMPRAS*"<<endl;
  cout<<"*********************"<<endl<<endl<<endl;

  cout<<"Historial productos comprados:"<<endl<<endl;
  cout<<"Cantidad de gaseosas compradas: "<<gaseosas<<endl;
  cout<<"Cantidad de chocoramos comprados: "<<chocoramos<<endl;
  cout<<"Cantidad de galletas compradas: "<<galletas<<endl;
  cout<<"Cantidad de papas compradas: "<<papas<<endl<<endl;

  cout<<"Producto más comprado: "<<producto_mas_comprado<<endl<<endl;
  
  cout<<"Cantitad total de productos comprados: "<<gaseosas + chocoramos + galletas + papas<<endl<<endl;
  
  cout<<"Valor total de productos comprados: $"<<productos[0]*gaseosas + productos[1]*chocoramos + productos[2]*galletas + productos[3]*papas<<endl<<endl;
  
}

//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
void actualizar_inventario(){
  ifstream leer_inventario("inventario.csv");

  char variable_it[11], variable_it1[18],variable_it2[20], variable_it3[18], variable_it4[15];
 

  leer_inventario >> variable_it;
  leer_inventario >> variable_it1;
  leer_inventario >> itgaseosas;
    
  leer_inventario >> variable_it2;
  leer_inventario >> itchocoramos;
  
  leer_inventario >> variable_it3;
  leer_inventario >> itgalletas;
  
  leer_inventario >> variable_it4;
  leer_inventario >> itpapas;

  leer_inventario.close();
  
  itgaseosas -= can_gaseosas;
  itchocoramos -= can_chocoramos;
  itpapas -= can_papas;
  itgalletas -= can_galletas;

  can_gaseosas = 0;
  can_chocoramos = 0;
  can_papas = 0;
  can_galletas = 0;

  ofstream nuevo_inventario("inventario.csv");

  nuevo_inventario << variable_it;
  nuevo_inventario << endl;
  nuevo_inventario << variable_it1;
  nuevo_inventario << endl;
  nuevo_inventario << itgaseosas;
  nuevo_inventario << endl;
    
  nuevo_inventario << variable_it2;
  nuevo_inventario << endl;
  nuevo_inventario << itchocoramos;
  nuevo_inventario << endl;
  
  nuevo_inventario << variable_it3;
  nuevo_inventario << endl;
  nuevo_inventario << itgalletas;
  nuevo_inventario << endl;
  
  nuevo_inventario << variable_it4;
  nuevo_inventario << endl;
  nuevo_inventario << itpapas;

  nuevo_inventario.close();
}
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------

void disponibilidad(){
  cout<<"------------------------------------------------------------"<<endl<<endl;
  
  cout<<"1- Cantidad de gaseosas en la maquina es: "<<itgaseosas<<endl;
  cout<<"2- Cantidad de papas en la maquina es: "<<itpapas<<endl;
  cout<<"3- Cantidad de chocorramos en la maquina es: "<<itchocoramos<<endl;
  cout<<"4- Cantidad de galletas en la maquina es: "<<itgalletas<<endl<<endl;
  
}


//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

void registro_fopre(){
  cout<<"------------------------------------------------------------"<<endl<<endl;
  cout<<"**************************************"<<endl;
  cout<<"*FOPRE: Fondo de Programas Especiales*"<<endl;
  cout<<"**************************************"<<endl<<endl;
  cout<<"El FOPRE es una donacion por parte de nuestra empresa, esta equivale al 6% del valor del producto, es decir, usted no pagara ningun costo adicional, simplemente se le informa que parte de ese dinero se donara."<<endl<<endl;
  cout<<"Valor de la donacion FOPRE por prodructo:"<<endl<<endl;
  cout<<"1- Donacion para las gaseosas: $"<<productos[0]*0.06<<endl;
  cout<<"2- Donacion para las galletas: $"<<productos[2]*0.06<<endl<<endl;

  cout<<"Donacion total al FOPRE por gaseosas: $"<<gaseosas*productos[0]*0.06<<endl;
  cout<<"Donacion total al FOPRE por galletas: $"<<galletas*productos[2]*0.06<<endl<<endl;

  cout<<"Donacion total al FOPRE: $"<<fopre_total<<endl<<endl;
}
//-----------------------------------------------------------------------------------------------------------

void vueltas(){

  if(creditos == 0){
    cout<<"No existe saldo restante en la maquina."<<endl;
  }
  if(creditos != 0){
    cout<<"Su cambio es de: $"<<creditos<<endl;
  } 
} 

//-----------------------------------------------------------------------------------------------------------
void restablecer_inventario(){
  ofstream restablecer("inventario.csv");

  char variable3_it[11] = "INVENTARIO", variable3_it1[18] ="Gaseosas" ,variable3_it2[20]= "Chocoramos", variable3_it3[18]= "Galletas" , variable3_it4[15] = "Papas";

  
  restablecer << variable3_it;
  restablecer << endl;
  restablecer << variable3_it1;
  restablecer << endl;
  restablecer << 20;
  restablecer << endl;
    
  restablecer << variable3_it2;
  restablecer << endl;
  restablecer << 20;
  restablecer << endl;
  
  restablecer << variable3_it3;
  restablecer << endl;
  restablecer << 20;
  restablecer << endl;
  
  restablecer << variable3_it4;
  restablecer << endl;
  restablecer << 20;

  restablecer.close();

  cout<<"Se restablecio correctamente el inventario a su maxima capacidad en el caso de que falten productos."<<endl<<endl;
  
}

//-----------------------------------------------------------------------------------------------------------

void registro_total_compras(){

  ifstream registro_total("registro_compras.csv");

  char variable2_gas[10], variable2_cho[11], variable2_gall[10], variable2_pap[7];
  int cantidad2_gas = 0;
  int cantidad2_cho = 0;
  int cantidad2_pa = 0;
  int cantidad2_gall= 0;
  int cantidad2_total = 0;


  registro_total >> variable2_gas;
  registro_total >> cantidad2_gas;
    
  registro_total >> variable2_cho;
  registro_total >>cantidad2_cho;
  
  registro_total >> variable2_gall;
  registro_total >> cantidad2_gall;
  
  registro_total >> variable2_pap;
  registro_total >> cantidad2_pa;

  registro_total.close();


  cantidad2_total = cantidad2_gas+cantidad2_cho+cantidad2_gall+cantidad2_pa;

  
  cout<<"* Cantidad total de productos comprados en la maquina: "<<cantidad2_total<<endl<<endl;
  
  cout<<"* Cantidad total de gaseosas compradas en la maquina: "<<cantidad2_gas<<endl;
  cout<<"* Cantidad total de chocoramos comprados en la maquina: "<<cantidad2_cho<<endl;
  cout<<"* Cantidad total de galletas compradas en la maquina: "<<cantidad2_gall<<endl;
  cout<<"* Cantidad total de papas compradas en la maquina: "<<cantidad2_pa<<endl<<endl;

  cout<<"* Valor total recaudado por la maquina: "<<cantidad2_gas*3200 + cantidad2_cho*4000 + cantidad2_gall*2500 + cantidad2_pa*5300<<endl<<endl;

  cout<<"* Valor total donado a FOPRE por parte de la maquina: "<<cantidad2_gas*3200*0.06 + cantidad2_gall*2500*0.06<<endl<<endl;

  
  
}

//-----------------------------------------------------------------------------------------------------------
void administrador(){
  
char contraseña[50];
int opcion_admin = 0;

cout<<"Digite la contraseña de administrador: "<<endl;
cin>>contraseña;

if(strcmp(contraseña, "the-best-project") == 0){
  cout<<"¡Bienvenido administrador!"<<endl<<endl;
  cout<<"Indique la funcion que desea ejecutar: "<<endl;
  cout<<"1- Restablecer inventario."<<endl<<endl;
  cout<<"2- Ver registro total de compras."<<endl<<endl;
  cout<<"3- Salir."<<endl<<endl;
  cin>>opcion_admin;

  switch(opcion_admin){

      case 1:
          restablecer_inventario();
      break;

      case 2:
          registro_total_compras();
      break;

      case 3:
      break;

      default:

      cout<<"Error en la opcion digitada."<<endl;
      break;
  }

}else{
  cout<<"Contraseña incorrecta."<<endl<<endl;
}
  
}

//-----------------------------------------------------------------------------------------------------------

int main(){
  int opcion_principal;
  inventario_inicial();
  actualizar_inventario();
  cout<<"***********************"<<endl;
  cout<<"**Maquina expendedora**"<<endl; 
  cout<<"***********************"<<endl<<endl<<endl;

  // Apartado inicial del programa:
  for(int a = 0; a == 0;){
  cout<<"------------------------------------------------------------"<<endl<<endl;
  cout<<"PRODUCTOS:"<<endl<<endl;
  cout<<"1-  || Gaseosas   ||              Valor:3.200$ -- FOPRE"<<endl;
  cout<<"2-  || Chocoramos ||              Valor:4.000$"<<endl;
  cout<<"3-  || Galletas   ||              Valor:2.500$ -- FOPRE"<<endl;
  cout<<"4-  || Papas      ||              Valor:5.300$"<<endl<<endl;
  cout<<"------------------------------------------------------------"<<endl<<endl;
  cout<<"Digite la función que desea realizar"<<endl;
  cout<<"1. Comprar productos."<<endl;
  cout<<"2. Credito actual y agregar credito."<<endl;
  cout<<"3. Registro de compras."<<endl;
  cout<<"4. Disponibilidad de la máquina."<<endl;
  cout<<"5. Compras con FOPRE."<<endl;
  cout<<"6. Cerrar programa y recibir cambio."<<endl;
  cout<<"7. Opciones administrador."<<endl<<endl;
  cin>> opcion_principal;
    
  switch(opcion_principal){

    case 1:
      comprar_productos();
      
      break;
    
    case 2:
      agregar_credito();
      
      break;
    case 3:
      registro_compras();
      break;

    case 4:
      disponibilidad();
      break;

    case 5:
      registro_fopre();
      break;
    case 6:
      vueltas();
      cout<<"Finalizando programa..."<<endl;
      a = 1;
      break;
    case 7:
      administrador();
    break;
    default:
      cout<<"Opcion no válida, intnentelo nuevamente."<<endl<<endl;
      break;
    }
    
    actualizar_inventario();
    inventario_inicial();
  }


  ifstream leer_registro("registro_compras.csv");

  char variable_gas[10], variable_cho[11], variable_gall[10], variable_pap[7];
  int cantidad_gas = 0;
  int cantidad_cho = 0;
  int cantidad_pa = 0;
  int cantidad_gall= 0;

  leer_registro >> variable_gas;
  leer_registro>>cantidad_gas;
    
  leer_registro >> variable_cho;
  leer_registro>>cantidad_cho;
  
  leer_registro >> variable_gall;
  leer_registro>>cantidad_gall;
  
  leer_registro >> variable_pap;
  leer_registro>>cantidad_pa;

  

  
  leer_registro.close();

  gaseosas += cantidad_gas;
  chocoramos += cantidad_cho;
  papas += cantidad_pa;
  galletas += cantidad_gall;

  ofstream guardar_registro("registro_compras.csv");

  guardar_registro << variable_gas;
  guardar_registro << endl;
  guardar_registro << gaseosas;
  guardar_registro << endl;
    
  guardar_registro << variable_cho;
  guardar_registro << endl;
  guardar_registro << chocoramos;
  guardar_registro << endl;
  
  guardar_registro << variable_gall;
  guardar_registro << endl;
  guardar_registro << galletas;
  guardar_registro << endl;
  
  guardar_registro << variable_pap;
  guardar_registro << endl;
  guardar_registro << papas;
  guardar_registro << endl;

  guardar_registro.close();

  
  return 0;
}