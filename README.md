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

## class instruct
コンパイラの後で実装する。
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

## bf compiler
brainfuck->Cのコンパイラ  
愚直に変換して投げるだけでもそこそこ速くなるのでさらなる高速化を目指す。
- #### 0初期化
	mandelbrotでは、10%ほど速くなった。
- #### +-><を1命令にまとめる。
- ####
