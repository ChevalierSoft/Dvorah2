```bash
@@@@@@@   @@@  @@@   @@@@@@   @@@@@@@    @@@@@@   @@@  @@@      @@@@@@   
@@@@@@@@  @@@  @@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@  @@@     @@@@@@@@  
@@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@          @@@  
!@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@         @!@   
@!@  !@!  @!@  !@!  @!@  !@!  @!@!!@!   @!@!@!@!  @!@!@!@!        !!@    
!@!  !!!  !@!  !!!  !@!  !!!  !!@!@!    !!!@!!!!  !!!@!!!!       !!:     
!!:  !!!  :!:  !!:  !!:  !!!  !!: :!!   !!:  !!!  !!:  !!!      !:!      
:!:  !:!   ::!!:!   :!:  !:!  :!:  !:!  :!:  !:!  :!:  !:!     :!:       
 :::: ::    ::::    ::::: ::  ::   :::  ::   :::  ::   :::     :: :::::  
:: :  :      :       : :  :    :   : :   :   : :   :   : :     :  : : :  
```
# Dvorah2
Simple DLL injector usable with one command line.

## Release
There is a release for 32bit or 64bit availlable.

## Compilation
You need visual studio to complie this code.

Maybe in the next release I'll allow g++ compilation.

## Usage
`./Dvorah2 <dll_path>`


If you already know the PID you can add it at the end of the command.

`./Dvorah2 <dll_path> [PID]`

## Thanks
Thanks to [CasualGamer](https://github.com/CasualCoder91) for the base code. the flags makes the injector compatible with more dll than Dvorah v1 could.

## To do
- g++ compilation
- `-u` to unload dll (more complicated on 64bit)
