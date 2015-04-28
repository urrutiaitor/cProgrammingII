#ifndef BISTARATU_H
#define BISTARATU_H

#include "datuEgiturak.h"

void BISTARATU_notakBistaratuIkaslearentzat(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa);
void BISTARATU_ikaslearenBatezbestekoa(USUARIOA *ptr_usuarioa);
void BISTARATU_taldekoIkasgaikoBatezbestekoa(ESKOLA *ptr_eskola, USUARIOA *ptr_usuarioa);
void BISTARATU_taldekoBatezbestekoa(ESKOLA *ptr_eskola, USUARIOA *ptr_usuarioa);

#endif