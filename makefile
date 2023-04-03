app.out: Plant_Diary.o MakeText.o NodeManage.o
	gcc -o app.out Plant_Diary.o MakeText.o NodeManage.o

Plant_Diary.o: MakeText.h MakeText.h Plant_Diary.c
	gcc -c -o Plant_Diary.o Plant_Diary.c

MakeText.o: MakeText.h MakeText.c
	gcc -c -o MakeText.o MakeText.c

NodeManage.o: MakeText.h NodeManage.c
	gcc -c -o NodeManage.o NodeManage.c