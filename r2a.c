#include <stdio.h>
#include <stdarg.h>
#include "r2a.h"
int main(){
    inform(INF_INFO,"R2A - Raylib to Ascede Translator");

    inform(INF_INFO,"");
    inform(INF_INFO,"Loading tokens...");
    inittokens();
    initkills();

    inform(INF_INFO,"");
    if(!fileexists("raylib.h")){
        inform(INF_WARNING,"Please put this executable in the \"raylib/src\" directory.");
        inform(INF_INFO,"Press any key to exit.");
        getc(stdin);
        return -1;
    }

    inform(INF_INFO,"");
    inform(INF_INFO,"Deleting modules...");
    inform(INF_INFO,"Removing math module...");
    trydelete("raymath.h");
    inform(INF_INFO,"Removing 3D support...");
    if(!trydelete("rmodels.c"))trydelete("models.c");
    trydelete("external/cgltf.h");
    trydelete("external/msf_gif.h");
    trydelete("external/par_shapes.h");
    trydelete("external/tinyobj_loader.h");
    trydelete("external/vox_loader.h");
    inform(INF_INFO,"Removing camera module...");
    if(!trydelete("rcamera.h"))trydelete("camera.h");
    inform(INF_INFO,"Removing compression module...");
    trydelete("external/sinfl.h");
    trydelete("external/sdefl.h");

    inform(INF_INFO,"");
    inform(INF_INFO,"Processing files...");
    processfile("raylib.h");
    processfile("config.h");
    processfile("rgestures.h");
    processfile("rlgl.h");
    processfile("utils.h");
    processfile("rcore.c");
    processfile("rglfw.c");
    processfile("rshapes.c");
    processfile("rtext.c");
    processfile("rtextures.c");
    processfile("utils.c");

    renamefile("raylib.h","ascede.h");

    showtokensstats();
    showkillsstats();
    free(tokens);
    inform(INF_INFO,"Press any key to exit.");
    getc(stdin);
    return 0;
}
