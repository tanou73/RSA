RSA
===

# Introduction

Cette suite de programme vous permet de :
* génerer des clés RSA
* chiffrer un message
* le déchiffrer
* le signer
* le vérifier

Ce programme utilise des grands entiers (GMP) pour assurer la sécurité.

#Compilation

Rendez-vous dans le dossier RSA pour compiler et utiliser les programmes:

	cd RSA && make clean && make

# Tester la suite 

Générez vos clés (le nom du fichier est optionnel, cf. Programmes/gencle) :

	./gencle 1024 key

_Les fichiers key.priv et key.pub seront créés._

Chiffrez (avec votre clé publique) et déchiffrez (avec votre clé privée) votre message :

	cat msg.txt | ./chiffre key.pub | ./dechiffre key.priv

Préparez votre signature et stockez-la dans un fichier

	cat msg.txt | ./msgToSha1 >> fichier.sign

On va maintenant encrypter notre message en SHA-1, le signer et vérifier notre signature en la comparant avec nos fichier.sign

	cat msg.txt | ./msgToSha1 | ./signe key.priv | ./verifie key.pub fichier.sign

# Programmes

## gencle

#### Lancer le programme

	./gencle [t] ([file])

> [t] : nombre de bits pour générer les clés ( temps correct jusqu'à 2048 bits)
> ([file]) : Optionel: nom du fichier privée dans lequel sauvegarder les clés (par défaut ~/.my_rsa)

#### Description

Ce programme génére les clés publiques et les clés privées. Ces clés sont affichées puis stockées dans un fichier privé (lectures et écritures autorisées seulement pour l'utilisateur courant) et publique.

## Chiffre

#### Lancer le programme

Le programme chiffre ce qui se trouve sur l'entrée standard. On peut par exemple lui envoyer :

	cat monMessage.txt | ./chiffre [n] [b] [t]

ou 

	cat monMessage.txt | ./chiffre [fichier.pub]

> [n] [b] : clé publique avec laquelle vous voulez chiffrer
> [t] : taille des blocks pour découper (en bits)
> [fichier.pub] : Le fichier contenant votre clé publique

#### Description

Ce programme chiffre le message placé dans l'entrée standard avec la clé passée en paramètre et renvoie le résultat sur la sortie standard.

## Dechiffre

#### Lancer le programme

Le programme déchiffre ce qui se trouve sur l'entrée standard. On peut par exemple lui envoyer :

	cat monMessageChiffre.txt | ./dechiffre [file]

> [file] : fichier générer par gencle (dans lequel se trouve votre clé privée)

#### Description

Ce programme déchiffre le message placé dans l'entrée standard avec la clé située dans gencle (générée auparavant) et renvoie le résultat sur la sortie standard.

#### Chiffrer et déchiffrer

	cat msg.txt | ./chiffre 1062080754043853759 2478996599 32 | ./dechiffre file.priv

ou

	cat msg.txt | ./chiffre key.pub | ./dechiffre key.priv

## MessageToSha1

#### Lancer le programme

Le programme encode un message (de l'entrée standard) en SHA-1. On peut par exemple lui envoyer :

	cat monMessageChiffre.txt | ./msgToSha1

#### Description

Ce programme encode en sha1 le message placé dans l'entrée standard et renvoie le résultat sur la sortie standard.

Peut être utilisé pour faire un checksum SHA-1 sur le message, et de l'envoyer par exemple à signe pour signer le message avec.

## Signe

#### Lancer le programme

Le programme signe un message (de l'entrée standard) avec la clé privée du fichier privée générée auparavant . On peut par exemple lui envoyer le sha1 du message, puis l'enregistrer dans un fichier :

	cat monMessageChiffre.txt | ./msgToSha1 | ./signe >> signature.txt

#### Description

Ce programme signe le message placé dans l'entrée standard et renvoie le résultat sur la sortie standard.

## Verifie

#### Lancer le programme

Le programme vérifie une signature envoyé sur l'entrée standard par rapport à un fichier signature passé en paramètre. 

	cat signature-to-test.txt | ./verifie sender.pub sender.sign

ou

	cat signature-to-test.txt | ./verifie [n] [b] [t] sender.sign

> entrée standard : la signature à vérifier
> [sender.pub] : la clé publique de l'expéditeur
> [n] [b] [t] : clé publique de l'expéditeur et taille des blocs
> [sender.sign] : la signature attendu de l'expéditeur
