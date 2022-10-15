project(UAE4ALL_PSP)
cmake_minimum_required(VERSION 3.14)
SET(CMAKE_BUILD_TYPE Release)

    add_library(src OBJECT src/audio.c src/autoconf.c src/blitfunc.c src/blittable.c src/blitter.c src/cia.c
                       src/compiler.c src/custom.c src/disk.c src/drawing.c src/ersatz.c src/gfxutil.c src/gui.c src/keybuf.c src/md-support.c
                       src/memory.c src/missing.c src/od-joy.c src/savedisk.c src/sdlgfx.c src/sound.c src/writelog.c src/zfile.c)

    add_library(menu OBJECT src/menu/fade.c src/menu/menu.c src/menu/menu_load.c src/menu/menu_main.c)
    add_library(m68k OBJECT src/m68k/fame/famec.c src/m68k/fame/m68k_intrf.c)
    add_library(vkbd OBJECT src/vkbd/vkbd.c)

add_definitions(-DPSP)
add_definitions(-DPSP_USERMODE)

add_definitions(-DUSE_UNDERSCORE)
add_definitions(-DOPTIMIZED_FLAGS)
add_definitions(-D__inline__=__inline__)
add_definitions(-DSHM_SUPPORT_LINKS=0)

add_definitions(-DUSE_FAME_CORE_C)
add_definitions(-DUSE_FAME_CORE)
add_definitions(-DOPTIMIZED_FLAGS)

add_definitions(-DOS_WITHOUT_MEMORY_MANAGEMENT)
add_definitions(-DVKBD_ALWAYS)
add_definitions(-DUSE_SDL)

add_definitions(-DUNALIGNED_PROFITABLE)
add_definitions(-DMENU_MUSIC)

add_definitions(-DROM_PATH_PREFIX=\"./disks/\" -DDATA_PREFIX=\"./data/\" -DSAVE_PREFIX=\"./\")
add_definitions(-DDATA_PREFIX=\"./data/\")

include_directories(src src/include src/menu src/vkbd /src/m68k)
include_directories(${PSPDEV}/psp/include/SDL)


add_executable(UAE4ALL_PSP src/main.c)
target_link_libraries(UAE4ALL_PSP src m68k menu vkbd -lpspdebug -lSDL -lSDL_mixer -lz -lpsppower -lpspdisplay -lpspgu 
                                    -lpspaudio -lpspctrl -lGL -lpspvram -lpspirkeyb -lpspvfpu -lpsphprm -lpspge -lmikmod)

                                    create_pbp_file(
                                        TARGET UAE4ALL_PSP
                                        ICON_PATH ${CMAKE_SOURCE_DIR}/data/psp-eboot-icon.png
                                        BACKGROUND_PATH NULL
                                        PREVIEW_PATH NULL
                                        TITLE UAE4ALL_PSP
                                        )
