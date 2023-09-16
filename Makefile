CC=gcc
CLIBS=-lglew32 -lglfw3 -lopengl32 -lgdi32 -lm -lcglm
CFLAGS=-D GLEW_STATIC

main:
	${CC} src/main.c 						-o bin/main 				${CFLAGS} ${CLIBS}

examples:
	${CC} src/example/window_example.c 		-o bin/window_example 		${CFLAGS} ${CLIBS}
	${CC} src/example/clear_color_example.c -o bin/clear_color 			${CFLAGS} ${CLIBS}
	${CC} src/example/triangle_example.c 	-o bin/triangle_example 	${CFLAGS} ${CLIBS}
	${CC} src/example/shadering_example.c 	-o bin/shadering_example 	${CFLAGS} ${CLIBS}
	${CC} src/example/uniform_example.c 	-o bin/uniform_example 		${CFLAGS} ${CLIBS}
	${CC} src/example/texture_example.c 	-o bin/texture_example 		${CFLAGS} ${CLIBS}
	${CC} src/example/quad_example.c 		-o bin/quad_example 		${CFLAGS} ${CLIBS}
	${CC} src/example/keyboard_example.c 	-o bin/keyboard_example  	${CFLAGS} ${CLIBS}
	${CC} src/example/mouse_example.c 		-o bin/mouse_example  		${CFLAGS} ${CLIBS}