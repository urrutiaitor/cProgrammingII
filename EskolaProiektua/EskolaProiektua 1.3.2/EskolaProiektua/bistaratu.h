#ifndef BISTARATU_H
#define BISTARATU


int BISTARATU_gelaAukeratu(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void BISTARATU_notakBistaratuIkaslearentzat(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void BISTARATU_notakBistaratuIrakaslearentzat(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void BISTARATU_ikaslearenBatezbestekoa(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void BISTARATU_taldekoIkasgaikoBatezbestekoa(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void BISTARATU_taldekoBatezbestekoa(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void BISTARATU_taldekoBatezbestekoHoberena(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void BISTARATU_taldekoIkasleakBatezbestekoarenArabera(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void ordenatu(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);

#endif