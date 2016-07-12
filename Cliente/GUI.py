#-*- coding: utf-8-*-

def showPlacar(chances, acertos):
	print
	print "Chances : " + chances
	print "Acertos : " + acertos

def showQuis(word, tip, kicks):
	print "Dica : " + tip
	print "Chutes : " + kicks
	print "Palavra : " + word
	print

def showWin(venceu):
	if venceu :
		print " AEEH VENCEU  :) "
	else :
		print " AAHH PERDEU :( "


def getChute():
	k = raw_input("Digite seu chute: ")
	return k

def getOp():
	print
	o = raw_input("Digite sua escolha :\n   1- Novo Jogo\n   2- Sair\n  ")
	return o

def getMsgErroChute():
	print "Erro ao digitar o chute, Tente Novamente"

def getMsgErroMenu():
	print "Erro ao digitar sua opção, Tente Novamente"
