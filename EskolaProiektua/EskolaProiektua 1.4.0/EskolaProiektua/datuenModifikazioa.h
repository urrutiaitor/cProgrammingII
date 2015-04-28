#ifndef DATUENMODIFIKAZIOA_H
#define DATUENMODIFIKAZIOA


void DATUENMODIFIKAZIOA_notakModifikatu(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void DATUENMODIFIKAZIOA_notakSartu(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void DATUENMODIFIKAZIOA_ikasleBatSartu(USUARIO **usuarioa_ptr_ptr ESKOLA **eskola_ptr_ptr);
void DATUENMODIFIKAZIOA_eskolakoDatuakSartu( ESKOLA *eskola_ptr);//ONDO
void DATUENMODIFIKAZIOA_eskolakoDatuakModifikatu(ESKOLA *eskola_ptr);//ONDO
void DATUENMODIFIKAZIOA_ikasleakGeletanBanatu(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptra);
void DATUENMODIFIKAZIOA_gelaFisikoaAsignatu(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void DATUENMODIFIKAZIOA_irakasleakAsignatu(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void DATUENMODIFIKAZIOA_tutoreaAsignatu(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void DATUENMODIFIKAZIOA_batenDatuakSartu(USUARIO **usuarioa_ptr_ptr,  ESKOLA **eskola_ptr_ptr);
void DATUENMODIFIKAZIOA_ikaslearenIkasgaiakSartu(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void DATUENMODIFIKAZIOA_ikasgaiakSartu(USUARIO **usuarioa_ptr_ptr,ESKOLA **eskola_ptr_ptr);
void DATUENMODIFIKAZIOA_ikasgaiakSartuAdministrazioa(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);
void DATUENMODIFIKAZIOA_eskolakoIzenaModifikatu(ESKOLA *eskola_ptr);
void DATUENMODIFIKAZIOA_eskolakoHelbideaModifikatu(ESKOLA *eskola_ptr);
void DATUENMODIFIKAZIOA_eskolakoTelefonoaModifikatu(ESKOLA *eskola_ptr);
void DATUENMODIFIKAZIOA_eskolakoMailakJarri(USUARIO **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);

#endif