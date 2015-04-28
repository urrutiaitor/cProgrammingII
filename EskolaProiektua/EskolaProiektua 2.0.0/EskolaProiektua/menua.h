#ifndef MENUA_H
#define MENUA_H

#include "datuEgiturak.h"

int MENUA_menukoAukerak(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa, int *ptr_usuarioa, int *ptr_pasahitza);

void MENUA_aukerakAdministratzailea(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa, int *ptr_usuarioa);
void MENUA_aukerakIrakaslea(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa, int *ptr_usuarioa);
void MENUA_aukerakIkaslea(ESKOLA *ptr_eskola, USUARIOA *ptr_ikaslea, int *ptr_usuarioa);

int MENUA_aukerakAdministratzaileaBistaratu();
int MENUA_aukerakIrakasleaBistaratu();
int MENUA_aukerakIkasleaBistaratu();

#endif