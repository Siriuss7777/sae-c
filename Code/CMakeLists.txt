cmake_minimum_required(VERSION 3.0)
project(SAE-C)

set(SRCS
    main.c 
    lib/utils.c
    lib/menu.c
    lib/loadclients.c
    lib/addclient.c
    lib/displayallclients.c
    lib/displayemptyclients.c
)
	
set(HEADERS
    lib/headers/utils.h
    lib/headers/menu.h
    lib/headers/loadclients.h
    lib/headers/addclient.h
    lib/headers/displayallclients.h
    lib/headers/displayemptyclients.h
)

add_executable(SAE-C ${SRCS} ${HEADERS})
