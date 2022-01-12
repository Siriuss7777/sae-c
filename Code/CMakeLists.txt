cmake_minimum_required(VERSION 3.0)
project(SAE-C)

set(SRCS
    main.c 
    lib/menu.c
    lib/save.c
    lib/sort.c
    lib/edit.c
    lib/utils.c
    lib/filter.c
    lib/search.c
    lib/delete.c
    lib/addclient.c
    lib/loadclients.c
    lib/displayallclients.c
    lib/displayemptyclients.c
)
	
set(HEADERS
    lib/headers/menu.h
    lib/headers/save.h
    lib/headers/sort.h
    lib/headers/edit.h
    lib/headers/utils.h
    lib/headers/filter.h
    lib/headers/search.h
    lib/headers/delete.h
    lib/headers/addclient.h
    lib/headers/loadclients.h
    lib/headers/displayallclients.h
    lib/headers/displayemptyclients.h
)

add_executable(SAE-C ${SRCS} ${HEADERS})
