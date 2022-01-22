cl -MT -DWIN32 -EHsc -I"_DEVKIT_PATH_\include" -c _SRC_FILENAME_
link -nologo -DLL -out:_OUT_PATH_ _RIX_PLUGIN_NAME_.obj "_DEVKIT_PATH_\lib\libprman.lib" "_DEVKIT_PATH_\lib\libpxrcore.lib"
del _OUT_OBJ_
del _OUT_LIB_
del _OUT_EXP_
