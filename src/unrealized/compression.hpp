#pragma once

#include "minilzo/minilzo.h"

#define HEAP_ALLOC(var,size) \
    lzo_align_t __LZO_MMODEL var [ ((size) + (sizeof(lzo_align_t) - 1)) / sizeof(lzo_align_t) ]

static HEAP_ALLOC(wrkmem, LZO1X_1_MEM_COMPRESS);

struct bytearr{
public:
    char* bytes;
    int len;
    bool success;
    void len(){ len = strlen(bytes) }
};

class compressor{
private:
    bool inited = false;
public:
    compressor(){

    }
    bool init(){
        if (lzo_init() != LZO_E_OK) return false;
        inited = true;
        return true;
    }
    int compess(bytearr dat, bytearr* out){
        if(inited){
            out->len = dat.len / 5;
            return lzo1x_1_compress(dat.bytes, dat.len, out->bytes, out->len, wrkmem);
        } else {
            return bytes;
        }
    }
}

