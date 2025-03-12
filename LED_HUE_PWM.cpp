#include "mbed.h"

//Buses Display
BusOut DATOS(PA_13, PA_14, PA_15, PC_13, PB_15, PB_14, PB_13, PC_4);
DigitalOut ENABLES (PC_6);
DigitalOut RS (PC_8);
//Entrada
DigitalIn INTERRUPTOR (PC_5);
//Salida
DigitalOut TESTIGO(PA_0); //testigo de prueba para control de bloqueo micro
//PWM
PwmOut ROJO(PC_9);
PwmOut VERDE(PB_8);
PwmOut AZUL(PB_9);

//Variables
uint8_t contar=0;
char texto[50];
char texto2[50];

//Rutinas
void SALUDO(void);
void ENTER(void);
void LED(void);
void CONTAR (void);
void POS0 (void);
void POS1 (void);
void POS2 (void);
void POS3 (void);
void POS4 (void);
void POS5 (void);
void POS6 (void);
void POS7 (void);
void POS8 (void);
void POS9 (void);
void POS10 (void);
void POS11 (void);
void POS12 (void);
void POS13 (void);
void POS14 (void);
void POSICION (void);
//Display
void R_I (uint8_t COMANDO);
void R_D (uint8_t CARACTER);
void INICIALIZAR(void);

//-----------------------------------------INICIO----------------------------------------------

int main (void)
{
    INICIALIZAR();
    SALUDO();
    while(1){
        CONTAR();
        POSICION();
            }
}

void SALUDO(void)
{
    TESTIGO = 1;
    uint8_t INDICE;
    uint8_t LONGITUD = 0;

	//R_I(128);// Primer renglon primer caracter
    R_I(131);// Centrar

    LONGITUD = sprintf(texto,"Televisa");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}

	//R_I(192);// Segundo renglon primer caracter
    R_I(195); // Centrar

    LONGITUD = sprintf(texto2,"Presenta");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}
}

void CONTAR(void)
{
     ENTER();
     LED();
     contar++;
}

void POSICION(void)
    {
        ROJO.period_ms(1);
        VERDE.period_ms(1);
        AZUL.period_ms(1);
        
        switch(contar)
        {
            case 0: POS0(); break;
            case 1: POS1(); break;
            case 2: POS2(); break;
            case 3: POS3(); break;
            case 4: POS4(); break;
            case 5: POS5(); break;
            case 6: POS6(); break;
            case 7: POS7(); break;
            case 8: POS8(); break;
            case 9: POS9(); break;
            case 10: POS10(); break;
            case 11: POS11(); break;
            case 12: POS12(); break;
            case 13: POS13(); break;
            case 14: POS14(); break;
            default: POS0(); break;
        }
    }

//--------------------------------- INTERNAS --------------------------------------------------

void ENTER(void)
{   
    while (INTERRUPTOR==1) 
    {}
    ThisThread::sleep_for(40ms);
    while(INTERRUPTOR==0)
    {}    
    ThisThread::sleep_for(40ms);  
 }

void LED(void)
{
    uint8_t l=0;

    TESTIGO = 1;
    for(l=0;l<4;l++)
    {
        TESTIGO = 0;
        ThisThread::sleep_for(40ms);
        TESTIGO = 1;
        ThisThread::sleep_for(40ms);
    }
    TESTIGO = 1;
}   

void POS0 (void)
    {
        ROJO.pulsewidth_us(0);
        VERDE.pulsewidth_us(0);
        AZUL.pulsewidth_us(0);          
    }

void POS1 (void) //Amarillo
    {
        ROJO.pulsewidth_us(1000);
        VERDE.pulsewidth_us(500);
        AZUL.pulsewidth_us(0);

    uint8_t INDICE;
    uint8_t LONGITUD = 0;

    R_I(1);//Limpia display y deja en HOME
	//R_I(128);// Primer renglon primer caracter
    R_I(129);// Centrar

    LONGITUD = sprintf(texto,"R100 G050 B000");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}
    
	//R_I(192);// Segundo renglon primer caracter
    R_I(196); // Centrar

    LONGITUD = sprintf(texto2,"AMARILLO");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}

    }
void POS2 (void) //Naranja
    {
        ROJO.pulsewidth_us(1000);
        VERDE.pulsewidth_us(125);
        AZUL.pulsewidth_us(0);

    uint8_t INDICE;
    uint8_t LONGITUD = 0;

    R_I(1);//Limpia display y deja en HOME
	//R_I(128);// Primer renglon primer caracter
    R_I(129);// Centrar

    LONGITUD = sprintf(texto,"R100 G012 B000");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}
    
	//R_I(192);// Segundo renglon primer caracter
    R_I(196); // Centrar

    LONGITUD = sprintf(texto2,"NARANJA");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}

    }
void POS3 (void) //Rojo
    {
        ROJO.pulsewidth_us(1000);
        VERDE.pulsewidth_us(0);
        AZUL.pulsewidth_us(0);

    uint8_t INDICE;
    uint8_t LONGITUD = 0;

    R_I(1);//Limpia display y deja en HOME
	//R_I(128);// Primer renglon primer caracter
    R_I(129);// Centrar

    LONGITUD = sprintf(texto,"R100 G000 B000");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}
    
	//R_I(192);// Segundo renglon primer caracter
    R_I(198); // Centrar

    LONGITUD = sprintf(texto2,"ROJO");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}

    }   
void POS4 (void) //Fucsia
    {
        ROJO.pulsewidth_us(1000);
        VERDE.pulsewidth_us(0);
        AZUL.pulsewidth_us(500);

    uint8_t INDICE;
    uint8_t LONGITUD = 0;

    R_I(1);//Limpia display y deja en HOME
	//R_I(128);// Primer renglon primer caracter
    R_I(129);// Centrar

    LONGITUD = sprintf(texto,"R100 G000 B050");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}
    
	//R_I(192);// Segundo renglon primer caracter
    R_I(197); // Centrar

    LONGITUD = sprintf(texto2,"FUCSIA");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}

    }
void POS5 (void) //Dmanson
    {
        ROJO.pulsewidth_us(1000);
        VERDE.pulsewidth_us(0);
        AZUL.pulsewidth_us(200);   

    uint8_t INDICE;
    uint8_t LONGITUD = 0;

    R_I(1);//Limpia display y deja en HOME
	//R_I(128);// Primer renglon primer caracter
    R_I(129);// Centrar

    LONGITUD = sprintf(texto,"R080 G000 B067");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}
    
	//R_I(192);// Segundo renglon primer caracter
    R_I(192); // Centrar

    LONGITUD = sprintf(texto2,"Azul-Violeta");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}

    }
void POS6 (void) //Violeta
    {
        ROJO.pulsewidth_us(500);
        VERDE.pulsewidth_us(0);
        AZUL.pulsewidth_us(1000);

    uint8_t INDICE;
    uint8_t LONGITUD = 0;

    R_I(1);//Limpia display y deja en HOME
	//R_I(128);// Primer renglon primer caracter
    R_I(129);// Centrar

    LONGITUD = sprintf(texto,"R050 G000 B100");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}
    
	//R_I(192);// Segundo renglon primer caracter
    R_I(196); // Centrar

    LONGITUD = sprintf(texto2,"VIOLETA");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}

    }
void POS7 (void) //Azul
    {
        ROJO.pulsewidth_us(0);
        VERDE.pulsewidth_us(0);
        AZUL.pulsewidth_us(1000);

    uint8_t INDICE;
    uint8_t LONGITUD = 0;

    R_I(1);//Limpia display y deja en HOME
	//R_I(128);// Primer renglon primer caracter
    R_I(129);// Centrar

    LONGITUD = sprintf(texto,"R000 G000 B100");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}
    
	//R_I(192);// Segundo renglon primer caracter
    R_I(198); // Centrar

    LONGITUD = sprintf(texto2,"AZUL");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}

    }
void POS8 (void) //Cerúleo
    {
        ROJO.pulsewidth_us(0);
        VERDE.pulsewidth_us(500);
        AZUL.pulsewidth_us(1000);

    uint8_t INDICE;
    uint8_t LONGITUD = 0;

    R_I(1);//Limpia display y deja en HOME
	//R_I(128);// Primer renglon primer caracter
    R_I(129);// Centrar

    LONGITUD = sprintf(texto,"R000 G050 B100");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}
    
	//R_I(192);// Segundo renglon primer caracter
    R_I(196); // Centrar

    LONGITUD = sprintf(texto2,"CERULEO");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}

    }
void POS9 (void) //Cian
    {
        ROJO.pulsewidth_us(0);
        VERDE.pulsewidth_us(1000);
        AZUL.pulsewidth_us(1000);

    uint8_t INDICE;
    uint8_t LONGITUD = 0;

    R_I(1);//Limpia display y deja en HOME
	//R_I(128);// Primer renglon primer caracter
    R_I(129);// Centrar

    LONGITUD = sprintf(texto,"R000 G100 B100");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}
    
	//R_I(192);// Segundo renglon primer caracter
    R_I(198); // Centrar

    LONGITUD = sprintf(texto2,"CIAN");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}

    }
void POS10 (void) //Aguamarina
    {
        ROJO.pulsewidth_us(0);
        VERDE.pulsewidth_us(1000);
        AZUL.pulsewidth_us(500);

    uint8_t INDICE;
    uint8_t LONGITUD = 0;

    R_I(1);//Limpia display y deja en HOME
	//R_I(128);// Primer renglon primer caracter
    R_I(129);// Centrar

    LONGITUD = sprintf(texto,"R000 G100 B050");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}
    
	//R_I(192);// Segundo renglon primer caracter
    R_I(195); // Centrar

    LONGITUD = sprintf(texto2,"AGUAMARINA");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}

    }
void POS11 (void) //Verde
    {
        ROJO.pulsewidth_us(0);
        VERDE.pulsewidth_us(1000);
        AZUL.pulsewidth_us(0);

    uint8_t INDICE;
    uint8_t LONGITUD = 0;

    R_I(1);//Limpia display y deja en HOME
	//R_I(128);// Primer renglon primer caracter
    R_I(129);// Centrar

    LONGITUD = sprintf(texto,"R000 G100 B000");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}
    
	//R_I(192);// Segundo renglon primer caracter
    R_I(197); // Centrar

    LONGITUD = sprintf(texto2,"VERDE");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}

    }
void POS12 (void) //Lima
    {
        ROJO.pulsewidth_us(500);
        VERDE.pulsewidth_us(1000);
        AZUL.pulsewidth_us(0);

    uint8_t INDICE;
    uint8_t LONGITUD = 0;

    R_I(1);//Limpia display y deja en HOME
	//R_I(128);// Primer renglon primer caracter
    R_I(129);// Centrar

    LONGITUD = sprintf(texto,"R050 G100 B000");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}
    
	//R_I(192);// Segundo renglon primer caracter
    R_I(198); // Centrar

    LONGITUD = sprintf(texto2,"LIMA");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}

        //contar=0;    
    }

    void POS13 (void) //Blanco
    {
        ROJO.pulsewidth_us(1000);
        VERDE.pulsewidth_us(1000);
        AZUL.pulsewidth_us(1000);

    uint8_t INDICE;
    uint8_t LONGITUD = 0;

    R_I(1);//Limpia display y deja en HOME
	//R_I(128);// Primer renglon primer caracter
    R_I(129);// Centrar

    LONGITUD = sprintf(texto,"R100 G100 B100");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}
    
	//R_I(192);// Segundo renglon primer caracter
    R_I(198); // Centrar

    LONGITUD = sprintf(texto2,"BLANCO");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}
        //contar=0;
    }   

void POS14 (void) //Negro o ausencia de color
    {
        ROJO.pulsewidth_us(0000);
        VERDE.pulsewidth_us(0000);
        AZUL.pulsewidth_us(0000);

    uint8_t INDICE;
    uint8_t LONGITUD = 0;

    R_I(1);//Limpia display y deja en HOME
	//R_I(128);// Primer renglon primer caracter
    R_I(129);// Centrar

    LONGITUD = sprintf(texto,"R000 G000 B000");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto[INDICE]);
		ThisThread::sleep_for(50ms);
	}
    
	//R_I(192);// Segundo renglon primer caracter
    R_I(195); // Centrar

    LONGITUD = sprintf(texto2,"APAGADO");
 
    for(INDICE = 0;INDICE<LONGITUD;INDICE++)
	{
        R_D(texto2[INDICE]);
		ThisThread::sleep_for(50ms);
	}
        contar=0;
    }
// ----------------------------------- DISPLAY ------------------------------------

void R_I (uint8_t COMANDO)
{
	RS  	= 0;
	//RW  	= 0;
	ENABLES  = 0;
	DATOS   = COMANDO;
    
    ENABLES  = 1;
	wait_us(1);
	ENABLES  = 0;
    
	ThisThread::sleep_for(2ms);
}

void R_D (uint8_t CARACTER)
{
	RS  	= 1;
	//RW  	= 0;
	ENABLES  = 0;
	DATOS   = CARACTER;
    
	ENABLES  = 1;
	wait_us(1);
	ENABLES  = 0;
    
	ThisThread::sleep_for(2ms);
}

void INICIALIZAR(void)
{
	ThisThread::sleep_for(50ms);
	R_I(0b00110000);
    
	ThisThread::sleep_for(25ms);
	R_I(0b00110000);
    
	ThisThread::sleep_for(1ms);
	R_I(0b00110000);
    
	R_I(0b00111000);  // Activa la segunda linea y establece la interfaz en 8 bits
	R_I(0b00001111);  // R_I(0b00001100); → sin cursor ni sin parpadeo
	R_I(0b00000001);    
}
