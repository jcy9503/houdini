
rem note
cl -MT -DWIN32 -EHsc -I"__DEVKIT_PATH__\include" -c __SRC_FILENAME__.cpp
link -nologo -DLL -out:"__DSO_TEMP_DEST_PATH__.dll" __SRC_FILENAME__.obj "__DEVKIT_PATH__\lib\ai.lib"
del __SRC_FILENAME__.obj
del __SRC_FILENAME__.lib
del __SRC_FILENAME__.exp
