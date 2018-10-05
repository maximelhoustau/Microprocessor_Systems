extern int * _bss;
extern int * _bss_size;
extern int * _zero;

void init_bss(){
  while(_bss < _bss_size){
    *_bss = *_zero;
    _bss += 4 ;
  }
}
