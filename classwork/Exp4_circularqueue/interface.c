#include "interface.h"
#include "internalfun.h"
#include "cirqueue.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

void Welcome()
{
    system("color f0");
    puts("\t\t|--------------------------------------|");
    puts("\t\t|             Experiment 4             |");
    puts("\t\t|            Circular Queue            |");
    puts("\t\t|             Oct. 29,2017             |");
    puts("\t\t|        Developed by Gaoxiang Liu     |");
    puts("\t\t|--------------------------------------|");
    puts("\t\t|  This program simulates the process  |");
    puts("\t\t|  of treatment of patients.           |");
    puts("\t\t|          Only for Study              |");
    puts("\t\t|--------------------------------------|");
    puts("\t\t|  Press any key to continue.          |");
    puts("\t\t|--------------------------------------|");
    _getch();
    Display();
}

void Display()
{
    char choice;
    bool allow = true;      //if new patients can enter
    CirQueue q;
    InitQueue(&q);
    while(1)
    {
        system("cls");
        system("color 0a");
        puts  ("\t\t|--------------------------------------------|");
        puts  ("\t\t|       Patients' Treatment Simulator        |");
        puts  ("\t\t|--------------------------------------------|");
        printf("\t\t|      Current number of Patients: ");
        printf("%d         |\n",QueueLength(&q));
        puts  ("\t\t|--------------------------------------------|");
        puts  ("\t\t|     [1] New Patient comes                  |");
        puts  ("\t\t|     [2] Treat one patient                  |");
        puts  ("\t\t|     [3] View all the patients in line      |");
        puts  ("\t\t|     [4] Don't accept new patient           |");
        puts  ("\t\t|         (Treat all Patients in Line)       |");
        puts  ("\t\t|     [5] Off Work                           |");
        puts  ("\t\t|--------------------------------------------|");
        choice =_getch();
        switch (choice)
        {
        default:
            break;
        case '1':
            if(allow)
                WaitInLine_UI(&q);
            else
                noAccept();
            break;
        case '2':
            Treatment_UI(&q);
            break;
        case '3':
            View(&q);
            break;
        case '4':
            allow = false;
            TreatAllPatients(&q);
            break;
        case '5':
            DestroyQueue(&q);
            OffWork();
            break;
        }
    }

}

void WaitInLine_UI(CirQueue *q)
{
    Patient e;
    system("cls");
    system("color 0e");
    puts("===================New Patient===================");
    printf("input ID:");
    while(1)
    {
        scanf("%d",&e.id);
        while(getchar()!='\n')
            continue;
        if(Check(q, e))
            break;
        else
            puts("This patient has existed, please allocate another ID.");
    }

    if(WaitInLine(q,e))
        puts("Done!");
    else
        puts("Please wait till the doctor is available.");
    _getch();
}

void noAccept()
{
    system ("cls");
    system ("color 0e");
    puts ("This hospital doesn't accept new paitents.");
    puts ( "Please visit tomorrow.");
    _getch();
}

void Treatment_UI(CirQueue *q)
{
    Patient e;
    system("cls");
    system("color 0e");
    puts("===================Treat a Patient===================");
    if(Treatment(q,&e))
    {
        printf("The patient %d has finished.\nDone!", e.id);
    }
    else
    {
        puts("There is no patients.");
    }
    _getch();
}

void View(CirQueue *q)
{
    //operation: view all the patients in line(Traverse)
    system("cls");
    system("color 0e");
    puts("===================View All Patients===================");
    puts("Patients in line:");
    if(!QueueTraverse(q, PrintELem))
        puts("No patients.");
    _getch();
}

void TreatAllPatients(CirQueue *q)
{
    system("color 0e");
    Patient e;
    //operation: treat all the patients
    int len=QueueLength(q);
    for(int i=1;i<=len;++i)
    {
        system("cls");
        puts("===================Treat All Patients===================");
        puts("This hospital will no accept new patients today.");
        DeQueue(q,&e);
        for(int j=1;j<i;++j)
            puts("DONE");
        printf("Treating patient: %d ",e.id);
        for(int j=0;j<20;++j)
        {
            printf("#");
            Sleep(50);
        }
    }
    system("cls");
    puts("All patients have been treated.");
    _getch();
}

void OffWork()
{
    system ("color 0e");
    for(int i=5;i>0;i--)
    {
        system ("cls");
        puts ("Off work today.");
        puts ("Please visit the hospital tomorrow.");
        puts ("--------------------------------------");
        printf("\nSystem will exit in  %d  second(s).\n\t\t",i);
        for(int j=0;j<10;++j)
        {
            printf(".");
            Sleep(100);
        }
    }
    exit(0);
}
