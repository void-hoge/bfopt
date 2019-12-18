# Brainfuck intetrpreter & compiler
メモ的な
## class interpreter
- ### data
	配列データ  
	data_ptrでアクセス  
- ### prg
	命令の配列  
	pcでアクセス
- ### ins
	最適化した命令の配列

## class instruction
- ### type
	- nop
		- no operation
	- move x
		- ptrをx動かす
	- add x
		- ptrが指すところにx足す
	- goto x
		- pcをx+1進める
	- gotob
		- gotoになる前の[
	- gotof
		- gotoになる前の]
