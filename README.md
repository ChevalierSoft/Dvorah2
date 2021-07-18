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
There is a release for 32bit/64bit version with Debug/Release precompiled [HERE](https://github.com/ChevalierSoft/Dvorah2/releases/tag/v2.0).

## Compilation
You need visual studio to complie this code.

Maybe in the next release I'll allow g++ compilation.

## Usage
`Dvorah2.exe <full_dll_path>`

You need to write the full path like `C:\full\path.dll`. If you only put something like `./my.dll` it will not work. `$pdw\my.dll` only works on powershell.

If you already know the PID you can add it at the end of the command.

`Dvorah2.exe <dll_path> [PID]`

## Thanks
Thanks to [CasualCoder91](https://github.com/CasualCoder91) for the base code. the flags makes the injector compatible with more dll than Dvorah v1 could.

## To do
- g++ compilation
- `-u` to unload dll (more complicated on 64bit)
