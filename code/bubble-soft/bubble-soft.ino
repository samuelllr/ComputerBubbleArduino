// Variáveis
char numbers[255] = {};
char n1 , n2;           
int localArray = -1;
int pararContagem = -1;
int tempDelay = 400;
byte reverse = 0;
byte mode = 0;
byte bugInvisivel = 1;
byte modeFast = 0; 

void setup() {

  Serial.begin( 9600 );

  // Intro
  Serial.println( "---------------- [   ♾ BUBBLE SOFT AGORITHM COMPUTER ♾ ] ----------------" );
  Serial.println( " ? --> Apresenta o Array. " );
  Serial.println( " | --> Inicia a organização do Array. " );
  Serial.println( " ! --> Ativar modo Rápido/Desativar. " );
  Serial.println( " # --> Limpar Array. " );
  Serial.println( " @ --> Muda o modo de organização. Decrecente/Crescente. " );
  Serial.println( " " );
  delay( 2000 );
  Serial.println( " [ Sistema Pronto para adicionar dados ] " );
  Serial.println( " " );

}

void loop() {

  char serial = Serial.read( );

  if( mode == 0 ){
    
    if( serial > ' ' ){

      if( ( serial != '|' )&&( serial != '?' )&&( serial != ' ' )&&( serial != '!' )&&( serial != '#' )&&( serial != '@' ) ){ 

        Serial.println( "  ------[...]------  " );
        Serial.print( " Adiconado: " );
        Serial.println( serial );

        localArray++;
        Serial.print( " Posição: ");
        Serial.print( localArray );
        Serial.print( " [ Total: " );
        Serial.print( localArray + 1 );
        Serial.println( " ]" );
        numbers[ localArray ] = serial;

        if( modeFast == 0 ){

          Serial.println( " Array :" );
    
          for ( int i = 0 ; i <= localArray ; i++ ){
            Serial.print( " " );
            Serial.println( numbers[i] );
          }
        
        }

      }

      // Funções
      switch ( serial ){
        case '|': mode = 1; Serial.println( " " ); Serial.println( " INICIANDO TRABALHO..." ); delay(2000); break;
        case '?':
            Serial.print( " Números no Array: " ); 
          for( int i = 0; i <= localArray; i++ ){
            Serial.print( numbers[i] );
            if( i < localArray ){
              Serial.print( ", ");
            }
          }
        break;
        case '!':
          if( modeFast == 0 ){ 
            Serial.println( " " );
            Serial.println( " Modo Rápido ativado. ⚡" );
            modeFast = 1; 
            tempDelay = 100; 
          }else{
            Serial.println( " " );
            Serial.println( " Modo Rápido desativado. ↻" );
            modeFast = 0; 
            tempDelay = 400; 
          }
        break;
        case '#' :
           Serial.println( " " );
           Serial.println( " Array Limpo. ⟵" );
           memset( numbers , 0 , 255 );
           localArray = -1;
        break;
        case '@':
          if( reverse == 0 ){
            Serial.println( " " );
            Serial.println( " Organização decrecente ativada. ⥦" );
            reverse = 1;
          }else{
            Serial.println( " " );
            Serial.println( " Organização crescente ativada. ⥦" );
            reverse = 0;
          }
        break;
      }

    }
    
  }

  if ( mode == 1 ) start(); 

}

// Bubble Soft
void start(){

  Serial.println( " " );
  Serial.println( " ORGANIZANDO..." );

  for( int i = 0 ; i < localArray ; i++ ){

     if( i == localArray ) bugInvisivel = 0;
    
     n1 = numbers[i];
     n2 = numbers[ i + bugInvisivel ];

     if( reverse == 0 ){
     
       if(  n1 > n2  ){
  
          numbers[i] = n2;
          numbers[ i + bugInvisivel ] = n1;
  
          pararContagem = -1;
         
       }else{
          pararContagem++;
       }

     }

     if( reverse == 1 ){
  
       if(  n1 < n2  ){
  
          numbers[i] = n2;
          numbers[ i + bugInvisivel ] = n1;
  
          pararContagem = -1;
         
       }else{
          pararContagem++;
       }

     }
    
  }

  if( modeFast == 0 ){

    for( int i = 0; i <= localArray; i++ ){
       Serial.print( " " );
       Serial.println( numbers[i] );
    }

  }

  if( pararContagem > localArray ){ 
      mode = 0;
      Serial.println( " Trabalho Terminado." );
      
      Serial.println( " Array ORGANIZADO: ");
      Serial.print( " " );
      for( int i = 0; i <= localArray; i++ ){
         Serial.print( numbers[i] );
         if( i < localArray ){
            Serial.print( ",");
         }
      }
      
  }

  delay(tempDelay);
  
}