#ifndef DATUENMODIFIKAZIOA_H
#define DATUENMODIFIKAZIOA_H

#include "datuEgiturak.h"

int DATUENMODIFIKAZIOA_eskolakoDatuakModifikatu(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa);
int DATUENMODIFIKAZIOA_eskolakoIzenaModifikatu(ESKOLA *ptr_eskola);
int DATUENMODIFIKAZIOA_eskolakoHelbideaModifikatu(ESKOLA *ptr_eskola);
int DATUENMODIFIKAZIOA_eskolakoTelefonoaModifikatu(ESKOLA *ptr_eskola);

int DATUENMODIFIKAZIOA_ikasgaiakSartuAdministrazioa(ESKOLA *ptr_eskola);
int DATUENMODIFIKAZIOA_usuarioBatSartu(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa);
int DATUENMODIFIKAZIOA_usuarioarenDatuakSartu(USUARIOA *ptr_usuarioa);
int DATUENMODIFIKAZIOA_irakasleakAsignatu(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa);
int DATUENMODIFIKAZIOA_ikaslearenIkasgaiakSartu(ESKOLA *ptr_eskola, USUARIOA *ptr_usuarioa);
int DATUENMODIFIKAZIOA_notakSartu(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa, USUARIOA *ptr_usuarioa);


#endif